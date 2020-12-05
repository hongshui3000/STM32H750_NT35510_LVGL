//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��STM32F103ZET6,����ԭ��ELITE STM32������,��Ƶ72MHZ������12MHZ
//QDtech-TFTҺ������ for STM32 FSMC
//xiao��@ShenZhen QDtech co.,LTD
//��˾��վ:www.qdtft.com
//�Ա���վ��http://qdtech.taobao.com
//wiki������վ��http://www.lcdwiki.com
//��˾�ṩ����֧�֣��κμ������⻶ӭ��ʱ����ѧϰ
//�̻�(����) :+86 0755-23594567 
//�ֻ�:15989313508���빤�� 
//����:lcdwiki01@gmail.com    support@lcdwiki.com    goodtft@163.com 
//����֧��QQ:3002773612  3002778157
//��������QQȺ:324828016
//��������:2018/08/09
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������ȫ�����Ӽ������޹�˾ 2018-2028
//All rights reserved
/****************************************************************************************************
//=========================================��Դ����================================================//
//     LCDģ��                STM32��Ƭ��
//      VDD          ��        DC5V/3.3V        //��Դ
//      GND          ��          GND            //��Դ��
//=======================================Һ���������߽���==========================================//
//��ģ��Ĭ��������������Ϊ16λ��������
//     LCDģ��                STM32��Ƭ��      _
//			 DB0          ��          PD14           |
//			 DB1          ��          PD15           | 
//       DB2          ��          PD0            |
//       DB3          ��          PD1            |
//       DB4          ��          PE7            |
//       DB5          ��          PE8            |
//       DB6          ��          PE9            |
//       DB7          ��          PE10           |==>>Һ����16λ���������ź�
//       DB8          ��          PE11           | 
//       DB9          ��          PE12           |
//       DB10         ��          PE13           |
//       DB11         ��          PE14           |
//       DB12         ��          PE15           |
//       DB13         ��          PD8            |
//       DB14         ��          PD9            |
//       DB15         ��          PD10          _|
//=======================================Һ���������߽���==========================================//
//     LCDģ�� 				        STM32��Ƭ�� 
//       WR          ��          PD5           //Һ����д���ݿ����ź�
//       RD          ��          PD4           //Һ���������ݿ����ź�
//       RS          ��          PG0           //Һ��������/��������ź�
//       RST         ��        ��λ����        //Һ������λ�����ź�
//       CS          ��          PG12          //Һ����Ƭѡ�����ź�
//       BL          ��          PB0           //Һ������������ź�
//=========================================������������=========================================//
//���ģ�鲻���������ܻ��ߴ��д������ܣ����ǲ���Ҫ�������ܣ�����Ҫ���д���������
//	   LCDģ��                STM32��Ƭ�� 
//       PEN         ��          PF10          //�����������ж��ź�
//       MISO        ��          PB2           //������SPI���߶��ź�
//       MOSI        ��          PF9           //������SPI����д�ź�
//       T_CS        ��          PF11          //������Ƭѡ�����ź�
//       CLK         ��          PB1           //������SPI����ʱ���ź�
**************************************************************************************************/	
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
#include "sys.h"	 
#include "stdlib.h"

//LCD��Ҫ������
typedef struct  
{										    
	u16 width;			//LCD ���
	u16 height;			//LCD �߶�
	u16 id;				  //LCD ID
	u8  dir;			  //���������������ƣ�0��������1��������	
	u16	 wramcmd;		//��ʼдgramָ��
	u16  rramcmd;   //��ʼ��gramָ��
	u16  setxcmd;		//����x����ָ��
	u16  setycmd;		//����y����ָ��	 
}_lcd_dev; 	

//LCD����
extern _lcd_dev lcddev;	//����LCD��Ҫ����
/////////////////////////////////////�û�������///////////////////////////////////	 
#define USE_HORIZONTAL  	  0 //����Һ����˳ʱ����ת���� 	0-0����ת��1-90����ת��2-180����ת��3-270����ת
#define LCD_USE8BIT_MODEL   0	//�������������Ƿ�ʹ��8λģʽ 0,ʹ��16λģʽ.1,ʹ��8λģʽ

//////////////////////////////////////////////////////////////////////////////////	  
//����LCD�ĳߴ�
#define LCD_W 480
#define LCD_H 800

//TFTLCD������Ҫ���õĺ���		   
extern u16  POINT_COLOR;//Ĭ�Ϻ�ɫ    
extern u16  BACK_COLOR; //������ɫ.Ĭ��Ϊ��ɫ

////////////////////////////////////////////////////////////////////
//-----------------LCD�˿ڶ���---------------- 
#define LED      10      //�����������        PB0
#define RST      12     //��λ����            PD11

//QDtechȫϵ��ģ������������ܿ��Ʊ��������û�Ҳ���Խ�PWM���ڱ�������
#define	LCD_LED PCout(LED) //LCD����
#define LCD_RST PDout(RST) //��λ����            PC4

//LCD��ַ�ṹ��
typedef struct
{
#if LCD_USE8BIT_MODEL 
	vu8 LCD_REG;
	vu8 LCD_RAM;
#else
	vu16 LCD_REG;
	vu16 LCD_RAM;		
#endif
} LCD_TypeDef;

//ʹ��NOR/SRAM�� Bank1.sector4,��ַλHADDR[27,26]=11 A10��Ϊ�������������� 
#if LCD_USE8BIT_MODEL
//ʹ��8λģʽʱ��STM32�ڲ���ַ����Ҫ����һλ 
#define LCD_BASE        ((u32)(0x6C000000 | 0x000003FF))
#else
//ʹ��16λģʽʱ��ע������ʱSTM32�ڲ���ַ��Ҫ����һλ����! 			    
#define LCD_BASE        ((u32)(0x6C000000 | 0x000007FE))
#endif
#define LCD             ((LCD_TypeDef *) LCD_BASE)		  

//������ɫ
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
#define BROWN 			0XBC40 //��ɫ
#define BRRED 			0XFC07 //�غ�ɫ
#define GRAY  			0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	0X841F //ǳ��ɫ
#define LIGHTGRAY     0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 			 		0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE      	0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE          0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)
	    															  
void LCD_Init(void);
u16 LCD_read(void);
void LCD_Clear(u16 Color);	 
void LCD_SetCursor(u16 Xpos, u16 Ypos);
void LCD_DrawPoint(u16 x,u16 y);//����
u16  LCD_ReadPoint(u16 x,u16 y); //����	   
void LCD_SetWindows(u16 xStar, u16 yStar,u16 xEnd,u16 yEnd);
u16 LCD_RD_DATA(void);//��ȡLCD����								    
void LCD_WriteReg(u16 LCD_Reg, u16 LCD_RegValue);
void LCD_WR_REG(u16 data);
void LCD_WR_DATA(u16 data);
void LCD_ReadReg(u16 LCD_Reg,u16 *Rval,int n);
void LCD_WriteRAM_Prepare(void);
void LCD_ReadRAM_Prepare(void);   
void Lcd_WriteData_16Bit(u16 Data);
u16 Lcd_ReadData_16Bit(void);
void LCD_direction(u8 direction );
u16 Color_To_565(u8 r, u8 g, u8 b);
u16 LCD_Read_ID(void);

				  		 
#endif  
	 
	 



