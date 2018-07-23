//
//  storage.hpp
//  lego
//
//  Created by Yuzhou Zhu on 23/7/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#include "people_generated.h"
#include "storage_observer.hpp"

#ifndef storage_hpp
#define storage_hpp

#include <stdio.h>

#endif /* storage_hpp */

namespace lego {
    class Storage {
    private:
        std::string _storage_path;
        std::weak_ptr<StorageObserver> _observer;

    public:
        Storage(const std::string storage_path);
        void setObserver(const std::shared_ptr<StorageObserver> observer);
        void removeObserver();
        void getPeople();
        void save_people(const std::string first_name, const std::string last_name);
    };
}
