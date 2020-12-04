#ifndef __LCD_H
#define __LCD_H		

#include "ref.h"

typedef struct
{
	uint16_t	width;
	uint16_t	height;
	uint16_t	id;
	uint8_t		dir;
	uint16_t	wramcmd;
	uint16_t	rramcmd;
	uint16_t	setxcmd;
	uint16_t	setycmd;
} _lcd_dev;

extern _lcd_dev lcddev;

#define USE_HORIZONTAL		0 //0 = 0*; 1 = 90*; 2 = 180*; 3 = 270*
#define LCD_USE8BIT_MODEL		0 //0 = 16bit parallel; 1 = 8bit parallel

#define LCD_W		480
#define LCD_H		800

extern uint16_t  POINT_COLOR;
extern uint16_t  BACK_COLOR;

#define LCD_REGION_NUMBER		MPU_REGION_NUMBER0
#define LCD_ADDRESS_START		(0X60000000)
#define LCD_REGION_SIZE			MPU_REGION_SIZE_256MB

#define LCD_LED      10 //Backlight pin number
#define LCD_RST      12 //Reset pin number

#define	LCD_LED_SET()	HAL_GPIO_WritePin(GPIOC, 1 << LCD_LED, GPIO_PIN_SET) //Pin_C_out + LED = PC10
#define	LCD_LED_CLR()	HAL_GPIO_WritePin(GPIOC, 1 << LCD_LED, GPIO_PIN_RESET)

#define	LCD_RST_SET()	HAL_GPIO_WritePin(GPIOD, 1 << LCD_RST, GPIO_PIN_SET) //Pin_D_out + RST = PD12
#define	LCD_RST_CLR()	HAL_GPIO_WritePin(GPIOD, 1 << LCD_RST, GPIO_PIN_RESET)


typedef struct
{
#if LCD_USE8BIT_MODEL 
	vu8 LCD_REG;
	vu8 LCD_RAM;
#else
	__IO uint16_t LCD_REG;
	__IO uint16_t LCD_RAM;
#endif
} LCD_TypeDef;

#if LCD_USE8BIT_MODEL
#define LCD_BASE        ((uint32_t)(0x6C000000 | 0x000003FF))
#else		    
#define LCD_BASE        ((uint32_t)(0x6C000000 | 0x000007FE))
#endif
#define LCD			((LCD_TypeDef *) LCD_BASE)		  

#define WHITE       0xFFFF
#define BLACK      	0x0000	  
#define BLUE       	0x001F  
#define BRED        0XF81F
#define GRED 		0XFFE0
#define GBLUE		0X07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define BROWN 		0XBC40
#define BRRED 		0XFC07
#define GRAY  		0X8430
#define DARKBLUE    0X01CF
#define LIGHTBLUE   0X7D7C
#define GRAYBLUE    0X5458
#define LIGHTGREEN  0X841F
#define LIGHTGRAY   0XEF5B
#define LGRAY 		0XC618
#define LGRAYBLUE   0XA651
#define LBBLUE      0X2B12

void LCD_Init(void);
uint16_t LCD_read(void);
void LCD_Clear(uint16_t Color);
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
void LCD_DrawPoint(uint16_t x, uint16_t y);
uint16_t  LCD_ReadPoint(uint16_t x, uint16_t y);
void LCD_SetWindows(uint16_t xStar, uint16_t yStar, uint16_t xEnd, uint16_t yEnd);
uint16_t LCD_RD_DATA(void);
void LCD_WriteReg(uint16_t LCD_Reg, uint16_t LCD_RegValue);
void LCD_WR_REG(uint16_t data);
void LCD_WR_DATA(uint16_t data);
void LCD_ReadReg(uint16_t LCD_Reg, uint16_t* Rval, int n);
void LCD_WriteRAM_Prepare(void);
void LCD_ReadRAM_Prepare(void);
void Lcd_WriteData_16Bit(uint16_t Data);
uint16_t Lcd_ReadData_16Bit(void);
void LCD_direction(uint8_t direction);
uint16_t Color_To_565(uint8_t r, uint8_t g, uint8_t b);
uint16_t LCD_Read_ID(void);

#endif  
