#ifndef __MYIIC_H
#define __MYIIC_H

#include "ref.h"
  	   		   
#define SDA_IN()  {GPIOH->MODER&=~(3<<(5*2));GPIOH->MODER|=0<<5*2;}
#define SDA_OUT() {GPIOH->MODER&=~(3<<(5*2));GPIOH->MODER|=1<<5*2;}

/* они переписывают PH4,5 для I2C (SCL = PH4; SDA = PH5) */

#define IIC_SCL(n)  (n? HAL_GPIO_WritePin(GPIOH, GPIO_PIN_4, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOH, GPIO_PIN_4, GPIO_PIN_RESET)) //SCL
#define IIC_SDA(n)  (n? HAL_GPIO_WritePin(GPIOH, GPIO_PIN_5, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOH, GPIO_PIN_5, GPIO_PIN_RESET)) //SDA
#define READ_SDA    HAL_GPIO_ReadPin(GPIOH, GPIO_PIN_5)

void IIC_Init(void);
void IIC_Start(void);
void IIC_Stop(void);
void IIC_Send_Byte(uint8_t txd);
uint8_t IIC_Read_Byte(unsigned char ack);
uint8_t IIC_Wait_Ack(void);
void IIC_Ack(void);
void IIC_NAck(void);

void IIC_Write_One_Byte(uint8_t daddr, uint8_t addr, uint8_t data);
uint8_t IIC_Read_One_Byte(uint8_t daddr, uint8_t addr);
#endif

