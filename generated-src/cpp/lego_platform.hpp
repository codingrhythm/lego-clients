// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#pragma once

#include <memory>
#include <string>

namespace lego {

class NetworkCallback;
struct Template;

/** Platform APIs */
class LegoPlatform {
public:
    virtual ~LegoPlatform() {}

    /** get platform specific storage path */
    virtual std::string get_storage_path() = 0;

    /**
     * event subscriptions
     * notify UI layer when data is updated
     */
    virtual void data_updated(const Template & data) = 0;

    /** http methods */
    virtual void http_download_file(const std::string & file_id, const std::shared_ptr<NetworkCallback> & callback) = 0;

    virtual void http_upload_file(const std::string & path, const std::shared_ptr<NetworkCallback> & callback) = 0;

    virtual void http_get_data(const std::shared_ptr<NetworkCallback> & callback) = 0;

    virtual void http_send_data(const Template & data, const std::shared_ptr<NetworkCallback> & callback) = 0;

    /** grpc methods */
    virtual void grpc_get_data(const std::shared_ptr<NetworkCallback> & callback) = 0;

    virtual void grpc_send_data(const Template & data, const std::shared_ptr<NetworkCallback> & callback) = 0;
};

}  // namespace lego
