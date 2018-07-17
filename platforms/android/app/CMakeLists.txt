cmake_minimum_required(VERSION 3.4.1)

file(GLOB legoclient_sources
    ../../../deps/djinni/support-lib/jni/*.cpp
    ../../../generated-src/jni/*.cpp
    ../../../src/cpp/*.cpp
    ../../../core/*.cpp
    ../../../deps/generated-grpc/*.cc
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
    ../../../deps/generated-grpc/
    ../../../deps/protobuf/include/
    ../../../deps/grpc/include/
)

target_link_libraries(legoland /Users/vinovarkey/Documents/lego-clients/deps/libs/libboringssl.a
    /Users/vinovarkey/Documents/lego-clients/deps/libs/libgrpc-c++.a
    /Users/vinovarkey/Documents/lego-clients/deps/libs/libgrpc-core.a
    /Users/vinovarkey/Documents/lego-clients/deps/libs/libnanopb.a
    /Users/vinovarkey/Documents/lego-clients/deps/libs/libprotobuf-c++.a
    )