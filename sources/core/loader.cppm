export module awesome.core.loader;

import <chrono>;
import awesome.std;
import awesome.core.application;

import awesome.logs.console;

import awesome.window.application;

export namespace awsm {
    template<typename... applications>
    class loader {
        public:
            explicit loader (awsm::string name);

            ~loader () = default;

            auto run () -> void;

            template<typename T>
            auto retrieve () -> T*;

            template<typename T>
            auto retrieve () const -> const T*;

            auto stop () -> void;

            auto running () -> bool;

        private:

            awsm::vector<awsm::owner<awsm::application>> m_applications;
            awsm::owner<awsm::logs::console>             m_logger;
            awsm::string                                 m_name;

            bool m_running;
    };

    template<typename... applications>
    auto loader<applications...>::running () -> bool {
        return m_running;
    }

    template<typename... applications>
    template<typename T>
    auto loader<applications...>::retrieve () -> T* {
        auto it = std::find_if (m_applications.begin (),
                                m_applications.end (),
                                [] (const awsm::owner<awsm::application>& app) {
                                    return typeid (T) == typeid (*app.get ());
                                });

        if (it != m_applications.end ()) {
            auto& ptr = *it;

            return awsm::reinterpret<T*> (ptr.get ());
        }

        m_logger->write ("Application {} not found!",
                         typeid (T).name ());

        return nullptr;
    }

    template<typename... applications>
    template<typename T>
    auto loader<applications...>::retrieve () const -> const T* {
        auto it = std::find_if (m_applications.begin (),
                                m_applications.end (),
                                [] (const awsm::owner<awsm::application>& app) {
                                    return typeid (T) == typeid (*app.get ());
                                });

        if (it != m_applications.end ()) {
            auto& ptr = *it;

            return awsm::reinterpret<T*> (ptr.get ());
        }

        m_logger->write ("Application {} not found!",
                         typeid (T).name ());

        return nullptr;
    }

    template<typename... applications>
    loader<applications...>::loader (awsm::string name) {
        m_name = std::move (name);

        m_logger = awsm::make_owner<awsm::logs::console> (m_name);

        m_applications.reserve (sizeof... (applications));

        (m_applications.emplace_back (awsm::make_owner<applications> ()), ...);

        m_logger->write ("Applications have been installed!");
    }

    template<typename... applications>
    auto loader<applications...>::run () -> void {
        m_running = true;
        m_logger->write ("Loader is now running!");

        auto last_time = std::chrono::high_resolution_clock::now ();

        while (m_running) {
            const auto time       = std::chrono::high_resolution_clock::now ();
            const auto delta_time = time - last_time;
            last_time = time;

            for (auto& application: m_applications) {
                application->update (awsm::as<awsm::f32> (delta_time.count ()) / 1000000000.0f);
            }
        }
    }

    template<typename... applications>
    auto loader<applications...>::stop () -> void {
        m_running = false;
    }
}