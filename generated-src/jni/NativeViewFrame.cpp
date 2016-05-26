// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#include "NativeViewFrame.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

NativeViewFrame::NativeViewFrame() = default;

NativeViewFrame::~NativeViewFrame() = default;

auto NativeViewFrame::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeViewFrame>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::I32::fromCpp(jniEnv, c.x)),
                                                           ::djinni::get(::djinni::I32::fromCpp(jniEnv, c.y)),
                                                           ::djinni::get(::djinni::I32::fromCpp(jniEnv, c.w)),
                                                           ::djinni::get(::djinni::I32::fromCpp(jniEnv, c.h)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeViewFrame::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 5);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeViewFrame>::get();
    return {::djinni::I32::toCpp(jniEnv, jniEnv->GetIntField(j, data.field_mX)),
            ::djinni::I32::toCpp(jniEnv, jniEnv->GetIntField(j, data.field_mY)),
            ::djinni::I32::toCpp(jniEnv, jniEnv->GetIntField(j, data.field_mW)),
            ::djinni::I32::toCpp(jniEnv, jniEnv->GetIntField(j, data.field_mH))};
}

}  // namespace djinni_generated
