#ifndef LED_H
#define LED_H

//LED GREEN
#ifndef LED_GREEN_PIN
	#define LED_GREEN_CLK				RCC_AHB1Periph_GPIOG
	#define LED_GREEN_PORT				GPIOG
	#define LED_GREEN_PIN				GPIO_Pin_13
#endif

//LED RED
#ifndef LED_RED_PIN
	#define LED_RED_CLK				RCC_AHB1Periph_GPIOG
	#define LED_RED_PORT				GPIOG
	#define LED_RED_PIN				GPIO_Pin_14
#endif

//LED Operation
#define LED_GREEN_ON()					GPIO_SetBits(LED_GREEN_PORT, LED_GREEN_PIN)
#define LED_GREEN_OFF()					GPIO_ResetBits(LED_GREEN_PORT, LED_GREEN_PIN)

#define LED_RED_ON()					GPIO_SetBits(LED_RED_PORT, LED_RED_PIN)
#define LED_RED_OFF()					GPIO_ResetBits(LED_RED_PORT, LED_RED_PIN)

//function declaration
void LED_Init(void);
#endif
