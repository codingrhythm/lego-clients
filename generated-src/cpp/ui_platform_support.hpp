// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#pragma once

#include <string>

namespace lego {

class UiPlatformSupport {
public:
    virtual ~UiPlatformSupport() {}

    virtual std::string get_time_string() = 0;

    virtual std::string get_storage_path() = 0;
};

}  // namespace lego
