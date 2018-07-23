//
//  storage_observer.hpp
//  lego
//
//  Created by Yuzhou Zhu on 23/7/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#pragma once

#include <string>

namespace lego {

    class StorageObserver {
    public:
        virtual void people_updated(const UIStorage::PeopleRecord * people_record) = 0;
    };

}
