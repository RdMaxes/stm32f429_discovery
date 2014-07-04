#include <stm32f4xx.h>
#include "string.h"
#include "led.h"
#include "myfont.h"
#include "ili9341.h"


static void delay(int32_t time)
{
	while(time--);
}

int main(void)
{	
	char str1[] = "hello, world!";
	char str2[] = "This is string test";	
	LED_Init();
	ILI9341_Init();
//	ILI9341_Puts(0,0,"LCD string test",&MY_Font_11x18,ILI9341_COLOR_WHITE,ILI9341_COLOR_BLUE);
	strcpy(str1,str2);
	while(1) 
	{	
		LED_GREEN_ON();
		LED_RED_OFF();		
		delay(800000);
		LED_GREEN_OFF();
		LED_RED_ON();
		delay(800000);
	}

	return 0;
}
