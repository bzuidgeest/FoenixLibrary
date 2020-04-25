#ifndef VICKY_H
#define VICKY_H

#define MASTER_CTRL_REG_L (*(unsigned char *)0xAF0000)
#define Mstr_Ctrl_Text_Mode_En  0x01
#define Mstr_Ctrl_Text_Overlay  0x02       // Enable the Overlay of the text mode on top of Graphic Mode (the Background Color is ignored)
#define Mstr_Ctrl_Graph_Mode_En 0x04       // Enable the Graphic Mode
#define Mstr_Ctrl_Bitmap_En     0x08       // Enable the Bitmap Module In Vicky
#define Mstr_Ctrl_TileMap_En    0x10       // Enable the Tile Module in Vicky
#define Mstr_Ctrl_Sprite_En     0x20       // Enable the Sprite Module in Vicky
#define Mstr_Ctrl_GAMMA_En      0x40       // this Enable the GAMMA correction - The Analog and DVI have different color value, the GAMMA is great to correct the difference
#define Mstr_Ctrl_Disable_Vid   0x80       // This will disable the Scanning of the Video hence giving 100% bandwith to the CPU

#define BORDER_CTRL_REG         (*(unsigned char *)0xAF0004)
#define Border_CTRL_Enable      0x01

#define BORDER_COLOR_B          (*(unsigned char *)0xAF0005)
#define BORDER_COLOR_G          (*(unsigned char *)0xAF0006)
#define BORDER_COLOR_R          (*(unsigned char *)0xAF0007)

#define VKY_TXT_CURSOR_CHAR_REG 		(*(volatile unsigned char *)0xAF0012)
#define VKY_TXT_CURSOR_CTRL_REG        	(*(volatile unsigned char *)0xAF0010)   
#define VKY_TXT_CURSOR_X_REG_L 			(*(volatile unsigned char *)0xAF0014)
#define VKY_TXT_CURSOR_X_REG_H  		(*(volatile unsigned char *)0xAF0015)
#define VKY_TXT_CURSOR_X_REG  			(*(volatile unsigned short *)0xAF0014)      
#define VKY_TXT_CURSOR_Y_REG_L 			(*(volatile unsigned char *)0xAF0016) 
#define VKY_TXT_CURSOR_y_REG_H  		(*(volatile unsigned char *)0xAF0017) 
#define VKY_TXT_CURSOR_Y_REG 			(*(volatile unsigned short *)0xAF0016)   

#define COLS_VISIBLE     				(*(volatile unsigned short *)0x00000F) //2 Bytes Columns visible per screen line. A virtual line can be longer than displayed, up to COLS_PER_LINE long. Default = 80
#define COLS_PER_LINE    				(*(volatile unsigned short *)0x000011) //2 Bytes Columns in memory per screen line. A virtual line can be this long. Default=128
#define LINES_VISIBLE    				(*(volatile unsigned short *)0x000013) //2 Bytes The number of rows visible on the screen. Default=25
#define LINES_MAX        				(*(volatile unsigned short *)0x000015) //2 Bytes The number of rows in memory for the screen. Default=64

#define BORDER_X_SIZE (*(volatile unsigned char *)0xAF0008) //X-  Values: 0 - 32 (Default: 32)
#define BORDER_Y_SIZE (*(volatile unsigned char *)0xAF0009) //Y- Values 0 -32 (Default: 32)

/*
extern volatile unsigned char * const textScreen = (unsigned char *)0xAFA000; 
extern volatile unsigned char * const textScreenColor = (unsigned char *)0xAFC000; 
extern volatile unsigned char * const textForegroundLUT = (unsigned char *)0xAF1F40; 
extern volatile unsigned char * const textBackgroundLUT = (unsigned char *)0xAF1F80; 

extern volatile unsigned long * const textForegroundLUT_L = (unsigned long *)0xAF1F40; 
extern volatile unsigned long * const textBackgroundLUT_L = (unsigned long *)0xAF1F80; 
*/

#define textScreen 			            ((volatile unsigned char *)0xAFA000)  
#define textScreenColor 			    ((volatile unsigned char *)0xAFC000)  
#define textForegroundLUT 			    ((volatile unsigned char *)0xAF1F40)  
#define textBackgroundLUT 			    ((volatile unsigned char *)0xAF1F80)  

#define textForegroundLUT_L 			((volatile unsigned long *)0xAF1F40)
#define textBackgroundLUT_L 			((volatile unsigned long *)0xAF1F80)

#define XY(x, y) ((x) + 128 * (y))
#define textColorByte(backgroundColor, foregroundcolor) (backgroundColor & 0xF | ((foregroundcolor & 0xF) << 4))

// Clear screen 
void clearTextScreen(unsigned char clearCharacter, unsigned char backgroundColor, unsigned char foregroundcolor);
// Print a string at the specified coordinates
void putTextXY(char *text, unsigned char x, unsigned char y, unsigned char backgroundColor, unsigned char foregroundcolor);

void enableTextLayer(void);
void setBorder(int x, int y, long color);

void setEGATextPalette();

#endif /* VICKY_H */