cmake_minimum_required(VERSION 3.4.1)

file(GLOB legoclient_sources
    ../../../deps/djinni/support-lib/jni/*.cpp
    ../../../generated-src/jni/*.cpp
    ../../../src/cpp/*.cpp
    ../../../core/*.cpp

)

add_library(legoland SHARED ${legoclient_sources})


# include directories for header files
include_directories(
    ../../../deps/djinni/support-lib/
    ../../../deps/djinni/support-lib/jni/
    ../../../generated-src/cpp/
    ../../../generated-src/jni/
    ../../../src/cpp/
    ../../../core/
    ../../../deps/flatbuffers/include/
    ../../../
)

target_link_libraries(legoland)