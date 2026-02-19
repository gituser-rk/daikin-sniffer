#include "daikin_sniffer.h"
#include "esphome/core/log.h"

namespace daikin_sniffer {

static const char *TAG = "daikin_sniffer";

DaikinSniffer::DaikinSniffer(esphome::uart::UARTComponent *parent)
    : esphome::uart::UARTDevice(parent) {
  raw_frame_sensor_ = new esphome::text_sensor::TextSensor();
  raw_frame_sensor_->set_name("Daikin Raw Frame");
}

void DaikinSniffer::setup() {
  ESP_LOGI(TAG, "Daikin sniffer initialized");
}

void DaikinSniffer::loop() {
  while (available()) {
    uint8_t b = read();
    ESP_LOGD(TAG, "RX: %02X", b);
  }
}

}  // namespace daikin_sniffer
