// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#pragma once

#include "djinni_support.hpp"
#include "ui_observer.hpp"

namespace djinni_generated {

class NativeUiObserver final : ::djinni::JniInterface<::lego::UiObserver, NativeUiObserver> {
public:
    using CppType = std::shared_ptr<::lego::UiObserver>;
    using CppOptType = std::shared_ptr<::lego::UiObserver>;
    using JniType = jobject;

    using Boxed = NativeUiObserver;

    ~NativeUiObserver();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeUiObserver>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeUiObserver>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeUiObserver();
    friend ::djinni::JniClass<NativeUiObserver>;
    friend ::djinni::JniInterface<::lego::UiObserver, NativeUiObserver>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::lego::UiObserver
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void title_updated(const std::string & title) override;
        void people_updated(const ::lego::People & people) override;
        void time_string_updated(const std::string & time_string) override;

    private:
        friend ::djinni::JniInterface<::lego::UiObserver, ::djinni_generated::NativeUiObserver>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/mycompany/lego/UiObserver") };
    const jmethodID method_titleUpdated { ::djinni::jniGetMethodID(clazz.get(), "titleUpdated", "(Ljava/lang/String;)V") };
    const jmethodID method_peopleUpdated { ::djinni::jniGetMethodID(clazz.get(), "peopleUpdated", "(Lcom/mycompany/lego/People;)V") };
    const jmethodID method_timeStringUpdated { ::djinni::jniGetMethodID(clazz.get(), "timeStringUpdated", "(Ljava/lang/String;)V") };
};

}  // namespace djinni_generated
