#include <stm32f4xx.h>
#include "led.h"
#include "myfont.h"
#include "myprintf.h"
#include "ili9341.h"
#include "usart1.h"


static void delay(int32_t time)
{
	while(time--);
}

int main(void)
{	
	char str_buf[30];	
	int32_t value =43552;
	LED_Init();
	ILI9341_Init();
	Usart1_Init(9600);
	Myprintf_Init(0x00,myputc);

	ILI9341_Puts(0,0,"LCD string test",&MY_Font_11x18,ILI9341_COLOR_WHITE,ILI9341_COLOR_BLUE);
	while(1) 
	{	
		//my_printf("It's usart1 test!\n");
		my_sprintf(str_buf,"%d\n",value);
		my_printf(str_buf);		
		LED_GREEN_ON();
		LED_RED_OFF();		
		delay(800000);
		LED_GREEN_OFF();
		LED_RED_ON();
		delay(800000);
	}

	return 0;
}
