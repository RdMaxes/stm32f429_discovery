/*
 *	ILI9341 library for LCD on STM32F429 Discovery, without LTDC hardware
 * @Hardware Configuration:
 * SPI Used: 	SPI5
 * SPI MOSI:	PF9
 * SPI SCK:	PF7	
 * CS		PC2
 * RESET	PD12
 * D/C		PD13
 */
#ifndef ILI9341_H
#define ILI9341_H

//Chip Select(CS) pin
#ifndef ILI9341_CS_PIN
	#define ILI9341_CS_CLK			RCC_AHB1Periph_GPIOC
	#define ILI9341_CS_PORT			GPIOC
	#define ILI9341_CS_PIN			GPIO_Pin_2
#endif
//Data Command(D/C) pin
#ifndef ILI9341_DC_PIN
	#define ILI9341_DC_CLK			RCC_AHB1Periph_GPIOD
	#define ILI9341_DC_PORT			GPIOD
	#define ILI9341_DC_PIN			GPIO_Pin_13
#endif
//Reset pin (RST) pin
#ifndef ILI9341_RST_PIN
	#define ILI9341_RST_CLK			RCC_AHB1Periph_GPIOD
	#define ILI9341_RST_PORT		GPIOD
	#define ILI9341_RST_PIN			GPIO_Pin_12
#endif

#define ILI9341_RST_SET				GPIO_SetBits(ILI9341_RST_PORT, ILI9341_RST_PIN)
#define ILI9341_RST_RESET			GPIO_ResetBits(ILI9341_RST_PORT, ILI9341_RST_PIN)
#define ILI9341_CS_SET				GPIO_SetBits(ILI9341_CS_PORT, ILI9341_CS_PIN)
#define ILI9341_CS_RESET			GPIO_ResetBits(ILI9341_CS_PORT, ILI9341_CS_PIN)
#define ILI9341_DC_SET				GPIO_SetBits(ILI9341_DC_PORT, ILI9341_DC_PIN)
#define ILI9341_DC_RESET			GPIO_ResetBits(ILI9341_DC_PORT, ILI9341_DC_PIN)

//LCD settings
#define ILI9341_WIDTH 				240
#define ILI9341_HEIGHT				320
#define ILI9341_PIXEL				76800

//Colors
#define ILI9341_COLOR_WHITE			0xFFFF
#define ILI9341_COLOR_BLACK			0x0000
#define ILI9341_COLOR_RED			0xF800
#define ILI9341_COLOR_GREEN			0x07E0
#define ILI9341_COLOR_GREEN2			0xB723
#define ILI9341_COLOR_BLUE			0x001F
#define ILI9341_COLOR_BLUE2			0x051D
#define ILI9341_COLOR_YELLOW			0xFFE0
#define ILI9341_COLOR_ORANGE			0xFBE4
#define ILI9341_COLOR_CYAN			0x07FF
#define ILI9341_COLOR_MAGENTA			0xA254
#define ILI9341_COLOR_GRAY			0x7BEF 
#define ILI9341_COLOR_BROWN			0xBBCA

//Commands
#define ILI9341_RESET				0x01
#define ILI9341_SLEEP_OUT			0x11
#define ILI9341_GAMMA				0x26
#define ILI9341_DISPLAY_OFF			0x28
#define ILI9341_DISPLAY_ON			0x29
#define ILI9341_COLUMN_ADDR			0x2A
#define ILI9341_PAGE_ADDR			0x2B
#define ILI9341_GRAM				0x2C
#define ILI9341_MAC				0x36
#define ILI9341_PIXEL_FORMAT			0x3A
#define ILI9341_WDB				0x51
#define ILI9341_WCD				0x53
#define ILI9341_RGB_INTERFACE			0xB0
#define ILI9341_FRC				0xB1
#define ILI9341_BPC				0xB5
#define ILI9341_DFC				0xB6
#define ILI9341_POWER1				0xC0
#define ILI9341_POWER2				0xC1
#define ILI9341_VCOM1				0xC5
#define ILI9341_VCOM2				0xC7
#define ILI9341_POWERA				0xCB
#define ILI9341_POWERB				0xCF
#define ILI9341_PGAMMA				0xE0
#define ILI9341_NGAMMA				0xE1
#define ILI9341_DTCA				0xE8
#define ILI9341_DTCB				0xEA
#define ILI9341_POWER_SEQ			0xED
#define ILI9341_3GAMMA_EN			0xF2
#define ILI9341_INTERFACE			0xF6
#define ILI9341_PRC				0xF7

/**
 * Public enum
 *
 * Select orientation for LCD
 */
typedef enum {
	ILI9341_Orientation_Portrait_1,
	ILI9341_Orientation_Portrait_2,
	ILI9341_Orientation_Landscape_1,
	ILI9341_Orientation_Landscape_2
} ILI9341_Orientation_t;

/**
 * Orientation
 * Used private
 */
typedef enum {
	ILI9341_Landscape,
	ILI9341_Portrait
} ILI9341_Orientation;

/**
 * Select font
 */
extern MY_FontDef_t MY_Font_7x10;
extern MY_FontDef_t MY_Font_11x18;
/**
 * LCD options
 * Used private
 */

typedef struct {
	uint16_t width;
	uint16_t height;
	ILI9341_Orientation orientation; // 1 = portrait; 0 = landscape
} ILI931_Options_t;

//function declaration
extern void ILI9341_Init(void);
extern void ILI9341_SetCursorPosition(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
extern void ILI9341_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
extern void ILI9341_Fill(uint16_t color);
extern void ILI9341_Rotate(ILI9341_Orientation_t orientation);
extern void ILI9341_Putc(uint16_t x, uint16_t y, char c, MY_FontDef_t *font, uint16_t foreground, uint16_t background);
extern void ILI9341_Puts(uint16_t x, uint16_t y, char *str, MY_FontDef_t *font, uint16_t foreground, uint16_t background);
extern void ILI9341_GetStringSize(char *str, MY_FontDef_t *font, uint16_t *width, uint16_t *height);
extern void ILI9341_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);
extern void ILI9341_DrawRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);
extern void ILI9341_DrawFilledRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);
extern void ILI9341_DrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
extern void ILI9341_DrawFilledCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
#endif
