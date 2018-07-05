// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#pragma once

#include "djinni_support.hpp"
#include "lego_platform.hpp"

namespace djinni_generated {

class NativeLegoPlatform final : ::djinni::JniInterface<::lego::LegoPlatform, NativeLegoPlatform> {
public:
    using CppType = std::shared_ptr<::lego::LegoPlatform>;
    using CppOptType = std::shared_ptr<::lego::LegoPlatform>;
    using JniType = jobject;

    using Boxed = NativeLegoPlatform;

    ~NativeLegoPlatform();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeLegoPlatform>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeLegoPlatform>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeLegoPlatform();
    friend ::djinni::JniClass<NativeLegoPlatform>;
    friend ::djinni::JniInterface<::lego::LegoPlatform, NativeLegoPlatform>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::lego::LegoPlatform
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        std::string get_storage_path() override;
        void data_updated(const ::lego::STemplate & data) override;
        void http_download_file(const std::string & file_id, const std::shared_ptr<::lego::NetworkCallback> & callback) override;
        void http_upload_file(const std::string & path, const std::shared_ptr<::lego::NetworkCallback> & callback) override;
        void http_get_data(const std::shared_ptr<::lego::NetworkCallback> & callback) override;
        void http_send_data(const ::lego::STemplate & data, const std::shared_ptr<::lego::NetworkCallback> & callback) override;
        void grpc_get_data(const std::shared_ptr<::lego::NetworkCallback> & callback) override;
        void grpc_send_data(const ::lego::STemplate & data, const std::shared_ptr<::lego::NetworkCallback> & callback) override;

    private:
        friend ::djinni::JniInterface<::lego::LegoPlatform, ::djinni_generated::NativeLegoPlatform>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/mycompany/lego/LegoPlatform") };
    const jmethodID method_getStoragePath { ::djinni::jniGetMethodID(clazz.get(), "getStoragePath", "()Ljava/lang/String;") };
    const jmethodID method_dataUpdated { ::djinni::jniGetMethodID(clazz.get(), "dataUpdated", "(Lcom/mycompany/lego/STemplate;)V") };
    const jmethodID method_httpDownloadFile { ::djinni::jniGetMethodID(clazz.get(), "httpDownloadFile", "(Ljava/lang/String;Lcom/mycompany/lego/NetworkCallback;)V") };
    const jmethodID method_httpUploadFile { ::djinni::jniGetMethodID(clazz.get(), "httpUploadFile", "(Ljava/lang/String;Lcom/mycompany/lego/NetworkCallback;)V") };
    const jmethodID method_httpGetData { ::djinni::jniGetMethodID(clazz.get(), "httpGetData", "(Lcom/mycompany/lego/NetworkCallback;)V") };
    const jmethodID method_httpSendData { ::djinni::jniGetMethodID(clazz.get(), "httpSendData", "(Lcom/mycompany/lego/STemplate;Lcom/mycompany/lego/NetworkCallback;)V") };
    const jmethodID method_grpcGetData { ::djinni::jniGetMethodID(clazz.get(), "grpcGetData", "(Lcom/mycompany/lego/NetworkCallback;)V") };
    const jmethodID method_grpcSendData { ::djinni::jniGetMethodID(clazz.get(), "grpcSendData", "(Lcom/mycompany/lego/STemplate;Lcom/mycompany/lego/NetworkCallback;)V") };
};

}  // namespace djinni_generated
