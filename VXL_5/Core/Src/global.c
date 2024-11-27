/*
 * global.c
 *
 *  Created on: 28 Nov 2024
 *      Author: PC
 */

#include "global.h"

uint8_t read_adc_flag = 0;
uint8_t ok_flag = 0;

int command_flag = 0;
char command_data[20] = "";
uint8_t temp = 0;

# define MAX_BUFFER_SIZE 30

char buffer [MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
