#include "ui_manager.hpp"
#include "ui_observer.hpp"
#include "ui_platform_support.hpp"
#include "storage.hpp"
#include "storage_observer.hpp"
#include "people.hpp"

namespace lego {
    class UIManagerImpl : public lego::UiManager, public lego::StorageObserver, public std::enable_shared_from_this<UIManagerImpl> {
    private:
        std::shared_ptr<UiObserver> _observer;
        std::shared_ptr<UiPlatformSupport> _platform;
        std::string _title;
        std::unique_ptr<Storage> _storage;
        lego::People _people;

    public:
        UIManagerImpl(const std::shared_ptr<UiObserver> & observer, const std::shared_ptr<UiPlatformSupport> & platform);
        void start();
        void stop();
        void update_title(const std::string & new_title);
        void update_first_name(const std::string & first_name);
        void update_last_name(const std::string & last_name);
        void time_string_updated(const std::string & time_string);
        void people_updated(const UIStorage::PeopleRecord * people_record);
        void get_time_string();
        void get_time_string_async();
    };
}
