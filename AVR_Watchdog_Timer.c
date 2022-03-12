
#include <avr/io.h>
#define F_CPU 4000000UL
#include "AVR_Watchdog_Timer.h"

void WDT_Enable()
{
	WDTCR = 0x0F; //0b00001111, Enable WDT, reset the system after 2.1 Seconds
}

void WDT_Disable()
{
	//Disable WDT
	WDTCR = 0x18; //0b00011000, at first, we write 1 to both WDTOE and WDE
	WDTCR = 0x00; //then, we have to write 0 to WDE
}

void WDT_Reset()
{
	//Reset WDT (start counting from the beginning)
	WDT_Disable();
	WDT_Enable();
}