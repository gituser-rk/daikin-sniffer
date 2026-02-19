#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace daikin_sniffer {

class DaikinSniffer : public esphome::Component, public esphome::uart::UARTDevice {
 public:
  DaikinSniffer(esphome::uart::UARTComponent *parent);

  void setup() override;
  void loop() override;

 protected:
  esphome::text_sensor::TextSensor *raw_frame_sensor_;
};

}  // namespace daikin_sniffer
