cmake_minimum_required(VERSION 3.19)

project(MINECRAFT_CLONE CXX)

# TODO support x86/x64 libs
# TODO support debug/release libs

# TODO change to find_library later
link_directories(Dependencies/SFML-2.5.1/lib)
link_directories(Dependencies/libnoise/lib)

#add_library(Minecraft_Library "")
add_executable(Minecraft_Library Minecraft_Clone/src/main.cpp "")

add_subdirectory(Minecraft_Clone)

set(CMAKE_TOOLCHAIN_FILE "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/vcpkg/scripts/buildsystems/vcpkg.cmake")

set_property(TARGET Minecraft_Library PROPERTY CXX_STANDARD 17)

target_include_directories(Minecraft_Library PRIVATE Minecraft_Clone/src)
target_include_directories(Minecraft_Library PRIVATE Minecraft_Clone/src/vendor/)
target_include_directories(Minecraft_Library PRIVATE Dependencies/SFML-2.5.1/include)
target_include_directories(Minecraft_Library PRIVATE Dependencies/libnoise/include)

include_directories(Minecraft_Clone/src)
include_directories(Minecraft_Clone/src/vendor)

#add_compile_definitions(SFML_STATIC) #Release
add_compile_definitions(GLEW_STATIC)
# maybe remove this
add_compile_definitions(_MBCS)

# TODO remove unnecessary dependencies if exists
target_link_libraries(Minecraft_Library PRIVATE libnoise)
target_link_libraries(Minecraft_Library PRIVATE glew32s)
target_link_libraries(Minecraft_Library PRIVATE flac freetype ogg openal32)
target_link_libraries(Minecraft_Library PRIVATE sfml-audio-d sfml-graphics-d sfml-system-d sfml-window-d) #Debug
#target_link_libraries(Minecraft_Library PRIVATE sfml-audio-s sfml-graphics-s sfml-system-s sfml-window-s) #Release
target_link_libraries(Minecraft_Library PRIVATE vorbisenc vorbisfile vorbis)
target_link_libraries(Minecraft_Library PRIVATE opengl32 gdi32 winmm)
target_link_libraries(Minecraft_Library PRIVATE User32 Shell32) #Debug

set_target_properties(Minecraft_Library PROPERTIES LINKER_LANGUAGE CXX)
