export module awesome.logs.console;

import <iostream>;

import awesome.std;

export namespace awsm::logs {
    class console {
        public:
            explicit console (awsm::string name);

            ~console () = default;

            template<typename... Args>
            auto write (awsm::format_string<Args...> str,
                        Args&& ... args) {
                std::cout << "[" << m_name << "] : " << std::format (str,
                                                                     std::forward<Args> (args)...) << std::endl;
            }

        private:
            awsm::string m_name;
    };

    console::console (awsm::string name) {
        m_name = std::move (name);
    }
}