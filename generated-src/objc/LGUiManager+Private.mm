// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGUiManager+Private.h"
#import "LGUiManager.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "LGUiObserver+Private.h"
#import "LGUiPlatformSupport+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface LGUiManager ()

- (id)initWithCpp:(const std::shared_ptr<::lego::UiManager>&)cppRef;

@end

@implementation LGUiManager {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::lego::UiManager>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::lego::UiManager>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable LGUiManager *)create:(nullable id<LGUiObserver>)observer
                        platform:(nullable id<LGUiPlatformSupport>)platform {
    try {
        auto objcpp_result_ = ::lego::UiManager::create(::djinni_generated::UiObserver::toCpp(observer),
                                                        ::djinni_generated::UiPlatformSupport::toCpp(platform));
        return ::djinni_generated::UiManager::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)start {
    try {
        _cppRefHandle.get()->start();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)stop {
    try {
        _cppRefHandle.get()->stop();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)updateTitle:(nonnull NSString *)newTitle {
    try {
        _cppRefHandle.get()->update_title(::djinni::String::toCpp(newTitle));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)updateFirstName:(nonnull NSString *)firstName {
    try {
        _cppRefHandle.get()->update_first_name(::djinni::String::toCpp(firstName));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)updateLastName:(nonnull NSString *)lastName {
    try {
        _cppRefHandle.get()->update_last_name(::djinni::String::toCpp(lastName));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)timeStringUpdated:(nonnull NSString *)timeString {
    try {
        _cppRefHandle.get()->time_string_updated(::djinni::String::toCpp(timeString));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)getTimeString {
    try {
        _cppRefHandle.get()->get_time_string();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)getTimeStringAsync {
    try {
        _cppRefHandle.get()->get_time_string_async();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto UiManager::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto UiManager::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<LGUiManager>(cpp);
}

}  // namespace djinni_generated

@end
