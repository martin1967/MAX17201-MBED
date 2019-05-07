/**
 * Name: max1720x
 * Author: Luka Mustafa - Institute IRNAS Race { info@irnas.eu }
 * Version: 1.0
 * Description: A library for interfacing the MAXIM MAX17201/MAX17205
 * 				Li+ fuel gauges.
 * Source: https://github.com/pAIgn10/LiFuelGauge
 * License: Copyright (c) 2017 Nick Lamprianidis 
 *          This library is licensed under the GPL license
 *          http://www.opensource.org/licenses/mit-license.php
 * Inspiration: The library is inspired by: https://github.com/pAIgn10/LiFuelGauge
 * Filename: max1720x.h
 * File description: Definitions and methods for the max1720x library
 */



#include <mbed.h>

// Class for interfacing the MAX1720X Li+ fuel gauges
class max1720x
{
public:
	max1720x(int dev_address);
	float getVoltage();
	float getSOC();
	float getTemperature();
	uint16_t getTime();
	uint16_t getTimeH();
	float getCurrent();
	float getCapacity();
	float getCapacity_coulomb();
	float getTTE();
	float getTTF();
    uint8_t  reset();
	uint8_t HWreset();
	uint16_t read(char dev_ADDR);
	uint16_t write(char dev_ADDR, char comand);
	void init();
	uint16_t write2b(char mem_adr, uint16_t comand);
	uint16_t getStatus();
private:
    	
	char dev_ADDR = 0x36;
};


