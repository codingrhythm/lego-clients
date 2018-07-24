// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#include "NativeUiPlatformSupport.hpp"  // my header
#include "Marshal.hpp"
#include "NativeUiManager.hpp"

namespace djinni_generated {

NativeUiPlatformSupport::NativeUiPlatformSupport() : ::djinni::JniInterface<::lego::UiPlatformSupport, NativeUiPlatformSupport>() {}

NativeUiPlatformSupport::~NativeUiPlatformSupport() = default;

NativeUiPlatformSupport::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

NativeUiPlatformSupport::JavaProxy::~JavaProxy() = default;

std::string NativeUiPlatformSupport::JavaProxy::get_time_string() {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeUiPlatformSupport>::get();
    auto jret = (jstring)jniEnv->CallObjectMethod(Handle::get().get(), data.method_getTimeString);
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::String::toCpp(jniEnv, jret);
}
std::string NativeUiPlatformSupport::JavaProxy::get_storage_path() {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeUiPlatformSupport>::get();
    auto jret = (jstring)jniEnv->CallObjectMethod(Handle::get().get(), data.method_getStoragePath);
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::String::toCpp(jniEnv, jret);
}
void NativeUiPlatformSupport::JavaProxy::get_time_string_async(const std::shared_ptr<::lego::UiManager> & c_manager) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NativeUiPlatformSupport>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_getTimeStringAsync,
                           ::djinni::get(::djinni_generated::NativeUiManager::fromCpp(jniEnv, c_manager)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
