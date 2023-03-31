cmake_minimum_required(VERSION 3.19)

project(MINECRAFT_CLONE CXX)

add_library(Minecraft_Library "")

add_subdirectory(Minecraft_Clone)

set_target_properties(Minecraft_Library PROPERTIES LINKER_LANGUAGE CXX)
