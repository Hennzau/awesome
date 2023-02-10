export module awesome.std;

import <cstdint>;
import <memory>;
import <vector>;
import <span>;
import <array>;
import <unordered_map>;
import <queue>;
import <string_view>;
import <string>;
import <format>;

export namespace awsm {
    using u8 = std::uint8_t;
    using u16 = std::uint16_t;
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;

    using i8 = std::int8_t;
    using i16 = std::int16_t;
    using i32 = std::int32_t;
    using i64 = std::int64_t;

    using f32 = float;
    using f64 = double;

    template<typename T,
             typename O>
    constexpr T as (const O& v) noexcept {
        return static_cast<T> (v);
    }

    template<typename T,
             typename O>
    constexpr T reinterpret (const O& v) noexcept {
        return reinterpret_cast<T> (v);
    }

    template<typename T> using owner = std::unique_ptr<T>;

    template<typename T> using shared = std::shared_ptr<T>;

    template<typename T> using raw = T*;

    template<typename T,
             typename... Args>
    constexpr owner<T> make_owner (Args&& ... args) noexcept {
        return std::make_unique<T> (std::forward<Args> (args)...);
    }

    template<typename T>
    constexpr raw<T> raw_cast (owner<T>& v) noexcept {
        return v.get ();
    }

    template<typename T>
    constexpr raw<T> raw_cast (const owner<T>& v) noexcept {
        return v.get ();
    }

    template<typename T> using vector = std::vector<T>;

    template<typename T> using span = std::span<T>;

    template<typename T, u32 Size> using array = std::array<T,
                                                            Size>;

    template<typename Key,
             typename Value> using map = std::unordered_map<Key,
                                                            Value>;

    template<typename T> using queue = std::queue<T>;

    using string = std::string;
    using string_view = std::string_view;

    template<typename... Args> using format_string = std::format_string<Args...>;
}