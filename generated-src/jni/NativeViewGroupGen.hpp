// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#pragma once

#include "djinni_support.hpp"
#include "view_group_gen.hpp"

namespace djinni_generated {

class NativeViewGroupGen final : ::djinni::JniInterface<::gearsbox::ViewGroupGen, NativeViewGroupGen> {
public:
    using CppType = std::shared_ptr<::gearsbox::ViewGroupGen>;
    using CppOptType = std::shared_ptr<::gearsbox::ViewGroupGen>;
    using JniType = jobject;

    using Boxed = NativeViewGroupGen;

    ~NativeViewGroupGen();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeViewGroupGen>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeViewGroupGen>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeViewGroupGen();
    friend ::djinni::JniClass<NativeViewGroupGen>;
    friend ::djinni::JniInterface<::gearsbox::ViewGroupGen, NativeViewGroupGen>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::gearsbox::ViewGroupGen
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        std::shared_ptr<::gearsbox::ViewGen> getView(const std::string & id) override;
        bool addView(const std::string & id, ::gearsbox::ViewType type) override;
        bool removeView(const std::string & id) override;
        void addConstraint(const ::gearsbox::ViewConstraint & constraint) override;

    private:
        friend ::djinni::JniInterface<::gearsbox::ViewGroupGen, ::djinni_generated::NativeViewGroupGen>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("dyno/fun/gearsbox/ViewGroupGen") };
    const jmethodID method_getView { ::djinni::jniGetMethodID(clazz.get(), "getView", "(Ljava/lang/String;)Ldyno/fun/gearsbox/ViewGen;") };
    const jmethodID method_addView { ::djinni::jniGetMethodID(clazz.get(), "addView", "(Ljava/lang/String;Ldyno/fun/gearsbox/ViewType;)Z") };
    const jmethodID method_removeView { ::djinni::jniGetMethodID(clazz.get(), "removeView", "(Ljava/lang/String;)Z") };
    const jmethodID method_addConstraint { ::djinni::jniGetMethodID(clazz.get(), "addConstraint", "(Ldyno/fun/gearsbox/ViewConstraint;)V") };
};

}  // namespace djinni_generated
