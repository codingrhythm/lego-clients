cmake_minimum_required(VERSION 3.4.1)

file(GLOB legoclient_sources
    ../../../deps/djinni/support-lib/jni/*.cpp
    ../../../generated-src/jni/*.cpp
    ../../../src/cpp/*.cpp
    ../../../core/*.cpp
    ../../../deps/generated-grpc/*.cc
    ../../../deps/flatbuffers/src/util.cpp
)
add_library(legoland SHARED ${legoclient_sources})
# include directories for header files
target_include_directories(legoland PRIVATE
    ../../../deps/djinni/support-lib/
    ../../../deps/djinni/support-lib/jni/
    ../../../generated-src/cpp/
    ../../../generated-src/jni/
    ../../../src/cpp/
    ../../../core/
    ../../../deps/flatbuffers/include/
    ../../../
    ../../../deps/generated-grpc/
    ../../../deps/protobuf/include3.5.x/
    ../../../deps/grpc/include/
    ../../../deps/flatbuffers/grpc/
)


find_library( # Sets the name of the path variable.
          log-lib
          # Specifies the name of the NDK library that
          # you want CMake to locate.
          log )

set(LIBS_PATH /Users/yuzhou/Projects/lego-clients/deps/android_libs)
target_link_libraries(legoland
    ${LIBS_PATH}/arm64-v8a/libboringssl.a
    ${LIBS_PATH}/arm64-v8a/libgrpc++.a
    ${LIBS_PATH}/arm64-v8a/libgrpc.a
    ${LIBS_PATH}/arm64-v8a/libgpr.a
    ${LIBS_PATH}/arm64-v8a/libaddress_sorting.a
    ${LIBS_PATH}/arm64-v8a/libprotobufd.a
    ${LIBS_PATH}/arm64-v8a/libssl.a
    ${LIBS_PATH}/arm64-v8a/libcrypto.a
    ${LIBS_PATH}/arm64-v8a/libcares.a
    ${LIBS_PATH}/arm64-v8a/libz.a
    android
    ${log-lib}
)