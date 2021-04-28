/*
 * Version 
 * Author: WildfootW
 * GitHub: github.com/WildfootW
 * Copyleft (C) 2020 WildfootW all rights reversed
 *
 */

/*
in main:
sei();
adconverter.start()
ISR(ADC_vect)
{
    adconverter.get_value();
    adconverter.clear_interrupt_flag();
    adconverter.select_input_channel(0b00000101);
    adconverter.start();
}
*/
// choose channels in switch case
/*
ISR(ADC_vect)
{
    ADConverterMUX current_mux = ad_converter.get_mux();
    switch(current_mux)
    {
        case ADConverterMUX::ADC0:
            sensor_o_c.value_update(ad_converter.get_value());
            ad_converter.select_input_channel(ADConverterMUX::ADC1);
            break;
        case ADConverterMUX::ADC1:
            sensor_l.value_update(ad_converter.get_value());
            ad_converter.select_input_channel(ADConverterMUX::ADC2);
            break;
        default:
            break;
    }
    ad_converter.clear_interrupt_flag();
    ad_converter.start();
}
*/

#ifndef ADCONVERTER_HPP
#define ADCONVERTER_HPP

#include <avr/io.h>

enum class ADConverterMUX: uint8_t
{
    ADC0 = 0,
    ADC1 = 1,
    ADC2 = 2,
    ADC3 = 3,
    ADC4 = 4,
    ADC5 = 5,
    ADC6 = 6,
    ADC7 = 7
};
class ADConverter
{
public:
    ADConverter(){}
    void initial();

    // set which pin to use
    void select_input_channel(ADConverterMUX mux);
    void clear_interrupt_flag();
    void start();
    uint16_t get_value();
    ADConverterMUX get_mux();
};

#endif //ADCONVERTER_HPP
