//
//  network.hpp
//  lego
//
//  Created by Yuzhou Zhu on 23/7/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#ifndef network_hpp
#define network_hpp

#include <stdio.h>
#include "lego.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>

#endif /* network_hpp */

namespace lego {
    class Network {
    private:
        std::unique_ptr<lego::Lego::Stub> stub_;

    public:
        Network(std::shared_ptr<grpc::Channel> channel);
        PeopleData getPeople();
        void savePeople(const PeopleData data);
    };
}
