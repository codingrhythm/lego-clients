// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace lego {

class LegoPlatform;
struct Template;

/** Shared core APIs */
class LegoCore {
public:
    virtual ~LegoCore() {}

    /** class method to create core API instance */
    static std::shared_ptr<LegoCore> create(const std::shared_ptr<LegoPlatform> & platform);

    /** get data */
    virtual void get_data(bool use_grpc) = 0;

    /** send data */
    virtual void send_data(const Template & data, bool use_grpc) = 0;

    /** upload file */
    virtual void upload_file(const std::vector<uint8_t> & file_data) = 0;

    /** download file */
    virtual void download_file(const std::string & file_id) = 0;
};

}  // namespace lego
