#include <stm32f4xx.h>
#include "led.h"
#include "myfont.h"
#include "ili9341.h"


static void delay(int32_t time)
{
	while(time--);
}

int main(void)
{	
	LED_Init();
	while(1) 
	{
		LED_GREEN_ON();
		LED_RED_ON();		
		delay(800000);
		LED_GREEN_OFF();
		LED_RED_OFF();
		delay(800000);
	}

	return 0;
}
