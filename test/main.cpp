import awesome.std;

import awesome.core.application;

import awesome.logs.console;
import awesome.core.loader;

import awesome.window.application;
import awesome.window.monitor;

int main () {
    auto logger = awsm::logs::console { "MAIN" };

    logger.write ("Loader created!");
    auto loader = awsm::loader < awsm::window_app > { "Awesome" };

    loader.run ();

    auto windowing = loader.retrieve<awsm::window_app> ();

    auto monitors = awsm::monitors();

    for (auto& monitor : monitors) {
        logger.write ("{}", monitor);
    }

    return 0;
}