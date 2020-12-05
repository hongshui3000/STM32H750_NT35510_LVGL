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
#include "delay.h"
#if SYSTEM_SUPPORT_OS
#include "includes.h"					//ucos ʹ��	  
#endif
static u8  fac_us=0;							//us��ʱ������			   
static u16 fac_ms=0;							//ms��ʱ������,��ucos��,����ÿ�����ĵ�ms��
	
	
#if SYSTEM_SUPPORT_OS							//���SYSTEM_SUPPORT_OS������,˵��Ҫ֧��OS��(������UCOS).
//��delay_us/delay_ms��Ҫ֧��OS��ʱ����Ҫ������OS��صĺ궨��ͺ�����֧��
//������3���궨��:
//    delay_osrunning:���ڱ�ʾOS��ǰ�Ƿ���������,�Ծ����Ƿ����ʹ����غ���
//delay_ostickspersec:���ڱ�ʾOS�趨��ʱ�ӽ���,delay_init�����������������ʼ��systick
// delay_osintnesting:���ڱ�ʾOS�ж�Ƕ�׼���,��Ϊ�ж����治���Ե���,delay_msʹ�øò����������������
//Ȼ����3������:
//  delay_osschedlock:��������OS�������,��ֹ����
//delay_osschedunlock:���ڽ���OS�������,���¿�������
//    delay_ostimedly:����OS��ʱ,���������������.

//�����̽���UCOSII��UCOSIII��֧��,����OS,�����вο�����ֲ
//֧��UCOSII
#ifdef 	OS_CRITICAL_METHOD						//OS_CRITICAL_METHOD������,˵��Ҫ֧��UCOSII				
#define delay_osrunning		OSRunning			//OS�Ƿ����б��,0,������;1,������
#define delay_ostickspersec	OS_TICKS_PER_SEC	//OSʱ�ӽ���,��ÿ����ȴ���
#define delay_osintnesting 	OSIntNesting		//�ж�Ƕ�׼���,���ж�Ƕ�״���
#endif

//֧��UCOSIII
#ifdef 	CPU_CFG_CRITICAL_METHOD					//CPU_CFG_CRITICAL_METHOD������,˵��Ҫ֧��UCOSIII	
#define delay_osrunning		OSRunning			//OS�Ƿ����б��,0,������;1,������
#define delay_ostickspersec	OSCfg_TickRate_Hz	//OSʱ�ӽ���,��ÿ����ȴ���
#define delay_osintnesting 	OSIntNestingCtr		//�ж�Ƕ�׼���,���ж�Ƕ�״���
#endif


//us����ʱʱ,�ر��������(��ֹ���us���ӳ�)
void delay_osschedlock(void)
{
#ifdef CPU_CFG_CRITICAL_METHOD   				//ʹ��UCOSIII
	OS_ERR err; 
	OSSchedLock(&err);							//UCOSIII�ķ�ʽ,��ֹ���ȣ���ֹ���us��ʱ
#else											//����UCOSII
	OSSchedLock();								//UCOSII�ķ�ʽ,��ֹ���ȣ���ֹ���us��ʱ
#endif
}

//us����ʱʱ,�ָ��������
void delay_osschedunlock(void)
{	
#ifdef CPU_CFG_CRITICAL_METHOD   				//ʹ��UCOSIII
	OS_ERR err; 
	OSSchedUnlock(&err);						//UCOSIII�ķ�ʽ,�ָ�����
#else											//����UCOSII
	OSSchedUnlock();							//UCOSII�ķ�ʽ,�ָ�����
#endif
}

//����OS�Դ�����ʱ������ʱ
//ticks:��ʱ�Ľ�����
void delay_ostimedly(u32 ticks)
{
#ifdef CPU_CFG_CRITICAL_METHOD
	OS_ERR err; 
	OSTimeDly(ticks,OS_OPT_TIME_PERIODIC,&err);	//UCOSIII��ʱ��������ģʽ
#else
	OSTimeDly(ticks);							//UCOSII��ʱ
#endif 
}
 
//systick�жϷ�����,ʹ��ucosʱ�õ�
void SysTick_Handler(void)
{	
	if(delay_osrunning==1)						//OS��ʼ����,��ִ�������ĵ��ȴ���
	{
		OSIntEnter();							//�����ж�
		OSTimeTick();       					//����ucos��ʱ�ӷ������               
		OSIntExit();       	 					//���������л����ж�
	}
}
#endif

			   
//��ʼ���ӳٺ���
//��ʹ��OS��ʱ��,�˺������ʼ��OS��ʱ�ӽ���
//SYSTICK��ʱ�ӹ̶�ΪHCLKʱ�ӵ�1/8
//SYSCLK:ϵͳʱ��
void delay_init()
{
#if SYSTEM_SUPPORT_OS  							//�����Ҫ֧��OS.
	u32 reload;
#endif
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK_DIV8);	//ѡ���ⲿʱ��  HCLK/8
	fac_us=SystemCoreClock/8000000;				//Ϊϵͳʱ�ӵ�1/8  
#if SYSTEM_SUPPORT_OS  							//�����Ҫ֧��OS.
	reload=SystemCoreClock/8000000;				//ÿ���ӵļ������� ��λΪK	   
	reload*=1000000/delay_ostickspersec;		//����delay_ostickspersec�趨���ʱ��
												//reloadΪ24λ�Ĵ���,���ֵ:16777216,��72M��,Լ��1.86s����	
	fac_ms=1000/delay_ostickspersec;			//����OS������ʱ�����ٵ�λ	   

	SysTick->CTRL|=SysTick_CTRL_TICKINT_Msk;   	//����SYSTICK�ж�
	SysTick->LOAD=reload; 						//ÿ1/delay_ostickspersec���ж�һ��	
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk;   	//����SYSTICK    

#else
	fac_ms=(u16)fac_us*1000;					//��OS��,����ÿ��ms��Ҫ��systickʱ����   
#endif
}								    

#if SYSTEM_SUPPORT_OS  							//�����Ҫ֧��OS.
//��ʱnus
//nusΪҪ��ʱ��us��.		    								   
void delay_us(u32 nus)
{		
	u32 ticks;
	u32 told,tnow,tcnt=0;
	u32 reload=SysTick->LOAD;					//LOAD��ֵ	    	 
	ticks=nus*fac_us; 							//��Ҫ�Ľ�����	  		 
	tcnt=0;
	delay_osschedlock();						//��ֹOS���ȣ���ֹ���us��ʱ
	told=SysTick->VAL;        					//�ս���ʱ�ļ�����ֵ
	while(1)
	{
		tnow=SysTick->VAL;	
		if(tnow!=told)
		{	    
			if(tnow<told)tcnt+=told-tnow;		//����ע��һ��SYSTICK��һ���ݼ��ļ������Ϳ�����.
			else tcnt+=reload-tnow+told;	    
			told=tnow;
			if(tcnt>=ticks)break;				//ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳�.
		}  
	};
	delay_osschedunlock();						//�ָ�OS����									    
}
//��ʱnms
//nms:Ҫ��ʱ��ms��
void delay_ms(u16 nms)
{	
	if(delay_osrunning&&delay_osintnesting==0)	//���OS�Ѿ�������,���Ҳ������ж�����(�ж����治���������)	    
	{		 
		if(nms>=fac_ms)							//��ʱ��ʱ�����OS������ʱ������ 
		{ 
   			delay_ostimedly(nms/fac_ms);		//OS��ʱ
		}
		nms%=fac_ms;							//OS�Ѿ��޷��ṩ��ôС����ʱ��,������ͨ��ʽ��ʱ    
	}
	delay_us((u32)(nms*1000));					//��ͨ��ʽ��ʱ  
}
#else //����OSʱ
//��ʱnus
//nusΪҪ��ʱ��us��.		    								   
void delay_us(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us; 					//ʱ�����	  		 
	SysTick->VAL=0x00;        					//��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//��ʼ����	  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));		//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//�رռ�����
	SysTick->VAL =0X00;      					 //��ռ�����	 
}
//��ʱnms
//ע��nms�ķ�Χ
//SysTick->LOADΪ24λ�Ĵ���,����,�����ʱΪ:
//nms<=0xffffff*8*1000/SYSCLK
//SYSCLK��λΪHz,nms��λΪms
//��72M������,nms<=1864 
void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;				//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00;							//��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//��ʼ����  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));		//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//�رռ�����
	SysTick->VAL =0X00;       					//��ռ�����	  	    
} 
#endif 








































