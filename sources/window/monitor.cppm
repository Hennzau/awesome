module;

#include <GLFW/glfw3.h>

export module awesome.window.monitor;

import <iostream>;
import awesome.std;

export namespace awsm {
    struct monitor {
        GLFWmonitor* handle;

        awsm::u32 width;
        awsm::u32 height;
        awsm::u32 refresh_rate;

        awsm::i32 x {};
        awsm::i32 y {};

        awsm::u32 work_width;
        awsm::u32 work_height;

        awsm::f32 x_scale {};
        awsm::f32 y_scale {};

        awsm::string name;

        explicit monitor (GLFWmonitor* handle)
                : handle { handle } {

            auto mode = glfwGetVideoMode (handle);

            width        = mode->width;
            height       = mode->height;
            refresh_rate = mode->refreshRate;

            glfwGetMonitorPos (handle,
                               &x,
                               &y);

            auto w_width  = awsm::i32 { 0 };
            auto w_height = awsm::i32 { 0 };

            glfwGetMonitorWorkarea (handle,
                                    nullptr,
                                    nullptr,
                                    &w_width,
                                    &w_height);

            work_width  = w_width;
            work_height = w_height;

            glfwGetMonitorContentScale (handle,
                                        &x_scale,
                                        &y_scale);

            name = glfwGetMonitorName (handle);
        }
    };

    auto primary_monitor () -> monitor {
        return monitor { glfwGetPrimaryMonitor () };
    }

    auto monitors () -> awsm::vector<monitor> {
        auto monitors = awsm::vector<monitor> {};

        auto count   = awsm::i32 { 0 };
        auto handles = glfwGetMonitors (&count);

        for (auto i = 0; i < count; ++i) {
            monitors.emplace_back (handles[i]);
        }

        return monitors;
    }
}

export template<>
struct std::formatter<awsm::monitor> {
    constexpr auto parse (std::format_parse_context& ctx) {
        return ctx.begin ();
    }

    static auto format (const awsm::monitor& obj,
                        std::format_context& ctx) {
        return std::format_to (ctx.out (),
                               "Monitor [{}] : {}x{} @{}",
                               obj.name,
                               obj.width,
                               obj.height,
                               obj.refresh_rate);
    }
};