cmake_minimum_required(VERSION 3.28)
project(ShootEmUp LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include_directories("include")

add_executable(main
 "src/main.cpp"
 "include/Game.hpp"
 "src/Game.cpp"
 "include/ResourceHolder.hpp"
 "include/ResourceHolder.inl"
 "include/Entity.hpp"
 "src/Entity.cpp"
 "include/Aircraft.hpp"
 "src/Aircraft.cpp"
 "include/SceneNode.hpp"
 "src/SceneNode.cpp"
 "include/ResourceIdentifiers.hpp"
 "include/World.hpp"
 "src/World.cpp"
 "include/SpriteNode.hpp"
 "src/SpriteNode.cpp"
 "include/Command.hpp"
 "src/Command.cpp")

add_custom_target(copy_media
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_LIST_DIR}/copy_media.cmake
)
add_dependencies(main copy_media)

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)