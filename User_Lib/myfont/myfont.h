/**
 * Fonts library
 */
#ifndef MY_FONTS_H
#define MY_FONTS_H

/**
 * Font struct
 */
typedef struct {
	uint8_t FontWidth;
	uint8_t FontHeight;
	const uint16_t *data;
} MY_FontDef_t;

#endif

