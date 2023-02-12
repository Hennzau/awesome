export module awesome.window.event;

import awesome.std;
import <variant>;

import awesome.window.keys;
import awesome.window.buttons;

export namespace awsm {
    enum class event_type : awsm::u8 {
        empty,
        closed,
        resized,
        minimized,
        maximized,
        restored,
        scaled,
        key_pressed,
        key_released,
        mouse_button_pressed,
        mouse_button_released,
        mouse_entered,
        mouse_exited,
        mouse_moved,
        mouse_scrolled
    };

    struct empty_event {
        static constexpr auto type = event_type::empty;
    };

    struct closed_event {
        static constexpr auto type = event_type::closed;
    };

    struct resized_event {
        static constexpr auto type = event_type::resized;

        awsm::u32 width;
        awsm::u32 height;
    };

    struct minimized_event {
        static constexpr auto type = event_type::minimized;
    };

    struct maximized_event {
        static constexpr auto type = event_type::maximized;
    };

    struct restored_event {
        static constexpr auto type = event_type::restored;
    };

    struct scaled_event {
        static constexpr auto type = event_type::scaled;

        awsm::f32 scale_x;
        awsm::f32 scale_y;
    };

    struct key_pressed_event {
        static constexpr auto type = event_type::key_pressed;

        awsm::key key;
        bool      repeated;
        char      character;
    };

    struct key_released_event {
        static constexpr auto type = event_type::key_released;

        awsm::key key;
        char      character;
    };

    struct mouse_button_pressed_event {
        static constexpr auto type = event_type::mouse_button_pressed;

        awsm::button button;
        bool         repeated;

        awsm::u32 x;
        awsm::u32 y;
    };

    struct mouse_button_released_event {
        static constexpr auto type = event_type::mouse_button_released;

        awsm::button button;

        awsm::u32 x;
        awsm::u32 y;
    };

    struct mouse_exited_event {
        static constexpr auto type = event_type::mouse_exited;
    };

    struct mouse_entered_event {
        static constexpr auto type = event_type::mouse_entered;
    };

    struct mouse_moved_event {
        static constexpr auto type = event_type::mouse_moved;

        awsm::u32 x;
        awsm::u32 y;
    };

    struct mouse_scrolled_event {
        static constexpr auto type = event_type::mouse_scrolled;
    };

    using event_data = std::variant<empty_event,
                                    closed_event,
                                    resized_event,
                                    minimized_event,
                                    maximized_event,
                                    restored_event,
                                    key_pressed_event,
                                    key_released_event,
                                    mouse_button_pressed_event,
                                    mouse_button_released_event,
                                    mouse_entered_event,
                                    mouse_exited_event,
                                    mouse_moved_event,
                                    mouse_scrolled_event>;


    struct event {
        event_type type = event_type::empty;
        event_data data = empty_event {};
    };
}