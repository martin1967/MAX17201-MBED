#include <mbed.h>
#include "max1720x.h"
const int MAX1720X_ADDR = 0x36;
DigitalOut g_LED(LED4);
max1720x FuelGauge( MAX1720X_ADDR << 1);

int main() 
{
	FuelGauge.HWreset();
	wait(0.5);
	FuelGauge.init();
	uint16_t reset = FuelGauge.reset();
	
	wait(0.5);
	for (;;)
	{
		float t = FuelGauge.getTemperature();
		float c = FuelGauge.getCapacity();
		float colu = FuelGauge.getCapacity_coulomb();
		float i = FuelGauge.getCurrent();
		float v = FuelGauge.getVoltage();
		uint16_t  t1 = FuelGauge.getTime();
		g_LED = !g_LED;
		wait(0.5);
	}
}
