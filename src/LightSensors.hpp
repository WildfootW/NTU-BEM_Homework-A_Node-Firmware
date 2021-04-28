/*
 * Version
 * Author: WildfootW
 * GitHub: github.com/WildfootW
 * Copyleft (C) 2019-2020 WildfootW all rights reversed
 *
 */

#ifndef LIGHTSENSORS_H
#define LIGHTSENSORS_H

#include <stdint.h>
#include "avr-utils/BasicSensor.hpp"

class LightSensorP8103: public BasicSensor
{
public:
    LightSensorP8103(){}
    uint16_t get_value(){ return mix_value; }
//    void initial(uint16_t divide, bool less_than = false);
//    void value_update(uint8_t input_value);
//    bool target_detected() const;
//    unsigned long get_last_change_status_time() const;
private:
//    bool current_status;
//    bool value_less_than;
//    uint16_t divide_value;
//    unsigned long last_change_status_time;
};

#endif //LIGHTSENSORS_H
