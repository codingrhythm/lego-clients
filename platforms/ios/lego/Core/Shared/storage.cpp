//
//  storage.cpp
//  lego
//
//  Created by Yuzhou Zhu on 23/7/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#include "storage.hpp"
#include "flatbuffers/idl.h"
#include "flatbuffers/util.h"

namespace lego {
    Storage::Storage(const std::string storage_path) {
        _storage_path = storage_path;

    }

    void Storage::setObserver(const std::shared_ptr<StorageObserver> observer) {
        this->_observer = observer;
    }

    void Storage::removeObserver() {

    }

    void Storage::getPeople() {
        flatbuffers::FlatBufferBuilder builder;
        std::string loaded_file;
        std::string file_path = _storage_path + "/people.bin";
        flatbuffers::LoadFile(file_path.c_str(), true, &loaded_file);
        if (loaded_file.length() == 0) {
            return;
        }
        builder.PushBytes((uint8_t*)(loaded_file.c_str()), loaded_file.length());
        auto record = UIStorage::GetPeopleRecord(builder.GetCurrentBufferPointer());

        try {
            auto p = _observer.lock();
            p->people_updated(record);
        } catch (std::bad_weak_ptr b) {
            printf("bad weak prt");
        }
    }

    void Storage::save_people(const std::string first_name, const std::string last_name) {
        flatbuffers::FlatBufferBuilder builder;

        auto first_name_str = builder.CreateString(first_name);
        auto last_name_str = builder.CreateString(last_name);
        UIStorage::PeopleRecordBuilder peopleBuilder(builder);
        peopleBuilder.add_first_name(first_name_str);
        peopleBuilder.add_last_name(last_name_str);
        auto record = peopleBuilder.Finish();
        builder.Finish(record);

        std::string file_path = _storage_path + "/people.bin";
        flatbuffers::SaveFile(file_path.c_str(), (char *)builder.GetBufferPointer(), builder.GetSize(), true);

        this->getPeople();
    }
}
