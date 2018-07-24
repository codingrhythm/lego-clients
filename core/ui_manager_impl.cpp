#include "ui_manager_impl.hpp"

namespace lego {

    std::shared_ptr<UiManager> UiManager::create(const std::shared_ptr<UiObserver> & observer, const std::shared_ptr<UiPlatformSupport> & platform) {
        return std::make_shared<UIManagerImpl>(observer, platform);
    }

    UIManagerImpl::UIManagerImpl(const std::shared_ptr<UiObserver> & observer, const std::shared_ptr<UiPlatformSupport> & platform) : _people("", "") {
        _observer = observer;
        _platform = platform;
        _title = "Welcome";
        _storage = std::make_unique<Storage>(_platform->get_storage_path());
    }

    void UIManagerImpl::start() {
        _storage->setObserver(shared_from_this());
        _storage->getPeople();
    }

    void UIManagerImpl::stop() {
        _storage->removeObserver();
    }

    void UIManagerImpl::update_title(const std::string & new_title) {
        _title = new_title;
        
        _observer->title_updated(_title);
    }

    void UIManagerImpl::update_first_name(const std::string & first_name) {
        _storage->save_people(first_name, _people.last_name);
    }

    void UIManagerImpl::update_last_name(const std::string & last_name) {
        _storage->save_people(_people.first_name, last_name);
    }

    void UIManagerImpl::get_time_string() {
        std::string time_string = _platform->get_time_string();
        _observer->time_string_updated(time_string);
    }

    void UIManagerImpl::people_updated(const UIStorage::PeopleRecord * people_record) {
        _people = {
            people_record->first_name()->c_str(),
            people_record->last_name()->c_str()
        };
        _observer->people_updated(_people);
    }

    void UIManagerImpl::time_string_updated(const std::string &time_string) {
        _observer->time_string_updated(time_string);
    }

    void UIManagerImpl::get_time_string_async() {
        _platform->get_time_string_async(shared_from_this());
    }
}
