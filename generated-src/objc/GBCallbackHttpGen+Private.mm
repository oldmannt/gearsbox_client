// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from gearsbox.djinni

#import "GBCallbackHttpGen+Private.h"
#import "GBCallbackHttpGen.h"
#import "DJIMarshal+Private.h"
#import "DJIObjcWrapperCache+Private.h"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

namespace djinni_generated {

class CallbackHttpGen::ObjcProxy final
: public ::gearsbox::CallbackHttpGen
, public ::djinni::ObjcProxyCache::Handle<ObjcType>
{
public:
    using Handle::Handle;
    bool callback(int64_t c_id, bool c_result, const std::string & c_data) override
    {
        @autoreleasepool {
            auto r = [Handle::get() callback:(::djinni::I64::fromCpp(c_id))
                                      result:(::djinni::Bool::fromCpp(c_result))
                                        data:(::djinni::String::fromCpp(c_data))];
            return ::djinni::Bool::toCpp(r);
        }
    }
};

}  // namespace djinni_generated

namespace djinni_generated {

auto CallbackHttpGen::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return ::djinni::get_objc_proxy<ObjcProxy>(objc);
}

auto CallbackHttpGen::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return dynamic_cast<ObjcProxy&>(*cpp).Handle::get();
}

}  // namespace djinni_generated
