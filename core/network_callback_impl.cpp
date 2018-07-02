#include "network_callback_impl.hpp"
#include "template.hpp"
#include "flatbuffers/idl.h"
#include "flatbuffers/util.h"
#include "lego_generated.h"

namespace lego {
  std::string NetworkCallbackImpl::parse_and_store_data(const Template & data) {
    // TODO: convert to flatbuffers and save on disk
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

  void NetworkCallbackImpl::on_http_get_data_success(const Template & data) {
    if (getDataCallback) {
      getDataCallback(parse_and_store_data(data));
    }
  }

  void NetworkCallbackImpl::on_http_send_data_success() {
    if (sendDataCallback) {
      sendDataCallback();
    }
  }

  void NetworkCallbackImpl::on_grpc_get_data_success(const Template & data) {
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
