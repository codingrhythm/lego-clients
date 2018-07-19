// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from lego.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace lego {

class LegoPlatform;
struct STemplate;

/** Shared core APIs */
class LegoCore {
public:
    virtual ~LegoCore() {}

    /** class method to create core API instance */
    static std::shared_ptr<LegoCore> create(const std::shared_ptr<LegoPlatform> & platform);

    /** get data, returns template id */
    virtual std::string get_data() = 0;

    /** send data */
    virtual void send_data(const STemplate & data) = 0;

    /** upload file */
    virtual void upload_file(const std::vector<uint8_t> & file_data) = 0;

    /** download file */
    virtual void download_file(const std::string & file_id) = 0;

    /** performance test code */
    virtual STemplate send_large_data_over_bridge(const std::string & template_id) = 0;

    virtual STemplate generate_large_data(int32_t number_of_pages, int32_t questions_per_page) = 0;

    virtual std::string prefix_string(const std::string & input) = 0;
};

}  // namespace lego
