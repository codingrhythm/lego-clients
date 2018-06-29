// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#include "lego_core.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class LGLegoCore;

namespace djinni_generated {

class LegoCore
{
public:
    using CppType = std::shared_ptr<::lego::LegoCore>;
    using CppOptType = std::shared_ptr<::lego::LegoCore>;
    using ObjcType = LGLegoCore*;

    using Boxed = LegoCore;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

