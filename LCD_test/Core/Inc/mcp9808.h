/*
 * mcp9808.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Dmytro Khamula
 */

#include "main.h"
#include "stm32f4xx_hal.h"

#ifndef INC_MCP9808_H_
#define INC_MCP9808_H_

#define MCP9808_DEFAULT_ADDRESS 0x30

typedef struct {
	  float value;
	  float value_dec;
	  uint8_t temp_reg;
	  uint8_t data[2];
} MCP9808_HandleTypeDef;

float mcp9808_read_temp();
MCP9808_HandleTypeDef mcp9808_init();

#endif // INC_MCP9808_H_
