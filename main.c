
#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>
#include "AVR_Ports.h"
#include "AVR_GPIO_Declarations.h"
#include "AVR_Watchdog_Timer.h"

int main(void)
{
	Pin_Direction(C, 0, output);
	Pin_Direction(D, 0, output);
	
	WDT_Enable(); //WDT for 2.1 S
	Pin_Set(D,0);
	_delay_ms(2000); //more than 2100ms will continue restarting the program from here
	
	WDT_Reset();
	//WDT_Disable(); //canceling it here will get us a stuck loop!
	
	while(1) //infinite loop! (WDT will reset all program)
	{
		Pin_Reset(D,0);
		
		Pin_Toggle(C,0);
		_delay_ms(100);
	}
}
