// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGUiPlatformSupport+Private.h"
#import "LGUiPlatformSupport.h"
#import "DJIMarshal+Private.h"
#import "DJIObjcWrapperCache+Private.h"
#import "LGTask+Private.h"
#import "LGUiManager+Private.h"
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
    std::string get_storage_path() override
    {
        @autoreleasepool {
            auto objcpp_result_ = [djinni_private_get_proxied_objc_object() getStoragePath];
            return ::djinni::String::toCpp(objcpp_result_);
        }
    }
    void get_time_string_async(const std::shared_ptr<::lego::UiManager> & c_manager) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() getTimeStringAsync:(::djinni_generated::UiManager::fromCpp(c_manager))];
        }
    }
    void post_task_in_background_thread(const std::shared_ptr<::lego::Task> & c_task) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() postTaskInBackgroundThread:(::djinni_generated::Task::fromCpp(c_task))];
        }
    }
    void post_task_in_main_thread(const std::shared_ptr<::lego::Task> & c_task) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() postTaskInMainThread:(::djinni_generated::Task::fromCpp(c_task))];
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
