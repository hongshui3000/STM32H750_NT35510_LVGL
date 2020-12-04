#include "led.h"

/*****************************************************************************
 * @name       :void LED_Init(void)
 * @function   :Initialize LED GPIO
 * @parameters :None
 * @retvalue   :None
******************************************************************************/	 

void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOC_CLK_ENABLE();
	
    GPIO_Initure.Pin = GPIO_PIN_10; //PC10
    GPIO_Initure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Initure.Pull = GPIO_PULLUP;
    GPIO_Initure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    HAL_GPIO_Init(GPIOC, &GPIO_Initure);
	
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
}