// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ui.djinni

#include "view_event_handler.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class GBViewEventHandler;

namespace djinni_generated {

class ViewEventHandler
{
public:
    using CppType = std::shared_ptr<::gearsbox::ViewEventHandler>;
    using CppOptType = std::shared_ptr<::gearsbox::ViewEventHandler>;
    using ObjcType = GBViewEventHandler*;

    using Boxed = ViewEventHandler;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

