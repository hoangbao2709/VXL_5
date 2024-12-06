/*
 * uart_communiation_fsm.c
 *
 *  Created on: 28 Nov 2024
 *      Author: PC
 */

#include "uart_communiation_fsm.h"
#include "software_timer.h"
#include "main.h"
#include <stdio.h>
#include <string.h>

#define INIT        0
#define READ_ADC    1
#define SHOW_ADC    2

uint32_t adc_value = 0;

void uart_communiation_fsm() {
    switch (read_adc_flag) {
        case 1:
            HAL_ADC_PollForConversion(&hadc1, 1000);
            adc_value = HAL_ADC_GetValue(&hadc1);
            uint8_t adc_str[20];
            sprintf((char*)adc_str, "!%lu#\r\n", adc_value);
            read_adc_flag = 3;
            break;
        case 2:
            read_adc_flag = 0;
            break;
        case 3:
            HAL_Delay(3000);
            int i = index_buffer - 1;
            if (i >= 3 && buffer[i] == '#' &&
				buffer[i - 1] == 'K' &&
				buffer[i - 2] == 'O' &&
				buffer[i - 3] == '!') {
			}else
				HAL_UART_Transmit(&huart2, adc_str, strlen((char*)adc_str), 1000);
        	break;
        default:
            break;
    }
}
