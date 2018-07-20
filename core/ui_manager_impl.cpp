#include "ui_manager_impl.hpp"

namespace lego {

    std::shared_ptr<UiManager> UiManager::create(const std::shared_ptr<UiObserver> & observer, const std::shared_ptr<UiPlatformSupport> & platform) {
        return std::make_shared<UIManagerImpl>(observer, platform);
    }

    UIManagerImpl::UIManagerImpl(const std::shared_ptr<UiObserver> & observer, const std::shared_ptr<UiPlatformSupport> & platform) {
        _observer = observer;
        _platform = platform;
        _title = "Welcome";
    }

    void UIManagerImpl::update_title(const std::string & new_title) {
        _title = new_title;
        _observer->title_updated(_title);
    }

    void UIManagerImpl::update_first_name(const std::string & first_name) {

    }

    void UIManagerImpl::update_last_name(const std::string & last_name) {

    }

    std::string UIManagerImpl::get_time_string() {
        return _platform->get_time_string();
    }
}
