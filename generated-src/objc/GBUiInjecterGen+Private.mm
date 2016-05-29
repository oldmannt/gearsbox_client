// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#import "GBUiInjecterGen+Private.h"
#import "GBUiInjecterGen.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "GBUiInjecterGen+Private.h"
#import "GBViewGen+Private.h"
#include <exception>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface GBUiInjecterGen ()

- (id)initWithCpp:(const std::shared_ptr<::gearsbox::UiInjecterGen>&)cppRef;

@end

@implementation GBUiInjecterGen {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::gearsbox::UiInjecterGen>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::gearsbox::UiInjecterGen>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable GBUiInjecterGen *)instance {
    try {
        auto r = ::gearsbox::UiInjecterGen::instance();
        return ::djinni_generated::UiInjecterGen::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)inject:(nonnull NSString *)id
          view:(nullable id<GBViewGen>)view {
    try {
        _cppRefHandle.get()->inject(::djinni::String::toCpp(id),
                                    ::djinni_generated::ViewGen::toCpp(view));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable id<GBViewGen>)getView:(nonnull NSString *)id {
    try {
        auto r = _cppRefHandle.get()->getView(::djinni::String::toCpp(id));
        return ::djinni_generated::ViewGen::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)removeView:(nonnull NSString *)id {
    try {
        _cppRefHandle.get()->removeView(::djinni::String::toCpp(id));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto UiInjecterGen::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto UiInjecterGen::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<GBUiInjecterGen>(cpp);
}

}  // namespace djinni_generated

@end
