//
//  network.cpp
//  lego
//
//  Created by Yuzhou Zhu on 23/7/18.
//  Copyright © 2018 Yuzhou Zhu. All rights reserved.
//

#include "network.hpp"

namespace lego {
    Network::Network(std::shared_ptr<grpc::Channel> channel)
    : stub_(lego::Lego::NewStub(channel)) {
        
    }

    void Network::savePeople(const lego::PeopleData data) {
        grpc::ClientContext context;
        grpc::CompletionQueue cq;
        grpc::Status status;
        lego::LegoResponse response;
        std::unique_ptr<grpc::ClientAsyncResponseReader<lego::LegoResponse>> rpc(stub_->PrepareAsyncSavePeople(&context, data, &cq));

        rpc->StartCall();
        rpc->Finish(&response, &status, (void*)1);
        void* got_tag;
        bool ok = false;
        // Block until the next result is available in the completion queue "cq".
        // The return value of Next should always be checked. This return value
        // tells us whether there is any kind of event or the cq_ is shutting down.
        GPR_ASSERT(cq.Next(&got_tag, &ok));

        // Verify that the result from "cq" corresponds, by its tag, our previous
        // request.
        GPR_ASSERT(got_tag == (void*)1);
        // ... and that the request was completed successfully. Note that "ok"
        // corresponds solely to the request for updates introduced by Finish().
        GPR_ASSERT(ok);
    }

    lego::PeopleData Network::getPeople() {
        grpc::ClientContext context;
        grpc::CompletionQueue cq;
        grpc::Status status;
        lego::GetRequest request;
        request.set_flag("nice");
        lego::PeopleData response;
        std::unique_ptr<grpc::ClientAsyncResponseReader<lego::PeopleData>> rpc(stub_->PrepareAsyncGetPeople(&context, request, &cq));

        rpc->StartCall();
        rpc->Finish(&response, &status, (void*)1);
        void* got_tag;
        bool ok = false;
        // Block until the next result is available in the completion queue "cq".
        // The return value of Next should always be checked. This return value
        // tells us whether there is any kind of event or the cq_ is shutting down.
        GPR_ASSERT(cq.Next(&got_tag, &ok));

        // Verify that the result from "cq" corresponds, by its tag, our previous
        // request.
        GPR_ASSERT(got_tag == (void*)1);
        // ... and that the request was completed successfully. Note that "ok"
        // corresponds solely to the request for updates introduced by Finish().
        GPR_ASSERT(ok);

        // Act upon the status of the actual RPC.
        return response;
    }
}
