cmake_minimum_required(VERSION 3.20)
project(Ink-Platformer VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.x
)
FetchContent_MakeAvailable(SFML)

set(include_dirs
    include
    include/system)

set(src_files
    src/main.cpp
    src/Game.cpp
)
set(include_files
    include/Game.hpp
    include/Constants.hpp
    include/system/ResourceHolder.hpp
    include/system/ResourceHolder.tpp
    include/system/ResourceIDs.hpp
)

add_executable(Ink-Platformer
    ${src_files}
    ${include_files})
target_include_directories(Ink-Platformer PRIVATE ${include_dirs})
target_link_libraries(Ink-Platformer PRIVATE sfml-graphics sfml-window sfml-audio sfml-system)
target_compile_features(Ink-Platformer PRIVATE cxx_std_17)