/*
 * Author: WildfootW
 * GitHub: github.com/WildfootW
 * Copyleft (C) 2020-2021 WildfootW all rights reversed
 *
 */


#ifndef USART_HPP
#define USART_HPP

#include <stdint.h>

template <uint32_t baud_rate>
class USART
{
public:
    USART(){}
    void initial();
    void put_char(char c);
    void put_str(char* str_ptr);
    void put_uint16(const uint16_t& num);
private:
};

#endif //USART_HPP

#include "USART.cpp"

//template class USART<115200>; // These Make Program Bigger
//template class USART<9600>;

