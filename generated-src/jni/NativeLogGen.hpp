// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from gearsbox.djinni

#pragma once

#include "djinni_support.hpp"
#include "log_gen.hpp"

namespace djinni_generated {

class NativeLogGen final : ::djinni::JniInterface<::gearsbox::LogGen, NativeLogGen> {
public:
    using CppType = std::shared_ptr<::gearsbox::LogGen>;
    using CppOptType = std::shared_ptr<::gearsbox::LogGen>;
    using JniType = jobject;

    using Boxed = NativeLogGen;

    ~NativeLogGen();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<NativeLogGen>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<NativeLogGen>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    NativeLogGen();
    friend ::djinni::JniClass<NativeLogGen>;
    friend ::djinni::JniInterface<::gearsbox::LogGen, NativeLogGen>;

};

}  // namespace djinni_generated
