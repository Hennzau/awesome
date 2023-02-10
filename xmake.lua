add_rules ("mode.debug", "mode.release")

set_languages ("c++23")

add_requires ("glfw")

target ("awesome")
    set_kind ("static")

    add_files ("sources/**.cpp", "sources/**.cppm")

    add_packages ("glfw", { public = true })

target ("awesome-test")
    set_kind ("binary")

    add_files ("test/**.cpp")

    add_deps ("awesome")
