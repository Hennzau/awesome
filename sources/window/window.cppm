module;

#include <GLFW/glfw3.h>

export module awesome.window;

import awesome.std;

export namespace awsm {
    struct video_settings {
        awsm::u32 width;
        awsm::u32 height;
    };

    class window {
        public:
            window () = default;

            ~window () = default;

        private:
            GLFWwindow* m_glfw_window;
    };
}