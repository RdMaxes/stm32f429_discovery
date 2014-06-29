#include <stm32f4xx.h>
#include "usart1.h"
 
//DMA2 for usart1_tx configuration
void DMA2_usart1_Config(void)  
{  
    uint8_t dummy_data = 0;

    DMA_InitTypeDef DMA_InitStructure;
    //enable DMA2 clock
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
    //reset 
    DMA_DeInit(DMA2_Stream7); 
    //DMA configuration  
    DMA_InitStructure.DMA_Channel = DMA_Channel_4; 
    DMA_InitStructure.DMA_PeripheralBaseAddr =  (uint32_t)&USART1->DR; 
    DMA_InitStructure.DMA_BufferSize = 1;
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&dummy_data;      
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;     
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;   
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;   
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; 
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal ;     
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;     
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;  
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single; 
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold =DMA_FIFOThreshold_Full; 
                
    DMA_Init(DMA2_Stream7, &DMA_InitStructure);         
    DMA_Cmd(DMA2_Stream7,ENABLE); 
    USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);  
}

//usart1 send data via DMA
//@ int8_t *buf: data buffer ready to send
//@ int16_t len: data length
void usart1_DMA_send(int8_t *buf, int16_t len)
{  
    DMA_InitTypeDef DMA_InitStructure;
    //wait unitl last package is sent
    while(DMA_GetFlagStatus(DMA2_Stream7, DMA_FLAG_TCIF7)==RESET);
    DMA_ClearFlag(DMA2_Stream7, DMA_FLAG_TCIF7);
    //DMA configuration  
    DMA_InitStructure.DMA_Channel = DMA_Channel_4;   
    DMA_InitStructure.DMA_PeripheralBaseAddr =  (uint32_t)&USART1->DR; 
    DMA_InitStructure.DMA_BufferSize = len;
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&buf;      
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;     
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;   
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;   
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; 
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal ;     
    DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;     
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;  
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single; 
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold =DMA_FIFOThreshold_Full; 
                
    DMA_Init(DMA2_Stream7, &DMA_InitStructure);         
    DMA_Cmd(DMA2_Stream7,ENABLE); 
    USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE); 
}

//usart1 configuration
//default setting is 8,n,1
//@ int baudrate: the desired baudrate
void usart1_init(int baudrate)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;

	//enable clock for Tx/Rx pins
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	//hook the pin function
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
	//pin configuration
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	//enable usart1's clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	//usart1 configuration
	USART_InitStruct.USART_BaudRate = baudrate;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStruct);
	USART_Cmd(USART1, ENABLE);
	//enable RX interrupt
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	 
	//usart1 NVIC cconfiguration
	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStruct);	
}
