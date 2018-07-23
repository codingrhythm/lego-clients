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
        _network = std::make_shared<Network>(CreateChannel("localhost:8513", grpc::InsecureChannelCredentials()));
    }

    void Storage::setObserver(const std::shared_ptr<StorageObserver> observer) {
        this->_observer = observer;
    }

    void Storage::removeObserver() {

    }

    void Storage::getPeople() {
        notifyObserver();
        getDataFromServer();
    }

    void Storage::save_people(const std::string first_name, const std::string last_name) {
        this->saveDataToCache(first_name, last_name);

        this->sendDataToServer();

        // optimistic state update
        this->getPeople();
    }

    void Storage::getDataFromServer() {
        auto response = _network->getPeople();
        this->saveDataToCache(response.first_name(), response.last_name());
        notifyObserver();
    }

    void Storage::sendDataToServer() {
        const UIStorage::PeopleRecord * record = this->getCachedData();

        if (record != nullptr) {
            lego::PeopleData peopleData;
            peopleData.set_first_name(record->first_name()->c_str());
            peopleData.set_last_name(record->last_name()->c_str());
            _network->savePeople(peopleData);
        }
    }

    void Storage::notifyObserver() {
        const UIStorage::PeopleRecord * record = this->getCachedData();

        if (record != nullptr) {
            try {
                auto p = _observer.lock();
                p->people_updated(record);
            } catch (std::bad_weak_ptr b) {
                printf("bad weak prt");
            }
        }
    }

    const UIStorage::PeopleRecord * Storage::getCachedData() {
        flatbuffers::FlatBufferBuilder builder;
        std::string loaded_file;
        std::string file_path = _storage_path + "/people.bin";
        flatbuffers::LoadFile(file_path.c_str(), true, &loaded_file);
        if (loaded_file.length() == 0) {
            return nullptr;
        }
        builder.PushBytes((uint8_t*)(loaded_file.c_str()), loaded_file.length());
        return UIStorage::GetPeopleRecord(builder.GetCurrentBufferPointer());
    }

    void Storage::saveDataToCache(const std::string first_name, const std::string last_name) {
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
    }
    
}
