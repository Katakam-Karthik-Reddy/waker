#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

#include "utils.h"
#include "uart.h"

uint8_t* convert_number_to_string(int32_t value){
    static uint8_t buff[22];
    uint32_t temp_value = (uint32_t)value;

    uint8_t temp[22];
    size_t index = 0;

    if(value < 0){
        buff[index++] = '-';
        temp_value = -temp_value;
    }

    size_t i = 0;
    while(temp_value > 0){
        temp[i++] = '0' + (temp_value%10);
        temp_value = temp_value/10;
    }

    while(i>0){
        i--;
        buff[index++] = temp[i];
    }
    buff[index++] = '\0';
    return buff;
}


void writef(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);

    while(*fmt){
        if(*fmt != '%'){
            USART1_send_byte((uint32_t)(*fmt++));
            continue;
        }
        fmt++;

        switch(*fmt){
            case 'd':
            case 'i': USART1_send_number(va_arg(args, int));    break;
            case 'u': USART1_send_number(va_arg(args, uint32_t));  break;
            case 'c': USART1_send_byte(va_arg(args, int));     break;
            case 's': USART1_send_string(va_arg(args, const char *));   break;
            case '%': USART1_send_byte('%');     break;
            case '\0': va_end(args);    break;
            default: USART1_send_byte('%'); USART1_send_byte(*fmt);
        }
        fmt++;
    }
    USART1_send_byte('\n');
    va_end(args);
}