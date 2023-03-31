cmake_minimum_required(VERSION 3.19)

project(MINECRAFT_CLONE CXX)

add_library(Minecraft_Library "")
#add_executable(Minecraft_Library Minecraft_Clone/src/main.cpp "")

add_subdirectory(Minecraft_Clone)

set_property(TARGET Minecraft_Library PROPERTY CXX_STANDARD 17)

target_include_directories(Minecraft_Library PRIVATE Minecraft_Clone/src)
target_include_directories(Minecraft_Library PRIVATE Minecraft_Clone/src/vendor/)
target_include_directories(Minecraft_Library PRIVATE Dependencies/SFML-2.5.1/include)
target_include_directories(Minecraft_Library PRIVATE Dependencies/GLEW/include)
target_include_directories(Minecraft_Library PRIVATE Dependencies/libnoise/include)

include_directories(Minecraft_Clone/src)
include_directories(Minecraft_Clone/src/vendor)

set_target_properties(Minecraft_Library PROPERTIES LINKER_LANGUAGE CXX)
