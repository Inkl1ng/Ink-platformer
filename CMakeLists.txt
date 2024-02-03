cmake_minimum_required(VERSION 3.20)
project(Ink-Platformer VERSION 0.1.0 LANGUAGES C CXX)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.x
)
FetchContent_MakeAvailable(SFML)
set(src_files
    src/Game.cpp
    src/main.cpp
    src/Player.cpp
    src/engine/Entity.cpp
    src/engine/Tile.cpp
)
set(include_files
    include/Constants.hpp
    include/Game.hpp
    include/Player.hpp
    include/engine/Entity.hpp
    include/engine/Tile.hpp
    include/system/ResourceHolder.hpp
    include/system/ResourceHolder.tpp
    include/system/ResourceIDs.hpp
)

add_executable(Ink-Platformer
    ${src_files}
    ${include_files})
target_include_directories(Ink-Platformer PRIVATE include)
target_link_libraries(Ink-Platformer PRIVATE sfml-graphics sfml-window sfml-audio sfml-system)
target_compile_features(Ink-Platformer PRIVATE cxx_std_17)