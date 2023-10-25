/*
 * mcp9808.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Dmytro Khamula
 */

#include "mcp9808.h"
extern I2C_HandleTypeDef hi2c2;

MCP9808_HandleTypeDef mcp9808_init(){
	MCP9808_HandleTypeDef mcp9808;
	mcp9808.value = 0;
	mcp9808.temp_reg = 0x05u;
	mcp9808.value_dec = 0.0625;
	return mcp9808;
}

float mcp9808_read_temp(MCP9808_HandleTypeDef *mcp9808){
	  HAL_I2C_Master_Transmit(&hi2c2, MCP9808_DEFAULT_ADDRESS, &mcp9808->temp_reg, 1, 2000);
	  HAL_I2C_Master_Receive(&hi2c2, MCP9808_DEFAULT_ADDRESS | 0x01, mcp9808->data, 2, 2000);
	  for (int i = 0; i < 8; i++){
		  mcp9808->value += ((mcp9808->data[1] >> i) & 0x00000001) * mcp9808->value_dec;
		  mcp9808->value_dec *= 2u;
	  }
	  for (int i = 0; i < 4; i++){
		  mcp9808->value += ((mcp9808->data[0] >> i) & 0x00000001) * mcp9808->value_dec;
		  mcp9808->value_dec *= 2u;
	  }
	  return mcp9808->value;
	}

