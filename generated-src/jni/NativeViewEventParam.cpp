// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#include "NativeViewEventParam.hpp"  // my header
#include "Marshal.hpp"
#include "NativeViewEvent.hpp"

namespace djinni_generated {

NativeViewEventParam::NativeViewEventParam() = default;

NativeViewEventParam::~NativeViewEventParam() = default;

auto NativeViewEventParam::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<NativeViewEventParam>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::F32::fromCpp(jniEnv, c.x)),
                                                           ::djinni::get(::djinni::F32::fromCpp(jniEnv, c.y)),
                                                           ::djinni::get(::djinni_generated::NativeViewEvent::fromCpp(jniEnv, c.type)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.text)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto NativeViewEventParam::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 5);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<NativeViewEventParam>::get();
    return {::djinni::F32::toCpp(jniEnv, jniEnv->GetFloatField(j, data.field_mX)),
            ::djinni::F32::toCpp(jniEnv, jniEnv->GetFloatField(j, data.field_mY)),
            ::djinni_generated::NativeViewEvent::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mType)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mText))};
}

}  // namespace djinni_generated
