#include "ui_manager_impl.hpp"

namespace lego {

  std::shared_ptr<UiManager> UiManager::create(const std::shared_ptr<UiObserver> & observer) {
    return std::make_shared<UIManagerImpl>(observer);
  }

  UIManagerImpl::UIManagerImpl(const std::shared_ptr<UiObserver> & observer) {
    _observer = observer;
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
}