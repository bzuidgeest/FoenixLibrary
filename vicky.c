//#include <stdio.h>
#include "vicky.h"

/*
volatile unsigned char * const textScreen = (unsigned char *)0xAFA000; 
volatile unsigned char * const textScreenColor = (unsigned char *)0xAFC000; 
volatile unsigned char * const textForegroundLUT = (unsigned char *)0xAF1F40; 
volatile unsigned char * const textBackgroundLUT = (unsigned char *)0xAF1F80; 

volatile unsigned long * const textForegroundLUT_L = (unsigned long *)0xAF1F40; 
volatile unsigned long * const textBackgroundLUT_L = (unsigned long *)0xAF1F80; 
*/

//extern volatile unsigned long * const textBackgroundLUT_L = (unsigned long *)0xAF1F80; 


void x(void)
{
    textBackgroundLUT_L[0] = 2;
}


void clearTextScreen(unsigned char clearCharacter, unsigned char backgroundColor, unsigned char foregroundcolor)
{
    unsigned char color = backgroundColor & 0xF | ((foregroundcolor & 0xF) << 4);
    
	memset(textScreen, clearCharacter, 0x1E00);
	memset(textScreenColor, color, 0x1E00);
}

void putTextXY(char *text, unsigned char x, unsigned char y, unsigned char backgroundColor, unsigned char foregroundColor)
{
	int offset = XY(x, y);
    unsigned char color = textColorByte(backgroundColor, foregroundColor);
    
	while (*text)
	{
		textScreen[offset] = *text;
		textScreenColor[offset] = color;
		offset++;
		text++;
	}
}

void setEGATextPalette()
{
    textForegroundLUT_L[0] = 0xFF000000;
	textForegroundLUT_L[1] = 0xFF0000AA;
	textForegroundLUT_L[2] = 0xFF00AA00;
	textForegroundLUT_L[3] = 0xFF00AAAA;
	textForegroundLUT_L[4] = 0xFFAA0000;
	textForegroundLUT_L[5] = 0xFFAA00AA;
	textForegroundLUT_L[6] = 0xFFAA5500;
	textForegroundLUT_L[7] = 0xFFAAAAAA;
	textForegroundLUT_L[8] = 0xFF555555;
	textForegroundLUT_L[9] = 0xFF5555FF;
	textForegroundLUT_L[10] = 0xFF55FF55;
	textForegroundLUT_L[11] = 0xFF55FFFF;
	textForegroundLUT_L[12] = 0xFFFF5555;
	textForegroundLUT_L[13] = 0xFFFF55FF;
	textForegroundLUT_L[14] = 0xFFFFFF55;
	textForegroundLUT_L[15] = 0xFFFFFFFF;
	
	textBackgroundLUT_L[0] = 0xFF000000;
	textBackgroundLUT_L[1] = 0xFF000000;
	textBackgroundLUT_L[2] = 0xFF000000;
	textBackgroundLUT_L[3] = 0xFF000000;
	textBackgroundLUT_L[4] = 0xFF000000;
	textBackgroundLUT_L[5] = 0xFF000000;
	textBackgroundLUT_L[6] = 0xFF000000;
	textBackgroundLUT_L[7] = 0xFF000000;
	textBackgroundLUT_L[8] = 0xFF000000;
	textBackgroundLUT_L[9] = 0xFF000000;
	textBackgroundLUT_L[10] = 0xFF000000;
	textBackgroundLUT_L[11] = 0xFF000000;
	textBackgroundLUT_L[12] = 0xFF000000;
	textBackgroundLUT_L[13] = 0xFF000000;
	textBackgroundLUT_L[14] = 0xFF000000;
	textBackgroundLUT_L[15] = 0xFF000000;
}


void enableTextLayer(void)
{
	MASTER_CTRL_REG_L |= Mstr_Ctrl_Text_Mode_En;
}

void setBorder(int x, int y, long color)
{
	BORDER_X_SIZE = x; //(0x20)
	BORDER_Y_SIZE = y; //(0x20)

	BORDER_COLOR_R = color >> 16;
	BORDER_COLOR_G = color >> 8;
	BORDER_COLOR_B = color & 0xF;

	if (x == 0 && y == 0)
	{
		BORDER_CTRL_REG = 0;
	}
	else
	{
		BORDER_CTRL_REG = Border_CTRL_Enable;
	}
}