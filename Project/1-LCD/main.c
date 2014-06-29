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
	ILI9341_Init();
	while(1) 
	{	
		ILI9341_Fill(ILI9341_COLOR_WHITE); delay(8000000);
		ILI9341_Fill(ILI9341_COLOR_BLACK); delay(8000000);
		ILI9341_Fill(ILI9341_COLOR_RED); delay(8000000);
		ILI9341_Fill(ILI9341_COLOR_GREEN); delay(8000000);
		ILI9341_Fill(ILI9341_COLOR_GREEN); delay(8000000);
		ILI9341_Fill(ILI9341_COLOR_BLUE); delay(8000000);
		ILI9341_Fill(ILI9341_COLOR_YELLOW); delay(8000000);
		ILI9341_Fill(ILI9341_COLOR_ORANGE); delay(8000000);
		ILI9341_Fill(ILI9341_COLOR_MAGENTA); delay(8000000);
		ILI9341_Fill(ILI9341_COLOR_BROWN); delay(8000000);
		LED_GREEN_ON();
		LED_RED_OFF();		
		delay(800000);
		LED_GREEN_OFF();
		LED_RED_ON();
		delay(800000);
	}

	return 0;
}
