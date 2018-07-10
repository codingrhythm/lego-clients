// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGSTemplate+Private.h"
#import "DJIMarshal+Private.h"
#import "LGSPage+Private.h"
#include <cassert>

namespace djinni_generated {

auto STemplate::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.id),
            ::djinni::String::toCpp(obj.name),
            ::djinni::List<::djinni_generated::SPage>::toCpp(obj.pages)};
}

auto STemplate::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[LGSTemplate alloc] initWithId:(::djinni::String::fromCpp(cpp.id))
                                      name:(::djinni::String::fromCpp(cpp.name))
                                     pages:(::djinni::List<::djinni_generated::SPage>::fromCpp(cpp.pages))];
}

}  // namespace djinni_generated