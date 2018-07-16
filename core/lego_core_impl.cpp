#include "lego_core_impl.hpp"
#include "flatbuffers/idl.h"
#include "flatbuffers/util.h"
#include "s_template.hpp"
#include "s_page.hpp"
#include "s_question.hpp"
#include <string>

#include "lego.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>
#include "lego_generated.h"


class LegoClient {
public:
    LegoClient(std::shared_ptr<grpc::Channel> channel)
    : stub_(lego::Lego::NewStub(channel)) {
    }

    lego::Template GetTemplate() {
        grpc::ClientContext context;
        grpc::CompletionQueue cq;
        grpc::Status status;
        lego::GetRequest request;
        request.set_flag("nice");
        lego::Template response;
        std::unique_ptr<grpc::ClientAsyncResponseReader<lego::Template>> rpc(stub_->PrepareAsyncGetData(&context, request, &cq));

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
private:
    std::unique_ptr<lego::Lego::Stub> stub_;
};

namespace lego {
    std::unique_ptr<LegoClient> _client;
    std::shared_ptr<LegoCore> LegoCore::create(const std::shared_ptr<LegoPlatform> & platform) {
        return std::make_shared<LegoCoreImpl>(platform);
    }

    LegoCoreImpl::LegoCoreImpl(const std::shared_ptr<LegoPlatform> & platform) {
        _platform = platform;
        _networkCallback = std::make_shared<NetworkCallbackImpl>(platform->get_storage_path());
        _networkCallback->getDataCallback = std::bind(&LegoCoreImpl::get_data_handler, this, std::placeholders::_1);
        _networkCallback->sendDataCallback = std::bind(&LegoCoreImpl::send_data_handler, this);
        _networkCallback->downloadCallback = std::bind(&LegoCoreImpl::download_handler, this, std::placeholders::_1);
        _networkCallback->uploadCallback = std::bind(&LegoCoreImpl::upload_handler, this);
        grpc_init();
    }

    void LegoCoreImpl::get_data_handler(const std::string & template_id) {

    }

    void LegoCoreImpl::send_data_handler() {

    }

    void LegoCoreImpl::upload_handler() {

    }

    void LegoCoreImpl::download_handler(const std::string & file_path) {

    }

    std::string LegoCoreImpl::get_data() {
        _client = std::make_unique<LegoClient>(CreateChannel("localhost:8513", grpc::InsecureChannelCredentials()));
        lego::Template templateData = _client->GetTemplate();
        this->parse_and_store_data(templateData);
        return templateData.id().c_str();
    }

    void LegoCoreImpl::send_data(const STemplate & data) {

    }

    void LegoCoreImpl::upload_file(const std::vector<uint8_t> & file_data) {
    }

    void LegoCoreImpl::download_file(const std::string & file_id) {

    }

    STemplate LegoCoreImpl::send_large_data_over_bridge(const std::string & template_id) {
        flatbuffers::FlatBufferBuilder builder;
        std::string loaded_file;
        std::string file_path = _platform->get_storage_path() + "/" + template_id + ".bin";
        flatbuffers::LoadFile(file_path.c_str(), true, &loaded_file);
        builder.PushBytes((uint8_t*)(loaded_file.c_str()), loaded_file.length());
        auto record = LegoStorage::GetTemplateRecord(builder.GetCurrentBufferPointer());

        std::vector<SPage> pages;
        for (const auto page:*record->pages()) {
            std::vector<SQuestion> questions;
            for (const auto question:*page->questions()) {
                SQuestion question_data = {
                    question->id()->c_str(),
                    question->title()->c_str(),
                    question->response_type(),
                    question->question_description()->c_str(),
                    question->order()
                };
                questions.push_back(question_data);
            }

            SPage page_data = {
                page->id()->c_str(),
                page->title()->c_str(),
                page->order(),
                questions
            };

            pages.push_back(page_data);
        }

        STemplate templateData = {
            record->id()->c_str(),
            record->name()->c_str(),
            pages
        };

        return templateData;
    }

    void LegoCoreImpl::parse_and_store_data(const Template & data) {
        flatbuffers::FlatBufferBuilder builder;

        std::vector<flatbuffers::Offset<LegoStorage::PageRecord>> pages_vector;

        for (const Page &page : data.pages()) {
            std::vector<flatbuffers::Offset<LegoStorage::QuestionRecord>> questions_vector;
            for (const Question &question: page.questions()) {
                auto id = builder.CreateString(question.id());
                auto title = builder.CreateString(question.title());
                auto description = builder.CreateString(question.description());
                auto questionRecord = LegoStorage::CreateQuestionRecord(builder,
                                                                 id,
                                                                 title,
                                                                 question.response_type(),
                                                                 description,
                                                                 question.order());
                questions_vector.push_back(questionRecord);
            }
            auto id = builder.CreateString(page.id());
            auto title = builder.CreateString(page.title());
            auto questions = builder.CreateVector(questions_vector);
            auto pageRecord = LegoStorage::CreatePageRecord(builder,
                                                     id,
                                                     title,
                                                     page.order(),
                                                     questions);
            pages_vector.push_back(pageRecord);
        }
        auto id = builder.CreateString(data.id());
        auto name = builder.CreateString(data.name());
        auto pages = builder.CreateVector(pages_vector);
        LegoStorage::TemplateRecordBuilder templateBuilder(builder);
        templateBuilder.add_id(id);
        templateBuilder.add_name(name);
        templateBuilder.add_pages(pages);
        auto record = templateBuilder.Finish();
        builder.Finish(record);

        std::string file_path = _platform->get_storage_path() + "/" + data.id() + ".bin";
        flatbuffers::SaveFile(file_path.c_str(), (char *)builder.GetBufferPointer(), builder.GetSize(), true);
    }

    STemplate LegoCoreImpl::generate_large_data(int32_t number_of_pages, int32_t questions_per_page) {

        std::vector<SPage> pages;
        for (int page = 1; page <= number_of_pages; page++) {
            std::vector<SQuestion> questions;
            for (int question = 1; question <= questions_per_page; question++) {
                SQuestion question_data = {
                    std::to_string(question),
                    "This is title for question " + std::to_string(question),
                    question,
                    "This is description for question " + std::to_string(question),
                    question
                };
                questions.push_back(question_data);
            }

            SPage page_data = {
                std::to_string(page),
                "This is title for page " + std::to_string(page),
                page,
                questions
            };

            pages.push_back(page_data);
        }

        STemplate templateData = {
            "template id",
            "template name",
            pages
        };

        return templateData;
    }
}
