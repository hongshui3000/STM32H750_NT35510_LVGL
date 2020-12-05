/* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/
#ifndef __LCD_H
#define __LCD_H
#include "stdlib.h"
#include "stdint.h"

//LCD重要参数集
typedef struct
{
    unsigned short 		width;			//LCD 宽度
    unsigned short 		height;			//LCD 高度
    unsigned short 		id;				  //LCD ID
    unsigned char  		dir;			  //横屏还是竖屏控制：0，竖屏；1，横屏。
    unsigned short	 	wramcmd;		//开始写gram指令
    unsigned short  	rramcmd;   //开始读gram指令
    unsigned short  	setxcmd;		//设置x坐标指令
    unsigned short  	setycmd;		//设置y坐标指令
} _lcd_dev;

//LCD参数
extern _lcd_dev lcddev;	//管理LCD重要参数
/////////////////////////////////////用户配置区///////////////////////////////////
#define USE_HORIZONTAL  	 0 //定义液晶屏顺时针旋转方向 	0-0度旋转，1-90度旋转，2-180度旋转，3-270度旋转

//////////////////////////////////////////////////////////////////////////////////
//定义LCD的尺寸
#define LCD_W 480
#define LCD_H 800

//TFTLCD部分外要调用的函数
extern unsigned short  POINT_COLOR;//默认红色
extern unsigned short  BACK_COLOR; //背景颜色.默认为白色


//LCD地址结构体
typedef struct
{
    volatile unsigned short LCD_REG;
    volatile unsigned short LCD_RAM;
} LCD_TypeDef;

//使用NOR/SRAM的 Bank1.sector4,地址位HADDR[27,26]=11 A15作为数据命令区分线
//注意设置时STM32内部会右移一位对其!
#define LCD_BASE        ((uint32_t)(0x6C000000 | 0x0000FFFE))
#define LCD             ((LCD_TypeDef *) LCD_BASE)

//画笔颜色
#define WHITE       0xFFFF
#define BLACK      	0x0000
#define BLUE       	0x001F
#define BRED        0XF81F
#define GRED 			 	0XFFE0
#define GBLUE			 	0X07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define BROWN 			0XBC40 //棕色
#define BRRED 			0XFC07 //棕红色
#define GRAY  			0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色

#define LIGHTGREEN     	0X841F //浅绿色
#define LIGHTGRAY     	0XEF5B //浅灰色(PANNEL)
#define LGRAY 			 		0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE      	0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE          0X2B12 //浅棕蓝色(选择条目的反色)

void 								lcd_init(void);
unsigned short 			lcd_read(void);
void 								lcd_clear(unsigned short color);
void 								lcd_setcursor(unsigned short xpos, unsigned short ypos);
void 								lcd_drawpoint(unsigned short x,unsigned short y);//画点
unsigned short  		lcd_readpoint(unsigned short x,unsigned short y); //读点
void 								lcd_setwindows(unsigned short xstar, unsigned short ystar,unsigned short xend,unsigned short yend);
unsigned short 			lcd_rd_data(void);//读取lcd数据
void 								lcd_writereg(unsigned short lcd_reg, unsigned short lcd_regvalue);
void 								lcd_wr_reg(unsigned short data);
void 								lcd_wr_data(unsigned short data);
void 								lcd_readreg(unsigned short lcd_reg,unsigned short *rval,int n);
void 								lcd_writeram_prepare(void);
void 								lcd_readram_prepare(void);
void 								lcd_writedata_16bit(unsigned short data);
unsigned short 			lcd_readdata_16bit(void);
void 								lcd_direction(unsigned char direction );
unsigned short 			lcd_read_id(void);
unsigned short 			color_to_565(unsigned char r, unsigned char g, unsigned char b);

#endif





