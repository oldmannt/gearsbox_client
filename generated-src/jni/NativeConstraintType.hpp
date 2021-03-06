// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#pragma once

#include "constraint_type.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class NativeConstraintType final : ::djinni::JniEnum {
public:
    using CppType = ::gearsbox::ConstraintType;
    using JniType = jobject;

    using Boxed = NativeConstraintType;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<NativeConstraintType>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<NativeConstraintType>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    NativeConstraintType() : JniEnum("dyno/fun/gearsbox/ConstraintType") {}
    friend ::djinni::JniClass<NativeConstraintType>;
};

}  // namespace djinni_generated
