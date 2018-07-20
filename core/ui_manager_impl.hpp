#include "ui_manager.hpp"
#include "ui_observer.hpp"
#include "ui_platform_support.hpp"

namespace lego {
    class UIManagerImpl : public lego::UiManager {
    private:
        std::shared_ptr<UiObserver> _observer;
        std::shared_ptr<UiPlatformSupport> _platform;
        std::string _title;

    public:
        UIManagerImpl(const std::shared_ptr<UiObserver> & observer, const std::shared_ptr<UiPlatformSupport> & platform);
        void update_title(const std::string & new_title);
        void update_first_name(const std::string & first_name);
        void update_last_name(const std::string & last_name);
        std::string get_time_string();
    };
}
