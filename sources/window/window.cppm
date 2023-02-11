module;

#include <GLFW/glfw3.h>

export module awesome.window;

import awesome.std;
import awesome.window.monitor;

import awesome.logs.console;

export namespace awsm {
    enum cursor_mode {
        normal, hidden, disabled
    };

    struct video_settings {
        awsm::u32 width {};
        awsm::u32 height {};

        awsm::u32 x {};
        awsm::u32 y {};

        awsm::monitor     monitor;
        awsm::cursor_mode cursor_mode = cursor_mode::normal;

        bool resizable = false;
    };

    class window {
        public:
            window (awsm::string_view title,
                    const video_settings& settings);

            ~window ();

            auto swap_buffers () const -> void;

            auto update () -> void;

            auto should_close () -> bool;

        private:
            GLFWwindow* m_handle;
    };

    window::window (awsm::string_view title,
                    const video_settings& settings) {

        glfwWindowHint (GLFW_RESIZABLE,
                        settings.resizable ? GLFW_TRUE : GLFW_FALSE);

        m_handle = glfwCreateWindow (awsm::as<awsm::i32> (settings.width),
                                     awsm::as<awsm::i32> (settings.height),
                                     title.data (),
                                     nullptr,
                                     nullptr);

        // TO DO: manage multiple screens

        auto global_x = settings.x - awsm::as<awsm::u32> ((awsm::as<awsm::f32> (settings.width) / 2));
        auto global_y = settings.y - awsm::as<awsm::u32> ((awsm::as<awsm::f32> (settings.height) / 2));

        glfwSetWindowPos (m_handle,
                          awsm::as<awsm::i32> (global_x),
                          awsm::as<awsm::i32> (global_y));

        glfwSetInputMode (m_handle,
                          GLFW_CURSOR,
                          settings.cursor_mode == cursor_mode::normal ? GLFW_CURSOR_NORMAL : settings.cursor_mode ==
                                                                                             cursor_mode::hidden
                                                                                             ? GLFW_CURSOR_HIDDEN
                                                                                             : GLFW_CURSOR_DISABLED);

        glfwSetWindowUserPointer (m_handle,
                                  this);
    }

    window::~window () {
        glfwDestroyWindow (m_handle);
    }

    auto window::swap_buffers () const -> void {
        glfwSwapBuffers (m_handle);
    }

    auto window::update () -> void {

    }

    auto window::should_close () -> bool {
        return glfwWindowShouldClose (m_handle);
    }
}