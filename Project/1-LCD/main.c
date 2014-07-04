#include <stm32f4xx.h>
#include "led.h"
#include "myfont.h"
#include "myprintf.h"
#include "ili9341.h"
#include "usart1.h"
#include "string.h"


static void delay(int32_t time)
{
	while(time--);
}

int main(void)
{
	char str1[] = "Hello World!";
	char str2[] = "This is string.h test";
	LED_Init();
	ILI9341_Init();
	Usart1_Init(9600);
	Myprintf_Init(0x00,myputc);

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
