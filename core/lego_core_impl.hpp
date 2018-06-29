#include "lego_core.hpp"
#include "lego_platform.hpp"
#include "network_callback_impl.hpp"

namespace lego {
  class LegoCoreImpl : public lego::LegoCore {
  private:
    std::shared_ptr<LegoPlatform> _platform;
    std::shared_ptr<NetworkCallbackImpl> _networkCallback;

    void get_data_handler(const std::string & template_id);
    void send_data_handler();
    void upload_handler();
    void download_handler(const std::string & file_path);

  public:
    LegoCoreImpl(const std::shared_ptr<LegoPlatform> & platform);
    void get_data(bool use_grpc);
    void send_data(const Template & data, bool use_grpc);
    void upload_file(const std::vector<uint8_t> & file_data);
    void download_file(const std::string & file_id);
  };
}