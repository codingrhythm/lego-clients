#include "network_callback.hpp"
#include <functional>

typedef std::function<void (const std::string&)> GetDataCallbackFunc;
typedef std::function<void ()> SendDataCallbackFunc;
typedef std::function<void ()> UploadCallbackFunc;
typedef std::function<void (const std::string&)> DownloadCallbackFunc;

namespace lego {
    class NetworkCallbackImpl : public lego::NetworkCallback {
    private:
        // properties
        std::string _storage_path;
        // methods
        std::string parse_and_store_data(const Template & data);

    public:
        // properties
        GetDataCallbackFunc getDataCallback;
        SendDataCallbackFunc sendDataCallback;
        UploadCallbackFunc uploadCallback;
        DownloadCallbackFunc downloadCallback;

        // constructor
        NetworkCallbackImpl(const std::string & path);

        // methods
        void on_http_download_file_success(const std::string & path);
        void on_http_upload_file_success();
        void on_http_get_data_success(const Template & data);
        void on_http_send_data_success();
        void on_grpc_get_data_success(const Template & data);
        void on_grpc_send_data_success();
    };
}
