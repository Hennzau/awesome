export module awesome.core.application;

import awesome.std;

export namespace awsm {
    class application {
        public:
            application () = default;

            virtual ~application () = default;

            virtual auto update (awsm::f32 delta_time) -> void = 0;
    };
}