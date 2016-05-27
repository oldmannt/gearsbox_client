// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#pragma once

#include "djinni_support.hpp"
#include "view_gen.hpp"

namespace djinni_generated {

class NativeViewGen final : ::djinni::JniInterface<::gearsbox::ViewGen, NativeViewGen> {
public:
    using CppType = std::shared_ptr<::gearsbox::ViewGen>;
    using CppOptType = std::shared_ptr<::gearsbox::ViewGen>;
    using JniType = jobject;

    using Boxed = NativeViewGen;

    ~NativeViewGen();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeViewGen>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeViewGen>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeViewGen();
    friend ::djinni::JniClass<NativeViewGen>;
    friend ::djinni::JniInterface<::gearsbox::ViewGen, NativeViewGen>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::gearsbox::ViewGen
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        std::string getId() override;
        void setFrame(const ::gearsbox::ViewFrame & frame) override;
        ::gearsbox::ViewFrame getFrame() override;
        void setBackgroundColor(float a, float r, float g, float b) override;
        void setVisiable(bool v) override;

    private:
        friend ::djinni::JniInterface<::gearsbox::ViewGen, ::djinni_generated::NativeViewGen>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("dyno/fun/gearsbox/ViewGen") };
    const jmethodID method_getId { ::djinni::jniGetMethodID(clazz.get(), "getId", "()Ljava/lang/String;") };
    const jmethodID method_setFrame { ::djinni::jniGetMethodID(clazz.get(), "setFrame", "(Ldyno/fun/gearsbox/ViewFrame;)V") };
    const jmethodID method_getFrame { ::djinni::jniGetMethodID(clazz.get(), "getFrame", "()Ldyno/fun/gearsbox/ViewFrame;") };
    const jmethodID method_setBackgroundColor { ::djinni::jniGetMethodID(clazz.get(), "setBackgroundColor", "(FFFF)V") };
    const jmethodID method_setVisiable { ::djinni::jniGetMethodID(clazz.get(), "setVisiable", "(Z)V") };
};

}  // namespace djinni_generated