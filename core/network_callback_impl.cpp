#include "network_callback_impl.hpp"
#include "s_template.hpp"
#include "flatbuffers/idl.h"
#include "flatbuffers/util.h"
#include "lego_generated.h"

namespace lego {
    NetworkCallbackImpl::NetworkCallbackImpl(const std::string & path) {
        _storage_path = path;
    }

    std::string NetworkCallbackImpl::parse_and_store_data(const STemplate & data) {
        flatbuffers::FlatBufferBuilder builder;

        std::vector<flatbuffers::Offset<Lego::PageRecord>> pages_vector;

        for (const SPage &page : data.pages) {
            std::vector<flatbuffers::Offset<Lego::QuestionRecord>> questions_vector;
            for (const SQuestion &question: page.questions) {
                auto id = builder.CreateString(question.id);
                auto title = builder.CreateString(question.title);
                auto description = builder.CreateString(question.question_description);
                auto questionRecord = Lego::CreateQuestionRecord(builder,
                                                                 id,
                                                                 title,
                                                                 question.response_type,
                                                                 description,
                                                                 question.order);
                questions_vector.push_back(questionRecord);
            }
            auto id = builder.CreateString(page.id);
            auto title = builder.CreateString(page.title);
            auto questions = builder.CreateVector(questions_vector);
            auto pageRecord = Lego::CreatePageRecord(builder,
                                                     id,
                                                     title,
                                                     page.order,
                                                     questions);
            pages_vector.push_back(pageRecord);
        }
        auto id = builder.CreateString(data.id);
        auto name = builder.CreateString(data.name);
        auto pages = builder.CreateVector(pages_vector);
        Lego::TemplateRecordBuilder templateBuilder(builder);
        templateBuilder.add_id(id);
        templateBuilder.add_name(name);
        templateBuilder.add_pages(pages);
        auto record = templateBuilder.Finish();
        builder.Finish(record);

        std::string file_path = _storage_path + "/" + data.id + ".bin";
        flatbuffers::SaveFile(file_path.c_str(), (char *)builder.GetBufferPointer(), builder.GetSize(), true);
        return data.id;
    }

    void NetworkCallbackImpl::on_http_download_file_success(const std::string & path) {
        if (downloadCallback) {
            downloadCallback(path);
        }
    }

    void NetworkCallbackImpl::on_http_upload_file_success() {
        if (uploadCallback) {
            uploadCallback();
        }
    }

    void NetworkCallbackImpl::on_http_get_data_success(const std::string & path) {
        if (getDataCallback) {
            //getDataCallback(parse_and_store_data(data));
        }
    }

    void NetworkCallbackImpl::on_http_send_data_success() {
        if (sendDataCallback) {
            sendDataCallback();
        }
    }

    void NetworkCallbackImpl::on_grpc_get_data_success(const STemplate & data) {
        if (getDataCallback) {
            getDataCallback(parse_and_store_data(data));
        }
    }

    void NetworkCallbackImpl::on_grpc_send_data_success() {
        if (sendDataCallback) {
            sendDataCallback();
        }
    }

}
