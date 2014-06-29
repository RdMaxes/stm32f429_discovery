#ifndef USART1_H
#define USART1_H

//function declaration
void usart1_init(int baudrate);
void DMA2_usart1_Config(void);
void usart1_DMA_send(int8_t *buf, int16_t len);

#endif
