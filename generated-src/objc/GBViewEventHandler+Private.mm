// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#import "GBViewEventHandler+Private.h"
#import "GBViewEventHandler.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "GBViewEventParam+Private.h"
#import "GBViewGen+Private.h"
#include <exception>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface GBViewEventHandler ()

- (id)initWithCpp:(const std::shared_ptr<::gearsbox::ViewEventHandler>&)cppRef;

@end

@implementation GBViewEventHandler {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::gearsbox::ViewEventHandler>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::gearsbox::ViewEventHandler>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (BOOL)handle:(nonnull GBViewEventParam *)param
          view:(nullable id<GBViewGen>)view {
    try {
        auto r = _cppRefHandle.get()->handle(::djinni_generated::ViewEventParam::toCpp(param),
                                             ::djinni_generated::ViewGen::toCpp(view));
        return ::djinni::Bool::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto ViewEventHandler::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto ViewEventHandler::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<GBViewEventHandler>(cpp);
}

}  // namespace djinni_generated

@end
