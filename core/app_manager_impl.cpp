#include "app_manager_impl.hpp"

namespace lego {

    std::shared_ptr<AppManager> AppManager::create(const std::shared_ptr<AppObserver> & observer) {
        return std::make_shared<AppManagerImpl>(observer);
    }

    AppManagerImpl::AppManagerImpl(const std::shared_ptr<AppObserver> & observer) {
        _observer = observer;
    }

    void AppManagerImpl::update_time_string(const std::string & time_string) {

    }
}
