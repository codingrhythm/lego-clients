#include "ui_manager_impl.hpp"
#include "task.hpp"

class SavePeopleTask: public lego::Task {
public:
    SavePeopleTask(const std::string & firstName,
                   const std::string & lastName,
                   const std::shared_ptr<lego::Storage> storage) {
        firstName_ = firstName;
        lastName_ = lastName;
        storage_ = storage;
    }

    void execute() {
        try {
            auto p = storage_.lock();
            p->save_people(firstName_, lastName_);
        } catch (std::bad_weak_ptr b) {
            printf("bad weak prt");
        }
    }
private:
    std::string firstName_;
    std::string lastName_;
    std::weak_ptr<lego::Storage> storage_;
};

class GetPeopleTask: public lego::Task {
public:
    GetPeopleTask(const std::shared_ptr<lego::Storage> storage) {
        storage_ = storage;
    }

    void execute() {
        try {
            auto p = storage_.lock();
            p->getPeople();
        } catch (std::bad_weak_ptr b) {
            printf("bad weak prt");
        }
    }
private:
    std::weak_ptr<lego::Storage> storage_;
};

class UpdatePeopleStateTask: public lego::Task {
public:
    UpdatePeopleStateTask(const lego::People people, const std::shared_ptr<lego::UiObserver> observer)
    : people_(people.first_name, people.last_name) {
        observer_ = observer;
    }

    void execute() {
        try {
            auto p = observer_.lock();
            p->people_updated(people_);
        } catch (std::bad_weak_ptr b) {
            printf("bad weak prt");
        }
    }
private:
    std::weak_ptr<lego::UiObserver> observer_;
    lego::People people_;
};

class UpdateTitleStateTask: public lego::Task {
public:
    UpdateTitleStateTask(const std::string title, const std::shared_ptr<lego::UiObserver> observer) {
        title_ = title;
        observer_ = observer;
    }

    void execute() {
        try {
            auto p = observer_.lock();
            p->title_updated(title_);
        } catch (std::bad_weak_ptr b) {
            printf("bad weak prt");
        }
    }
private:
    std::weak_ptr<lego::UiObserver> observer_;
    std::string title_;
};

class UpdateTimeStateTask: public lego::Task {
public:
    UpdateTimeStateTask(const std::string timeString, const std::shared_ptr<lego::UiObserver> observer) {
        timeString_ = timeString;
        observer_ = observer;
    }

    void execute() {
        try {
            auto p = observer_.lock();
            p->time_string_updated(timeString_);
        } catch (std::bad_weak_ptr b) {
            printf("bad weak prt");
        }
    }
private:
    std::weak_ptr<lego::UiObserver> observer_;
    std::string timeString_;
};

namespace lego {

    std::shared_ptr<UiManager> UiManager::create(const std::shared_ptr<UiObserver> & observer, const std::shared_ptr<UiPlatformSupport> & platform) {
        return std::make_shared<UIManagerImpl>(observer, platform);
    }

    UIManagerImpl::UIManagerImpl(const std::shared_ptr<UiObserver> & observer, const std::shared_ptr<UiPlatformSupport> & platform) : _people("", "") {
        _observer = observer;
        _platform = platform;
        _title = "Welcome";
        _storage = std::make_shared<Storage>(_platform->get_storage_path());
    }

    void UIManagerImpl::start() {
        _storage->setObserver(shared_from_this());
        this->getPeople();
    }

    void UIManagerImpl::stop() {
        _storage->removeObserver();
    }

    void UIManagerImpl::getPeople() {
        auto task = std::make_shared<GetPeopleTask>(_storage);
        _platform->post_task_in_background_thread(task);
    }

    void UIManagerImpl::update_title(const std::string & new_title) {
        _title = new_title;
        // do complex in memory task here
        // this is just a demo purpose
        // in real world cases, you don't need to have background thread for a simple task like this,
        // so there is no need to dispatch back to main queue
        auto task = std::make_shared<UpdateTitleStateTask>(_title, _observer);
        _platform->post_task_in_main_thread(task);
    }

    void UIManagerImpl::update_first_name(const std::string & first_name) {
        auto task = std::make_shared<SavePeopleTask>(first_name, _people.last_name, _storage);
        _platform->post_task_in_background_thread(task);
    }

    void UIManagerImpl::update_last_name(const std::string & last_name) {
        auto task = std::make_shared<SavePeopleTask>(_people.first_name, last_name, _storage);
        _platform->post_task_in_background_thread(task);
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

        auto task = std::make_shared<UpdatePeopleStateTask>(_people, _observer);
        _platform->post_task_in_main_thread(task);
    }

    void UIManagerImpl::time_string_updated(const std::string &time_string) {
        auto task = std::make_shared<UpdateTimeStateTask>(time_string, _observer);
        _platform->post_task_in_main_thread(task);
    }

    void UIManagerImpl::get_time_string_async() {
        _platform->get_time_string_async(shared_from_this());
    }
}
