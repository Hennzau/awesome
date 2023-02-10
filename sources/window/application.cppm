module;

#include <GLFW/glfw3.h>

export module awesome.window.application;

import awesome.std;
import awesome.core.application;

import awesome.logs.console;

export namespace awsm {
    class window_app : public awsm::application {
        public:
            window_app ();

            ~window_app () override;

            auto update (awsm::f32 delta_time) -> void override;

        private:

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
        
    }
}