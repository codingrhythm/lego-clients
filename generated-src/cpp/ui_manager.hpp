// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#pragma once

#include <memory>
#include <string>

namespace lego {

class UiObserver;
class UiPlatformSupport;

class UiManager {
public:
    virtual ~UiManager() {}

    static std::shared_ptr<UiManager> create(const std::shared_ptr<UiObserver> & observer, const std::shared_ptr<UiPlatformSupport> & platform);

    virtual void start() = 0;

    virtual void stop() = 0;

    virtual void update_title(const std::string & new_title) = 0;

    virtual void update_first_name(const std::string & first_name) = 0;

    virtual void update_last_name(const std::string & last_name) = 0;

    virtual void time_string_updated(const std::string & time_string) = 0;

    virtual void get_time_string() = 0;

    virtual void get_time_string_async() = 0;
};

}  // namespace lego
