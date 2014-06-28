#include <stm32f4xx.h>
#include "led.h"
 
//LED configuration 
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	//LED GREEN
	RCC_AHB1PeriphClockCmd(LED_GREEN_CLK,ENABLE);
	GPIO_InitStruct.GPIO_Pin = LED_GREEN_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_GREEN_PORT, &GPIO_InitStruct);
	//LED RED
	RCC_AHB1PeriphClockCmd(LED_RED_CLK,ENABLE);
	GPIO_InitStruct.GPIO_Pin = LED_RED_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_RED_PORT, &GPIO_InitStruct);
		
}
