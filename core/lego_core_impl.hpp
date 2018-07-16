#include "lego_core.hpp"
#include "lego_platform.hpp"
#include "network_callback_impl.hpp"
#include "lego.pb.h"

namespace lego {
  class LegoCoreImpl : public lego::LegoCore {
  private:
    std::shared_ptr<LegoPlatform> _platform;
    std::shared_ptr<NetworkCallbackImpl> _networkCallback;

    void get_data_handler(const std::string & template_id);
    void send_data_handler();
    void upload_handler();
    void download_handler(const std::string & file_path);
    void parse_and_store_data(const Template & data);

  public:
    LegoCoreImpl(const std::shared_ptr<LegoPlatform> & platform);
    std::string get_data();
    void send_data(const STemplate & data);
    void upload_file(const std::vector<uint8_t> & file_data);
    void download_file(const std::string & file_id);
    STemplate send_large_data_over_bridge(const std::string & template_id);
    STemplate generate_large_data();
  };
}
