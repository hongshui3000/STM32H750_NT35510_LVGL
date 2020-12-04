#ifndef __TOUCH_H__
#define __TOUCH_H__

#include "ref.h"

#define TP_PRES_DOWN 0x80 
#define TP_CATH_PRES 0x40	  
										    
typedef struct
{
	uint8_t (*init)(void);
	uint8_t (*scan)(uint8_t);
	void (*adjust)(void);
	uint16_t x0;
	uint16_t y0;
	uint16_t x;
	uint16_t y;						   	    
	uint8_t  sta;
					
	float xfac;					
	float yfac;
	short xoff;
	short yoff;	   
	uint8_t touchtype;
}_m_tp_dev;

extern _m_tp_dev tp_dev;
  
#define PEN  13   //T_PEN   PD13
#define DOUT 14   //T_MISO  PB14
#define TDIN 15   //T_MOSI  PB15
#define TCLK 10   //T_SCK   PB10
#define TCS  11   //T_CS    PB11

#define PEN_READ  HAL_GPIO_ReadPin(GPIOD, 1 << PEN)
#define DOUT_READ HAL_GPIO_ReadPin(GPIOB, 1 << DOUT)

#define TDIN_SET()  HAL_GPIO_WritePin(GPIOB, 1 << TDIN, GPIO_PIN_SET)
#define TCLK_SET()  HAL_GPIO_WritePin(GPIOB, 1 << TCLK, GPIO_PIN_SET)
#define TCS_SET()   HAL_GPIO_WritePin(GPIOB, 1 << TCS, GPIO_PIN_SET)

#define TDIN_CLR()  HAL_GPIO_WritePin(GPIOB, 1 << TDIN, GPIO_PIN_RESET)
#define TCLK_CLR()  HAL_GPIO_WritePin(GPIOB, 1 << TCLK, GPIO_PIN_RESET)
#define TCS_CLR()   HAL_GPIO_WritePin(GPIOB, 1 << TCS, GPIO_PIN_RESET)
	   
void TP_Write_Byte(uint8_t num);
uint16_t TP_Read_AD(uint8_t CMD);
uint16_t TP_Read_XOY(uint8_t xy);
uint8_t TP_Read_XY(uint16_t *x,uint16_t *y);
uint8_t TP_Read_XY2(uint16_t *x,uint16_t *y);
void TP_Drow_Touch_Point(uint16_t x,uint16_t y,uint16_t color);
void TP_Draw_Big_Point(uint16_t x,uint16_t y,uint16_t color);
uint8_t TP_Scan(uint8_t tp);
void TP_Save_Adjdata(void);
uint8_t TP_Get_Adjdata(void);
void TP_Adjust(void);
uint8_t TP_Init(void);
																 
void TP_Adj_Info_Show(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t x3,uint16_t y3,uint16_t fac);
 		  
#endif

















