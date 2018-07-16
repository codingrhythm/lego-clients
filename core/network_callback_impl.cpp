#include "network_callback_impl.hpp"

namespace lego {
    NetworkCallbackImpl::NetworkCallbackImpl(const std::string & path) {
        _storage_path = path;
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

}
