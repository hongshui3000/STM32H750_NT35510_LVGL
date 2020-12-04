#ifndef __LED_H
#define __LED_H

#include "ref.h"

#define LED0(n)		(n? HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET) : HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET))
#define LED0_Toggle (HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_10))

/*
#define LED1(n)		(n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET))
#define LED1_Toggle (HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0))
*/

void LED_Init(void);	 				    
#endif
