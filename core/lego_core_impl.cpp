#include "lego_core_impl.hpp"
#include "flatbuffers/idl.h"
#include "flatbuffers/util.h"
#include "lego_generated.h"
#include "s_template.hpp"
#include "s_page.hpp"
#include "s_question.hpp"
#include <string>

#include "lego.pb.h"
#include "lego.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <grpc/support/log.h>

namespace lego {
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
    }

    void LegoCoreImpl::get_data_handler(const std::string & template_id) {
        flatbuffers::FlatBufferBuilder builder;
        std::string loaded_file;
        std::string file_path = _platform->get_storage_path() + "/" + template_id + ".bin";
        flatbuffers::LoadFile(file_path.c_str(), true, &loaded_file);
        builder.PushBytes((uint8_t*)(loaded_file.c_str()), loaded_file.length());
        auto record = ::Lego::GetTemplateRecord(builder.GetCurrentBufferPointer());

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

        _platform->data_updated(templateData);
    }

    void LegoCoreImpl::send_data_handler() {

    }

    void LegoCoreImpl::upload_handler() {

    }

    void LegoCoreImpl::download_handler(const std::string & file_path) {

    }

    void LegoCoreImpl::get_data(bool use_grpc) {
        if (use_grpc) {
            _platform->grpc_get_data(_networkCallback);
        } else {
            _platform->http_get_data(_networkCallback);
        }
    }

    void LegoCoreImpl::send_data(const STemplate & data, bool use_grpc) {
        if (use_grpc) {
            _platform->grpc_send_data(data, _networkCallback);
        } else {
            _platform->http_send_data(data, _networkCallback);
        }
    }

    void LegoCoreImpl::upload_file(const std::vector<uint8_t> & file_data) {
    }

    void LegoCoreImpl::download_file(const std::string & file_id) {

    }
}
