#include "mbed.h"
#include "MCP4561.h"
#define WIPER_0_VOLATILE 00								//MCP4561, MCP4562 exactly (IT IS WORK IN MY PROJECT)
#define WIPER_1_VOLATILE 01								//  (Dual Resistor Network devices only)
#define WIPER_0_NON_VOLATILE 02
#define WIPER_1_NON_VOLATILE 03

DigitalOut g_LED(LED1);									 // For Toggle 
Serial pc(USBTX, USBRX); // tx, rx
MCP4561 digiPot(46<< 1);								//declare an instance of MAX4561 with Device addr 46 ( 0101 1100 ), A0 pulled to LOW 
														//if A0 pulled to HIGH Device addr is 47


int main() 
{
	uint16_t setOutput=1;								//Variable to set resistance
	//uint16_t read;
	while (1)
	{
			digiPot.write(WIPER_0_VOLATILE, setOutput); //  method/function to set resistance
			uint16_t x=digiPot.read(00);				//  method/function to read resistance
			pc.printf("Resistance= %d \r\n", x);		// print to USB Serial
			//Toggle show circuit work
			g_LED = 1;
			wait_ms(500);
			g_LED = 0;
			wait_ms(500);
	}
}

