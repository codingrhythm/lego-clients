#include "lego_core_impl.hpp"

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

  void LegoCoreImpl::send_data(const Template & data, bool use_grpc) {
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
