// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGUiPlatformSupport+Private.h"
#import "LGUiPlatformSupport.h"
#import "DJIMarshal+Private.h"
#import "DJIObjcWrapperCache+Private.h"
#include <stdexcept>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

namespace djinni_generated {

class UiPlatformSupport::ObjcProxy final
: public ::lego::UiPlatformSupport
, private ::djinni::ObjcProxyBase<ObjcType>
{
    friend class ::djinni_generated::UiPlatformSupport;
public:
    using ObjcProxyBase::ObjcProxyBase;
    std::string get_time_string() override
    {
        @autoreleasepool {
            auto objcpp_result_ = [djinni_private_get_proxied_objc_object() getTimeString];
            return ::djinni::String::toCpp(objcpp_result_);
        }
    }
};

}  // namespace djinni_generated

namespace djinni_generated {

auto UiPlatformSupport::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return ::djinni::get_objc_proxy<ObjcProxy>(objc);
}

auto UiPlatformSupport::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return dynamic_cast<ObjcProxy&>(*cpp).djinni_private_get_proxied_objc_object();
}

}  // namespace djinni_generated