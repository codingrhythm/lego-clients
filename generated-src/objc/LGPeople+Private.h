// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#import "LGPeople.h"
#include "people.hpp"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class LGPeople;

namespace djinni_generated {

struct People
{
    using CppType = ::lego::People;
    using ObjcType = LGPeople*;

    using Boxed = People;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCpp(const CppType& cpp);
};

}  // namespace djinni_generated
