#include "app_manager.hpp"
#include "app_observer.hpp"

namespace lego {
  class AppManagerImpl : public lego::AppManager {
  private:
    std::shared_ptr<AppObserver> _observer;

  public:
    AppManagerImpl(const std::shared_ptr<AppObserver> & observer);
    void update_time_string(const std::string & time_string);
  };
}
