
#pragma once
#include "esphome.h"

class DaikinSniffer : public esphome::Component, public esphome::uart::UARTDevice {
 public:
  esphome::text_sensor::TextSensor *sensor = new esphome::text_sensor::TextSensor();

  DaikinSniffer(esphome::uart::UARTComponent *parent);

  void loop() override;

 private:
  std::vector<uint8_t> buffer;
};

