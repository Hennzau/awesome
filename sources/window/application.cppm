module;

#include <GLFW/glfw3.h>

export module awesome.window.application;

import awesome.std;
import awesome.core.application;
import awesome.window.monitor;
import awesome.window;

import awesome.logs.console;

export namespace awsm {
    class window_app : public awsm::application {
        public:
            window_app ();

            ~window_app () override;

            auto create (awsm::string_view title,
                         const awsm::video_settings& settings) -> awsm::raw<awsm::window>;

            auto destroy (awsm::raw<awsm::window> window) -> void;

            auto update (awsm::f32 delta_time) -> void override;

            [[nodiscard]] auto& windows () const { return m_windows; }

        private:
            awsm::vector<awsm::owner<awsm::window>> m_windows;
            awsm::queue<awsm::raw<awsm::window>>    m_destroy_queue;
    };

    window_app::window_app () {
        auto logger = awsm::logs::console { "WindowApplication" };

        if (not glfwInit ()) {
            logger.write ("GLFW failed to initialize!");
        } else {
            logger.write ("GLFW has been successfully initialized!");
        }
    }

    window_app::~window_app () {
        glfwWaitEvents ();
    }

    auto window_app::update (awsm::f32 delta_time) -> void {
        glfwPollEvents ();

        for (auto& window: m_windows) {
            window->update ();
            window->swap_buffers ();

            if (window->should_close ()) {
                m_destroy_queue.push (window.get ());
            }
        }

        while (not m_destroy_queue.empty ()) {
            auto window = m_destroy_queue.front ();
            m_destroy_queue.pop ();

            destroy (window);
        }
    }

    auto window_app::create (awsm::string_view title,
                             const awsm::video_settings& settings) -> awsm::raw<awsm::window> {
        m_windows.emplace_back (awsm::make_owner<awsm::window> (title,
                                                                settings));

        return m_windows.back ().get ();
    }

    auto window_app::destroy (awsm::raw<awsm::window> window) -> void {
        auto it = std::find_if (m_windows.begin (),
                                m_windows.end (),
                                [window] (auto& ptr) {
                                    return ptr.get () == window;
                                });
        if (it != m_windows.end ()) {
            m_windows.erase (it);
        }
    }
}