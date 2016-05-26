// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#pragma once

#include "djinni_support.hpp"
#include "view_frame.hpp"

namespace djinni_generated {

class NativeViewFrame final {
public:
    using CppType = ::gearsbox::ViewFrame;
    using JniType = jobject;

    using Boxed = NativeViewFrame;

    ~NativeViewFrame();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    NativeViewFrame();
    friend ::djinni::JniClass<NativeViewFrame>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("dyno/fun/gearsbox/ViewFrame") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(IIII)V") };
    const jfieldID field_mX { ::djinni::jniGetFieldID(clazz.get(), "mX", "I") };
    const jfieldID field_mY { ::djinni::jniGetFieldID(clazz.get(), "mY", "I") };
    const jfieldID field_mW { ::djinni::jniGetFieldID(clazz.get(), "mW", "I") };
    const jfieldID field_mH { ::djinni::jniGetFieldID(clazz.get(), "mH", "I") };
};

}  // namespace djinni_generated
