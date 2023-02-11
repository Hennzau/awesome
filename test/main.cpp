import awesome.std;

import <chrono>;
import <thread>;

import awesome.core.application;

import awesome.logs.console;
import awesome.core.loader;

import awesome.window.application;
import awesome.window.monitor;
import awesome.window;

int main () {
    auto logger = awsm::logs::console { "MAIN" };

    logger.write ("Loader created!");
    auto loader = awsm::loader < awsm::window_app > { "Awesome" };

    auto windowing = loader.retrieve<awsm::window_app> ();

    const auto video_settings = awsm::video_settings { .width = awsm::u32 { 1080 }, .height = awsm::u32 { 720 }, .x = awsm::u32 {
            1920 / 2 - 120 }, .y = awsm::u32 {
            1080 / 2 }, .monitor = awsm::primary_monitor (), .cursor_mode = awsm::cursor_mode::normal };

    auto window = windowing->create ("Awesome Window",
                                     video_settings);

    auto new_settings = video_settings;
    new_settings.width  = awsm::u32 { 300 };
    new_settings.height = awsm::u32 { 720 };
    new_settings.x      = awsm::u32 { 1920/2 + 1080 / 2 + 300 / 2 - 120};

    auto second = windowing->create ("Toolbox",
                                     new_settings);

    auto thread = std::thread ([&loader,
                                windowing] () {
        while (loader.running ()) {
            if (windowing->windows ().empty()) {
                loader.stop ();
            }
        }
    });

    loader.run ();

    thread.join ();

    return 0;
}