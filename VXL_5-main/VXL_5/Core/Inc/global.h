/*
 * global.h
 *
 *  Created on: 28 Nov 2024
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

int command_flag;
char command_data[];
uint8_t temp;

char buffer[];
uint8_t index_buffer;
uint8_t buffer_flag;

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

uint8_t read_adc_flag;
uint8_t ok_flag;

#endif /* INC_GLOBAL_H_ */
