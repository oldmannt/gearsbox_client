// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#import "GBViewConstraint+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto ViewConstraint::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::Enum<::gearsbox::ConstraintType, GBConstraintType>::toCpp(obj.type),
            ::djinni::Enum<::gearsbox::ConstraintType, GBConstraintType>::toCpp(obj.typeTo),
            ::djinni::String::toCpp(obj.viewFrom),
            ::djinni::String::toCpp(obj.viewTo),
            ::djinni::F32::toCpp(obj.multiplier),
            ::djinni::F32::toCpp(obj.offset)};
}

auto ViewConstraint::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[GBViewConstraint alloc] initWithType:(::djinni::Enum<::gearsbox::ConstraintType, GBConstraintType>::fromCpp(cpp.type))
                                           typeTo:(::djinni::Enum<::gearsbox::ConstraintType, GBConstraintType>::fromCpp(cpp.type_to))
                                         viewFrom:(::djinni::String::fromCpp(cpp.view_from))
                                           viewTo:(::djinni::String::fromCpp(cpp.view_to))
                                       multiplier:(::djinni::F32::fromCpp(cpp.multiplier))
                                           offset:(::djinni::F32::fromCpp(cpp.offset))];
}

}  // namespace djinni_generated
