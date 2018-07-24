// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#include "task.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class LGTask;

namespace djinni_generated {

class Task
{
public:
    using CppType = std::shared_ptr<::lego::Task>;
    using CppOptType = std::shared_ptr<::lego::Task>;
    using ObjcType = LGTask*;

    using Boxed = Task;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

