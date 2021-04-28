/*
 * main.cpp
 * Author: WildfootW
 * GitHub: github.com/WildfootW
 * Copyleft (ɔ) 2020-2021 WildfootW all rights reversed
 */

#include <avr/interrupt.h>
#include "avr-utils/IOPin.hpp"

#include "avr-utils/USART.hpp"
USART<115200> usart;

#include "avr-utils/ADConverter.hpp"
ADConverter ad_converter; // ADC6

#include "LightSensors.hpp"
LightSensorP8103 sensor_light;

void initial()
{
    CLKPR = (1 << CLKPCE); // clock prescaler change enable
  //CLKPR = 0b00000100; // set clk to  1 Mhz (16 / 16)
    CLKPR = 0b00000000; // set clk to 16 Mhz (16 / 1)

    sei();
    ad_converter.initial();
    ad_converter.select_input_channel(ADConverterMUX::ADC6);
//    pin_PC1::configure_pin_mode(AVRIOPinMode::Input);


    usart.initial();
}

int main(void)
{
    initial();

    while(true)
    {
        uint16_t sensor_light_value = sensor_light.get_value();
        usart.put_uint16(sensor_light_value);
//        char str[] = "WildfootW\n";
//        usart.put_str(str);
        usart.put_char('\n');
    }
}

ISR(ADC_vect)
{
//    ADConverterMUX current_mux = ad_converter.get_mux();
    sensor_light.value_update(ad_converter.get_value());
//    ad_converter.select_input_channel(ADConverterMUX::ADC1);
    ad_converter.clear_interrupt_flag();
    ad_converter.start();
}
