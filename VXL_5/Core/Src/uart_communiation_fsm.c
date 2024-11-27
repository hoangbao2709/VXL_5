/*
 * uart_communiation_fsm.c
 *
 *  Created on: 28 Nov 2024
 *      Author: PC
 */

#include "uart_communiation_fsm.h"
#include "software_timer.h"
#include "main.h" // Để truy cập vào hadc1 và huart2
#include <stdio.h> // Để sử dụng sprintf
#include <string.h> // Để sử dụng strlen

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
            HAL_UART_Transmit(&huart2, adc_str, strlen((char*)adc_str), 1000);
            read_adc_flag = 0;
            break;

        case 2:
            HAL_ADC_PollForConversion(&hadc1, 1000);
            adc_value = HAL_ADC_GetValue(&hadc1);
            sprintf((char*)adc_str, "!%lu#\r\n", adc_value);
            HAL_Delay(3000);
			HAL_UART_Transmit(&huart2, adc_str, strlen((char*)adc_str), 1000);
            read_adc_flag = 0;
            break;

        default:
            break;
    }
}