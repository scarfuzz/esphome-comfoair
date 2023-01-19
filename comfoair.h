#pragma once

#include "esphome.h"
#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/button/button.h"
#include "esphome/components/climate/climate.h"
#include "esphome/components/climate/climate_mode.h"
#include "esphome/components/climate/climate_traits.h"
#include "esphome/components/custom/climate/custom_climate.h"
#include "esphome/components/gpio/switch/gpio_switch.h"

namespace esphome {
namespace comfoair {

static const char *TAG = "comfoair";

static const uint8_t COMFOAIR_MSG_HEAD_LENGTH = 5;
static const uint8_t COMFOAIR_MSG_TAIL_LENGTH = 3;
static const uint8_t COMFOAIR_MSG_PREFIX = 0x07;
static const uint8_t COMFOAIR_MSG_HEAD = 0xf0;
static const uint8_t COMFOAIR_MSG_TAIL = 0x0f;
static const uint8_t COMFOAIR_MSG_ACK = 0xf3;
static const uint8_t COMFOAIR_MSG_IDENTIFIER_IDX = 3;
static const uint8_t COMFOAIR_MSG_DATA_LENGTH_IDX = 4;
static const uint8_t COMFOAIR_MSG_ACK_IDX = 1;

static const uint8_t COMFOAIR_GET_BOOTLOADER_VERSION_REQUEST = 0x67;
static const uint8_t COMFOAIR_GET_BOOTLOADER_VERSION_RESPONSE = 0x68;
static const uint8_t COMFOAIR_GET_BOOTLOADER_VERSION_LENGTH = 13;
static const uint8_t COMFOAIR_GET_FIRMWARE_VERSION_REQUEST = 0x69;
static const uint8_t COMFOAIR_GET_FIRMWARE_VERSION_RESPONSE = 0x6a;
static const uint8_t COMFOAIR_GET_FIRMWARE_VERSION_LENGTH = 13;
static const uint8_t COMFOAIR_GET_BOARD_VERSION_REQUEST = 0xa1;
static const uint8_t COMFOAIR_GET_BOARD_VERSION_RESPONSE = 0xa2;
static const uint8_t COMFOAIR_GET_BOARD_VERSION_LENGTH = 14;

static const uint8_t COMFOAIR_GET_INPUTS_REQUEST = 0x03;
static const uint8_t COMFOAIR_GET_INPUTS_RESPONSE = 0x04;
static const uint8_t COMFOAIR_GET_INPUTS_LENGTH = 0x02;
static const uint8_t COMFOAIR_GET_FAN_STATUS_REQUEST = 0x0b;
static const uint8_t COMFOAIR_GET_FAN_STATUS_RESPONSE = 0x0c;
static const uint8_t COMFOAIR_GET_FAN_STATUS_LENGTH = 0x06;
static const uint8_t COMFOAIR_GET_VALVE_STATUS_REQUEST = 0x0d;
static const uint8_t COMFOAIR_GET_VALVE_STATUS_RESPONSE = 0x0e;
static const uint8_t COMFOAIR_GET_VALVE_STATUS_LENGTH = 0x04;
static const uint8_t COMFOAIR_GET_TEMPERATURE_REQUEST = 0x0f;
static const uint8_t COMFOAIR_GET_TEMPERATURE_RESPONSE = 0x10;
static const uint8_t COMFOAIR_GET_TEMPERATURE_LENGTH = 0x04;
static const uint8_t COMFOAIR_GET_BUTTON_STATUS_REQUEST = 0x11;
static const uint8_t COMFOAIR_GET_BUTTON_STATUS_RESPONSE = 0x12;
static const uint8_t COMFOAIR_GET_BUTTON_STATUS_LENGTH = 0x01;
static const uint8_t COMFOAIR_GET_ANALOG_INPUTS_REQUEST = 0x13;
static const uint8_t COMFOAIR_GET_ANALOG_INPUTS_RESPONSE = 0x14;
static const uint8_t COMFOAIR_GET_ANALOG_INPUTS_LENGTH = 0x04;
static const uint8_t COMFOAIR_GET_SENSOR_DATA_REQUEST = 0x97;
static const uint8_t COMFOAIR_GET_SENSOR_DATA_RESPONSE = 0x98;
static const uint8_t COMFOAIR_GET_SENSOR_DATA_LENGTH = 0x11;
static const uint8_t COMFOAIR_GET_ANALOG_STATUS_REQUEST = 0x9d;
static const uint8_t COMFOAIR_GET_ANALOG_STATUS_RESPONSE = 0x9e;
static const uint8_t COMFOAIR_GET_ANALOG_STATUS_LENGTH = 0x0a;
static const uint8_t COMFOAIR_GET_DELAYS_REQUEST = 0xc9;
static const uint8_t COMFOAIR_GET_DELAYS_RESPONSE = 0xca;
static const uint8_t COMFOAIR_GET_DELAYS_LENGTH = 0x08;
static const uint8_t COMFOAIR_GET_VENTILATION_LEVEL_REQUEST = 0xcd;
static const uint8_t COMFOAIR_GET_VENTILATION_LEVEL_RESPONSE = 0xce;
static const uint8_t COMFOAIR_GET_VENTILATION_LEVEL_LENGTH = 0x0e;
static const uint8_t COMFOAIR_GET_TEMPERATURES_REQUEST = 0xd1;
static const uint8_t COMFOAIR_GET_TEMPERATURES_RESPONSE = 0xd2;
static const uint8_t COMFOAIR_GET_TEMPERATURES_LENGTH = 0x09;
static const uint8_t COMFOAIR_GET_MAIN_STATUS_REQUEST = 0xd5;
static const uint8_t COMFOAIR_GET_MAIN_STATUS_RESPONSE = 0xd6;
static const uint8_t COMFOAIR_GET_MAIN_STATUS_LENGTH = 0x0b;
static const uint8_t COMFOAIR_GET_ERROR_STATE_REQUEST = 0xd9;
static const uint8_t COMFOAIR_GET_ERROR_STATE_RESPONSE = 0xda;
static const uint8_t COMFOAIR_GET_ERROR_STATE_LENGTH = 0x11;
static const uint8_t COMFOAIR_GET_OPERATING_HOURS_REQUEST = 0xdd;
static const uint8_t COMFOAIR_GET_OPERATING_HOURS_RESPONSE = 0xde;
static const uint8_t COMFOAIR_GET_OPERATING_HOURS_LENGTH = 0x14;
static const uint8_t COMFOAIR_GET_BYPASS_CONTROL_REQUEST = 0xdf;
static const uint8_t COMFOAIR_GET_BYPASS_CONTROL_RESPONSE = 0xe0;
static const uint8_t COMFOAIR_GET_BYPASS_CONTROL_LENGTH = 0x07;
static const uint8_t COMFOAIR_GET_PREHEATER_STATUS_REQUEST = 0xe1;
static const uint8_t COMFOAIR_GET_PREHEATER_STATUS_RESPONSE = 0xe2;
static const uint8_t COMFOAIR_GET_PREHEATER_STATUS_LENGTH = 0x06;
static const uint8_t COMFOAIR_GET_RF_STATUS_REQUEST = 0xe5;
static const uint8_t COMFOAIR_GET_RF_STATUS_RESPONSE = 0xe6;
static const uint8_t COMFOAIR_GET_RF_STATUS_LENGTH = 0x07;
static const uint8_t COMFOAIR_GET_LAST_PREHEATING_REQUEST = 0xe9;
static const uint8_t COMFOAIR_GET_LAST_PREHEATING_RESPONSE = 0xea;
static const uint8_t COMFOAIR_GET_LAST_PREHEATING_LENGTH = 0x08;
static const uint8_t COMFOAIR_GET_EWT_REHEATER_REQUEST = 0xeb;
static const uint8_t COMFOAIR_GET_EWT_REHEATER_RESPONSE = 0xec;
static const uint8_t COMFOAIR_GET_EWT_REHEATER_LENGTH = 0x07;

// requests with ACK response
static const uint8_t COMFOAIR_SET_LEVEL_REQUEST = 0x99;
static const uint8_t COMFOAIR_SET_LEVEL_LENGTH = 0x01;
static const uint8_t COMFOAIR_SET_ANALOG_VALUES_REQUEST = 0x9f;
static const uint8_t COMFOAIR_SET_ANALOG_VALUES_LENGTH = 0x13;
static const uint8_t COMFOAIR_SET_DELAYS_REQUEST = 0xcb;
static const uint8_t COMFOAIR_SET_DELAYS_LENGTH = 0x08;
static const uint8_t COMFOAIR_SET_VENTILATION_LEVEL_REQUEST = 0xcf;
static const uint8_t COMFOAIR_SET_VENTILATION_LEVEL_LENGTH = 0x09;
static const uint8_t COMFOAIR_SET_COMFORT_TEMPERATURE_REQUEST = 0xd3;
static const uint8_t COMFOAIR_SET_COMFORT_TEMPERATURE_LENGTH = 0x01;
static const uint8_t COMFOAIR_SET_MAIN_STATUS_REQUEST = 0xd7;
static const uint8_t COMFOAIR_SET_MAIN_STATUS_LENGTH = 0x08;
static const uint8_t COMFOAIR_SET_RESET_REQUEST = 0xdb;
static const uint8_t COMFOAIR_SET_RESET_LENGTH = 0x04;
static const uint8_t COMFOAIR_SET_EWT_REHEATER_REQUEST = 0xed;
static const uint8_t COMFOAIR_SET_EWT_REHEATER_LENGTH = 0x05;
static const uint8_t COMFOAIR_SET_RS232_MODE_REQUEST = 0x9b;
static const uint8_t COMFOAIR_SET_RS232_MODE_RESPONSE = 0x9c;
static const uint8_t COMFOAIR_SET_RS232_MODE_LENGTH = 0x01;

// Specials setters
static const uint8_t COMFOAIR_SET_TEST_MODE_START_REQUEST = 0x01;
static const uint8_t COMFOAIR_SET_TEST_MODE_END_REQUEST = 0x19;
static const uint8_t COMFOAIR_SET_OUTPUTS_REQUEST = 0x05;
static const uint8_t COMFOAIR_SET_ANALOG_OUTPUTS_REQUEST = 0x07;
static const uint8_t COMFOAIR_SET_VALVES_REQUEST = 0x09;

static const uint8_t COMFOAIR_MIN_SUPPORTED_TEMP = 12;
static const uint8_t COMFOAIR_MAX_SUPPORTED_TEMP = 29;
static const float COMFOAIR_SUPPORTED_TEMP_STEP = 0.5f;

class ResetFilterButton;

class ComfoAirComponent : public climate::Climate, PollingComponent, uart::UARTDevice {
 public:

  ComfoAirComponent(UARTComponent *uart_comfoair, UARTComponent *uart_proxy, gpio::GPIOSwitch* green_led, gpio::GPIOSwitch* blue_led, gpio::GPIOSwitch* red_led) : Climate("comfoair"), PollingComponent(2000), uart_comfoair_(uart_comfoair), uart_proxy_(uart_proxy), green_led_(green_led), blue_led_(blue_led), red_led_(red_led) {}

  /// Return the traits of this controller.
  climate::ClimateTraits traits() override {
    auto traits = climate::ClimateTraits();
    traits.set_supports_current_temperature(true);
    traits.set_visual_min_temperature(COMFOAIR_MIN_SUPPORTED_TEMP);
    traits.set_visual_max_temperature(COMFOAIR_MAX_SUPPORTED_TEMP);
    traits.set_visual_temperature_step(COMFOAIR_SUPPORTED_TEMP_STEP);
    traits.set_supported_fan_modes({
      climate::CLIMATE_FAN_AUTO,
      climate::CLIMATE_FAN_LOW,
      climate::CLIMATE_FAN_MEDIUM,
      climate::CLIMATE_FAN_HIGH,
      climate::CLIMATE_FAN_OFF,
    }); 
    return traits;
  }

  /// Override control to change settings of the climate device.
  void control(const climate::ClimateCall &call) override {
    if (call.get_fan_mode().has_value()) {
      int level;

      fan_mode = *call.get_fan_mode();
      switch (fan_mode.value()) {
        case climate::CLIMATE_FAN_HIGH:
          level = 0x04;
          break;
        case climate::CLIMATE_FAN_MEDIUM:
          level = 0x03;
          break;
        case climate::CLIMATE_FAN_LOW:
          level = 0x02;
          break;
        case climate::CLIMATE_FAN_OFF:
          level = 0x01;
          break;
        case climate::CLIMATE_FAN_AUTO:
          level = 0x00;
          break;
        case climate::CLIMATE_FAN_FOCUS:
        case climate::CLIMATE_FAN_ON:
        case climate::CLIMATE_FAN_MIDDLE:
        case climate::CLIMATE_FAN_DIFFUSE:
        default:
          level = -1;
          break;
      }

      if (level >= 0) {
        set_level_(level);
      }

    }
    if (call.get_target_temperature().has_value()) {
      target_temperature = *call.get_target_temperature();
      set_comfort_temperature_(target_temperature);
    }

    publish_state();
  }

  void dump_config() override {
    uint8_t *p;
    ESP_LOGCONFIG(TAG, "ComfoAir:");
    LOG_UPDATE_INTERVAL(this);
    p = bootloader_version_;
    ESP_LOGCONFIG(TAG, "  Bootloader %.10s v%0d.%02d b%2d", p + 3, *p, *(p + 1), *(p + 2));
    p = firmware_version_;
    ESP_LOGCONFIG(TAG, "  Firmware %.10s v%0d.%02d b%2d", p + 3, *p, *(p + 1), *(p + 2));
    p = connector_board_version_;
    ESP_LOGCONFIG(TAG, "  Connector Board %.10s v%0d.%02d", p + 2, *p, *(p + 1));

    if (*(p + 12) != 0) {
      ESP_LOGCONFIG(TAG, "  CC-Ease v%0d.%02d", *(p + 12) >> 4, *(p + 12) & 0x0f);
    }
    if (*(p + 13) != 0) {
      ESP_LOGCONFIG(TAG, "  CC-Luxe v%0d.%02d", *(p + 13) >> 4, *(p + 13) & 0x0f);
    }

    //uart_comfoair_->check_uart_settings(9600);
    //uart_proxy_->check_uart_settings(9600);
  }

  void update() override {
    switch(update_counter_) {
      case -4:
        set_rs232_mode(3);
        break;
      case -3:
        write_command_(COMFOAIR_GET_BOOTLOADER_VERSION_REQUEST, nullptr, 0);
        break;
      case -2:
        write_command_(COMFOAIR_GET_FIRMWARE_VERSION_REQUEST, nullptr, 0);
        break;
      case -1:
        write_command_(COMFOAIR_GET_BOARD_VERSION_REQUEST, nullptr, 0);
        break;
      case 0:
        get_fan_status_();
        break;
      case 1:
        get_valve_status_();
        break;
      case 2:
        get_sensor_data_();
        break;
      case 3:
        get_ventilation_level_();
        break;
      case 4:
        get_temperatures_();
        break;
      case 5:
        get_error_status_();
        break;
      case 6:
        get_bypass_control_status_();
        break;
    }

    update_counter_++;
    if (update_counter_ > 6)
      update_counter_ = 0;
  }

  void loop() override {
    // Proxy commands from the display.
    while(uart_proxy_->available() != 0) {
      uart_proxy_->read_byte(&proxy_data_[proxy_data_index_]);
      auto check = check_byte_(proxy_data_, proxy_data_index_);
      if (!check.has_value()) {
        ESP_LOGV(TAG, "Proxying command 0x%02X from confosense with %i bytes.", proxy_data_[COMFOAIR_MSG_IDENTIFIER_IDX], proxy_data_index_+1);
        uart_comfoair_->write_array(proxy_data_, proxy_data_index_+1);
        uart_comfoair_->flush();
        proxy_data_index_ = 0;
        break;
      } else if (!*check) {
        // wrong data
        ESP_LOGV(TAG, "Byte %i of received data frame is invalid.", proxy_data_index_);
        proxy_data_index_ = 0;
      } else {
        proxy_data_index_++;
      }
    }

    while (uart_comfoair_->available() != 0) {
      uart_comfoair_->read_byte(&data_[data_index_]);
      auto check = check_byte_(data_, data_index_);
      if (!check.has_value()) {

        // finished
        ESP_LOGV(TAG, "Response 0x%02X from confosense with %i bytes.", data_[COMFOAIR_MSG_IDENTIFIER_IDX], data_index_+1);
        if (data_[COMFOAIR_MSG_ACK_IDX] != COMFOAIR_MSG_ACK) {
          parse_data_();
        }
        // Proxy result to the display.
        uart_proxy_->write_array(data_, data_index_+1);
        uart_proxy_->flush();
        data_index_ = 0;
      } else if (!*check) {
        // wrong data
        ESP_LOGV(TAG, "Byte %i of received data frame is invalid.", data_index_);
        data_index_ = 0;
      } else {
        // next byte
        data_index_++;
      }
    }
  }

  float get_setup_priority() const override { return setup_priority::DATA; }

  void reset_filter(void) {
    uint8_t reset_cmd[COMFOAIR_SET_RESET_LENGTH] = {0, 0, 0, 1};
    write_command_(COMFOAIR_SET_RESET_REQUEST, reset_cmd, sizeof(reset_cmd));
  }

 protected:

  void set_level_(int level) {
    if (level < 0 || level > 5) {
      ESP_LOGI(TAG, "Ignoring invalid level request: %i", level);
      return;
    }

    ESP_LOGI(TAG, "Setting level to: %i", level);
    uint8_t command[COMFOAIR_SET_LEVEL_LENGTH] = {(uint8_t) level};
    write_command_(COMFOAIR_SET_LEVEL_REQUEST, command, sizeof(command));
  }

  void set_comfort_temperature_(float temperature) {
    if (temperature < COMFOAIR_MIN_SUPPORTED_TEMP || 
        temperature > COMFOAIR_MAX_SUPPORTED_TEMP) {
      ESP_LOGI(TAG, "Ignoring invalid temperature request: %i", temperature);
      return;
    }

    ESP_LOGI(TAG, "Setting temperature to: %i", temperature);
    uint8_t command[COMFOAIR_SET_COMFORT_TEMPERATURE_LENGTH] = {(uint8_t) ((temperature + 20.0f) * 2.0f)};
    write_command_(COMFOAIR_SET_COMFORT_TEMPERATURE_REQUEST, command, sizeof(command));
  }
  
  void set_rs232_mode(int mode) {
    if (mode < 0 || mode > 4) {
      ESP_LOGI(TAG, "Ignoring invalid mode request: %i", mode);
      return;
    }

    ESP_LOGI(TAG, "Setting rs232 mode to: %i", mode);
    uint8_t command[] = {(uint8_t) mode};
    write_command_(COMFOAIR_SET_RS232_MODE_REQUEST, command, sizeof(command));
  }

  void write_command_(const uint8_t command, const uint8_t *command_data, uint8_t command_data_length) {
    uart_comfoair_->write_byte(COMFOAIR_MSG_PREFIX);
    uart_comfoair_->write_byte(COMFOAIR_MSG_HEAD);
    uart_comfoair_->write_byte(0x00);
    uart_comfoair_->write_byte(command);
    uart_comfoair_->write_byte(command_data_length);
    if (command_data_length > 0) {
      uart_comfoair_->write_array(command_data, command_data_length);
      uart_comfoair_->write_byte((command + command_data_length + comfoair_checksum_(command_data, command_data_length)) & 0xff);
    } else {
      uart_comfoair_->write_byte(comfoair_checksum_(&command, 1));
    }
    uart_comfoair_->write_byte(COMFOAIR_MSG_PREFIX);
    uart_comfoair_->write_byte(COMFOAIR_MSG_TAIL);
    uart_comfoair_->flush();
  }

  uint8_t comfoair_checksum_(const uint8_t *command_data, uint8_t length) const {
    uint8_t sum = 0;
    bool last_seven = false;
    for (uint8_t i = 0; i < length; i++) {
      if (command_data[i] == 0x07) {
        if (last_seven) {
          last_seven = false;
          continue;
        }
        last_seven = true;
      }
      sum += command_data[i];
    }
    return sum + 0xad;
  }

  optional<bool> check_byte_(uint8_t* data, uint8_t index) const {
    const uint8_t byte = data[index];

    if (index == 0)
      return byte == COMFOAIR_MSG_PREFIX;

    if (index == 1) {
      if (byte == COMFOAIR_MSG_ACK)
        return {};
      else
        return byte == COMFOAIR_MSG_HEAD;
    }

    if (index == 2)
      return byte == 0x00;

    if (index < COMFOAIR_MSG_HEAD_LENGTH)
      return true;

    uint8_t data_length = data[COMFOAIR_MSG_DATA_LENGTH_IDX];

    if ((COMFOAIR_MSG_HEAD_LENGTH + data_length + COMFOAIR_MSG_TAIL_LENGTH) > sizeof(data_)) {
      ESP_LOGW(TAG, "ComfoAir message too large");
      return false;
    }

    if (index < COMFOAIR_MSG_HEAD_LENGTH + data_length)
      return true;

    if (index == COMFOAIR_MSG_HEAD_LENGTH + data_length) {
      // checksum is without checksum bytes
      uint8_t checksum = comfoair_checksum_(data + 2, COMFOAIR_MSG_HEAD_LENGTH + data_length - 2);
      if (checksum != byte) {
        //ESP_LOG_BUFFER_HEX(TAG, data_, index+1);
        ESP_LOGW(TAG, "ComfoAir Checksum doesn't match: 0x%02X!=0x%02X", byte, checksum);
        return false;
      }
      return true;
    }

    if (index == COMFOAIR_MSG_HEAD_LENGTH + data_length + 1)
      return byte == COMFOAIR_MSG_PREFIX;

    if (index == COMFOAIR_MSG_HEAD_LENGTH + data_length + 2) {
      if (byte != COMFOAIR_MSG_TAIL)
        return false;
    }

    return {};
  }

  void parse_data_() {
    status_clear_warning();
    uint8_t *msg = &data_[COMFOAIR_MSG_HEAD_LENGTH];

    switch (data_[COMFOAIR_MSG_IDENTIFIER_IDX]) {
      case COMFOAIR_GET_BOOTLOADER_VERSION_RESPONSE:
        memcpy(bootloader_version_, msg, data_[COMFOAIR_MSG_DATA_LENGTH_IDX]);
        break;
      case COMFOAIR_GET_FIRMWARE_VERSION_RESPONSE:
        memcpy(firmware_version_, msg, data_[COMFOAIR_MSG_DATA_LENGTH_IDX]);
        break;
      case COMFOAIR_GET_BOARD_VERSION_RESPONSE:
        memcpy(connector_board_version_, msg, data_[COMFOAIR_MSG_DATA_LENGTH_IDX]);
        break;
      case COMFOAIR_GET_FAN_STATUS_RESPONSE: {
          if (fan_supply_air_percentage != nullptr) {
            fan_supply_air_percentage->publish_state(msg[0]);
          }
          if (fan_exhaust_air_percentage != nullptr) {
            fan_exhaust_air_percentage->publish_state(msg[1]);
          }
          if (fan_speed_supply != nullptr) {
            fan_speed_supply->publish_state(1875000.0f / get_uint16_(2));
          }
          if (fan_speed_exhaust != nullptr) {
            fan_speed_exhaust->publish_state(1875000.0f / get_uint16_(4));
          }
          break;
        }
      case COMFOAIR_GET_VALVE_STATUS_RESPONSE: {
        if (is_bypass_valve_open != nullptr) {
          is_bypass_valve_open->publish_state(msg[0] != 0);
        }
        if (is_preheating != nullptr) {
            is_preheating->publish_state(msg[1] != 0);
        }
        break;
      }
      case COMFOAIR_GET_BYPASS_CONTROL_RESPONSE: {
        if (bypass_factor != nullptr) {
          bypass_factor->publish_state(msg[2]);
        }
        if (bypass_step != nullptr) {
          bypass_step->publish_state(msg[3]);
        }
        if (bypass_correction != nullptr) {
          bypass_correction->publish_state(msg[4]);
        }
        if (is_summer_mode != nullptr) {
          is_summer_mode->publish_state(msg[6] != 0);
        }
        break;
      }
      case COMFOAIR_GET_TEMPERATURE_RESPONSE: {

        // T1 / outside air
        if (outside_air_temperature != nullptr) {
          outside_air_temperature->publish_state((float) msg[0] / 2.0f - 20.0f);
        }
        // T2 / supply air
        if (supply_air_temperature != nullptr) {
          supply_air_temperature->publish_state((float) msg[1] / 2.0f - 20.0f);
        }
        // T3 / return air
        if (return_air_temperature != nullptr) {
          return_air_temperature->publish_state((float) msg[2] / 2.0f - 20.0f);
        }
        // T4 / exhaust air
        if (exhaust_air_temperature != nullptr) {
          exhaust_air_temperature->publish_state((float) msg[3] / 2.0f - 20.0f);
        }
        break;
      }
      case COMFOAIR_GET_SENSOR_DATA_RESPONSE: {

        if (enthalpy_temperature != nullptr) {
          enthalpy_temperature->publish_state((float) msg[0] / 2.0f - 20.0f);
        }

        break;
      }
      case COMFOAIR_GET_VENTILATION_LEVEL_RESPONSE: {

        ESP_LOGD(TAG, "Level %02x", msg[8]);

        if (return_air_level != nullptr) {
          return_air_level->publish_state(msg[6]);
        }
        if (supply_air_level != nullptr) {
          supply_air_level->publish_state(msg[7]);
        }

        // Fan Speed
        switch(msg[8]) {
          case 0x00:
            fan_mode = climate::CLIMATE_FAN_AUTO;
            mode = climate::CLIMATE_MODE_AUTO;
            green_led_->turn_on();
            red_led_->turn_on();
            break;
          case 0x01:
            fan_mode = climate::CLIMATE_FAN_OFF;
            mode = climate::CLIMATE_MODE_OFF;
            green_led_->turn_off();
            red_led_->turn_off();
            break;
          case 0x02:
            fan_mode = climate::CLIMATE_FAN_LOW;
            mode = climate::CLIMATE_MODE_FAN_ONLY;
            green_led_->turn_on();
            red_led_->turn_off();
            break;
          case 0x03:
            fan_mode = climate::CLIMATE_FAN_MEDIUM;
            mode = climate::CLIMATE_MODE_FAN_ONLY;
            green_led_->turn_off();
            red_led_->turn_on();
          break;
          case 0x04:
            fan_mode = climate::CLIMATE_FAN_HIGH;
            mode = climate::CLIMATE_MODE_FAN_ONLY;
            green_led_->turn_off();
            red_led_->turn_on();
            break;
        }

        publish_state();

        // Supply air fan active (1 = active / 0 = inactive)
        if (is_supply_fan_active != nullptr) {
          is_supply_fan_active->publish_state(msg[9] == 1);
        }
        break;
      }
      case COMFOAIR_GET_ERROR_STATE_RESPONSE: {
        if (is_filter_full != nullptr) {
          if(is_filter_full->state != (msg[8] != 0)) {
            if (msg[8] != 0)
              blue_led_->turn_on();
            else
              blue_led_->turn_off();
          }
          is_filter_full->publish_state(msg[8] != 0);
        }
        break;
      }
      case COMFOAIR_GET_TEMPERATURES_RESPONSE: {

        // comfort temperature
        target_temperature = (float) msg[0] / 2.0f - 20.0f;
        current_temperature = (float) msg[2] / 2.0f - 20.0f;
        publish_state();

        // T1 / outside air
        if (outside_air_temperature != nullptr && msg[5] & 0x01) {
          outside_air_temperature->publish_state((float) msg[1] / 2.0f - 20.0f);
        }
        // T2 / supply air
        if (supply_air_temperature != nullptr && msg[5] & 0x02) {
          supply_air_temperature->publish_state((float) msg[2] / 2.0f - 20.0f);
        }
        // T3 / exhaust air
        if (return_air_temperature != nullptr && msg[5] & 0x04) {
          return_air_temperature->publish_state((float) msg[3] / 2.0f - 20.0f);
        }
        // T4 / continued air
        if (exhaust_air_temperature != nullptr && msg[5] & 0x08) {
          exhaust_air_temperature->publish_state((float) msg[4] / 2.0f - 20.0f);
        }
        // EWT
        if (ewt_temperature != nullptr && msg[5] & 0x10) {
          ewt_temperature->publish_state((float) msg[6] / 2.0f - 20.0f);
        }
        // reheating
        if (reheating_temperature != nullptr && msg[5] & 0x20) {
          reheating_temperature->publish_state((float) msg[7] / 2.0f - 20.0f);
        }
        // kitchen hood
        if (kitchen_hood_temperature != nullptr && msg[5] & 0x40) {
          kitchen_hood_temperature->publish_state((float) msg[8] / 2.0f - 20.0f);
        }

        break;
      }
    }
  }

  void get_fan_status_() {
    if (fan_supply_air_percentage != nullptr ||
        fan_exhaust_air_percentage != nullptr ||
        fan_speed_supply != nullptr ||
        fan_speed_exhaust != nullptr) {
      ESP_LOGD(TAG, "getting fan status");
      write_command_(COMFOAIR_GET_FAN_STATUS_REQUEST, nullptr, 0);
    }
  }

  void get_valve_status_() {
    if (is_bypass_valve_open != nullptr ||
        is_preheating != nullptr) {
      ESP_LOGD(TAG, "getting valve status");
      write_command_(COMFOAIR_GET_VALVE_STATUS_REQUEST, nullptr, 0);
    }
  }

  void get_error_status_() {
    if (is_filter_full != nullptr) {
      ESP_LOGD(TAG, "getting error status");
      write_command_(COMFOAIR_GET_ERROR_STATE_REQUEST, nullptr, 0);
    }
  }

  void get_bypass_control_status_() {
    if (bypass_factor != nullptr ||
       bypass_step != nullptr ||
       bypass_correction != nullptr ||
       is_summer_mode != nullptr) {
      ESP_LOGD(TAG, "getting bypass control");
      write_command_(COMFOAIR_GET_BYPASS_CONTROL_REQUEST, nullptr, 0);
    }
  }

  void get_temperature_() {
    if (outside_air_temperature != nullptr ||
       supply_air_temperature != nullptr ||
       return_air_temperature != nullptr ||
       outside_air_temperature != nullptr) {
      ESP_LOGD(TAG, "getting temperature");
      write_command_(COMFOAIR_GET_TEMPERATURE_REQUEST, nullptr, 0);
    }
  }

  void get_sensor_data_() {
    if (enthalpy_temperature != nullptr) {
      ESP_LOGD(TAG, "getting sensor data");
      write_command_(COMFOAIR_GET_SENSOR_DATA_REQUEST, nullptr, 0);
    }
  }

  void get_ventilation_level_() {
    ESP_LOGD(TAG, "getting ventilation level");
    write_command_(COMFOAIR_GET_VENTILATION_LEVEL_REQUEST, nullptr, 0);
  }

  void get_temperatures_() {
    ESP_LOGD(TAG, "getting temperatures");
    write_command_(COMFOAIR_GET_TEMPERATURES_REQUEST, nullptr, 0);
  }

  uint8_t get_uint8_t_(uint8_t start_index) const {
    return data_[COMFOAIR_MSG_HEAD_LENGTH + start_index];
  }

  uint16_t get_uint16_(uint8_t start_index) const {
    return (uint16_t(data_[COMFOAIR_MSG_HEAD_LENGTH + start_index + 1] | data_[COMFOAIR_MSG_HEAD_LENGTH + start_index] << 8));
  }

  uint8_t data_[30];
  uint8_t data_index_{0};
  uint8_t proxy_data_[30];
  uint8_t proxy_data_index_{0};
  
  int8_t update_counter_{-4};

  uint8_t bootloader_version_[13]{0};
  uint8_t firmware_version_[13]{0};
  uint8_t connector_board_version_[14]{0};
  
  UARTComponent* uart_comfoair_;
  UARTComponent* uart_proxy_;
  gpio::GPIOSwitch* green_led_;
  gpio::GPIOSwitch* blue_led_;
  gpio::GPIOSwitch* red_led_;
  
public:
  sensor::Sensor *fan_supply_air_percentage{nullptr};
  sensor::Sensor *fan_exhaust_air_percentage{nullptr};
  sensor::Sensor *fan_speed_supply{nullptr};
  sensor::Sensor *fan_speed_exhaust{nullptr};
  binary_sensor::BinarySensor *is_bypass_valve_open{nullptr};
  binary_sensor::BinarySensor *is_preheating{nullptr};
  sensor::Sensor *outside_air_temperature{nullptr};
  sensor::Sensor *supply_air_temperature{nullptr};
  sensor::Sensor *return_air_temperature{nullptr};
  sensor::Sensor *exhaust_air_temperature{nullptr};
  sensor::Sensor *enthalpy_temperature{nullptr};
  sensor::Sensor *ewt_temperature{nullptr};
  sensor::Sensor *reheating_temperature{nullptr};
  sensor::Sensor *kitchen_hood_temperature{nullptr};
  sensor::Sensor *return_air_level{nullptr};
  sensor::Sensor *supply_air_level{nullptr};
  binary_sensor::BinarySensor *is_supply_fan_active{nullptr};
  binary_sensor::BinarySensor *is_filter_full{nullptr};
  sensor::Sensor *bypass_factor{nullptr};
  sensor::Sensor *bypass_step{nullptr};
  sensor::Sensor *bypass_correction{nullptr};
  binary_sensor::BinarySensor *is_summer_mode{nullptr};
  ResetFilterButton *reset_filter_button{nullptr};
};

class ResetFilterButton : public button::Button {
  public:
    ResetFilterButton(const std::string& name, ComfoAirComponent* comfoair) : button::Button(name), comfoair_(comfoair) {}
    
  protected:
    void press_action() override {
      comfoair_->reset_filter();
    }
  private:
    ComfoAirComponent* comfoair_;  
};

}  // namespace comfoair
}  // namespace esphome