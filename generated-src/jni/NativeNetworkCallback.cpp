// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#include "NativeNetworkCallback.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeNetworkCallback::NativeNetworkCallback() : ::djinni::JniInterface<::lego::NetworkCallback, NativeNetworkCallback>("com/mycompany/lego/NetworkCallback$CppProxy") {}

NativeNetworkCallback::~NativeNetworkCallback() = default;


CJNIEXPORT void JNICALL Java_com_mycompany_lego_NetworkCallback_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::lego::NetworkCallback>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_mycompany_lego_NetworkCallback_00024CppProxy_native_1onHttpDownloadFileSuccess(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_path)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::lego::NetworkCallback>(nativeRef);
        ref->on_http_download_file_success(::djinni::String::toCpp(jniEnv, j_path));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_mycompany_lego_NetworkCallback_00024CppProxy_native_1onHttpUploadFileSuccess(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::lego::NetworkCallback>(nativeRef);
        ref->on_http_upload_file_success();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
