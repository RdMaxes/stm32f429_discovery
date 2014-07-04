#ifndef USART1_H
#define USART1_H

extern void USART1_IRQHandler(void);
//function declaration
void Usart1_Init(int baudrate);
void DMA2_usart1_Config(void);
void Usart1_DMA_Send(int8_t *buf, int16_t len);

#endif
