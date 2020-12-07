/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "dwt.h"
#include "rcc.h"
#include "delay.h"
#include "ssd1963.h"
#include "mpu.h"

//#define ENABLE_DCACHE 1

#define RAM_D1 __attribute__((section(".ram_d1")))
#define RAM_D2 __attribute__((section(".ram_d2")))
#define RAM_D3 __attribute__((section(".ram_d3")))
#define ITCM __attribute__((section(".itcm")))
#define DTCM __attribute__((section(".dtcm")))

#define ALGN4 __attribute__ ((aligned (4)))
#define ALGN8 __attribute__ ((aligned (8)))
#define ALGN32 __attribute__ ((aligned (32)))

/* GPIO SPEED */
#define S_LOW 0
#define S_MED 1
#define S_HI  2
#define S_VH  3

#ifndef GPIO_AFRH_AFRH8
#define GPIO_AFRH_AFRH8_Pos              (0U)
#define GPIO_AFRH_AFRH8_Msk              (0xFU << GPIO_AFRH_AFRH0_Pos)         /*!< 0x0000000F */
#define GPIO_AFRH_AFRH8                  GPIO_AFRH_AFRH0_Msk
#define GPIO_AFRH_AFRH9_Pos              (4U)
#define GPIO_AFRH_AFRH9_Msk              (0xFU << GPIO_AFRH_AFRH1_Pos)         /*!< 0x000000F0 */
#define GPIO_AFRH_AFRH9                  GPIO_AFRH_AFRH1_Msk
#define GPIO_AFRH_AFRH10_Pos              (8U)
#define GPIO_AFRH_AFRH10_Msk              (0xFU << GPIO_AFRH_AFRH2_Pos)         /*!< 0x00000F00 */
#define GPIO_AFRH_AFRH10                  GPIO_AFRH_AFRH2_Msk
#define GPIO_AFRH_AFRH11_Pos              (12U)
#define GPIO_AFRH_AFRH11_Msk              (0xFU << GPIO_AFRH_AFRH3_Pos)         /*!< 0x0000F000 */
#define GPIO_AFRH_AFRH11                  GPIO_AFRH_AFRH3_Msk
#define GPIO_AFRH_AFRH12_Pos              (16U)
#define GPIO_AFRH_AFRH12_Msk              (0xFU << GPIO_AFRH_AFRH4_Pos)         /*!< 0x000F0000 */
#define GPIO_AFRH_AFRH12                  GPIO_AFRH_AFRH4_Msk
#define GPIO_AFRH_AFRH13_Pos              (20U)
#define GPIO_AFRH_AFRH13_Msk              (0xFU << GPIO_AFRH_AFRH5_Pos)         /*!< 0x00F00000 */
#define GPIO_AFRH_AFRH13                  GPIO_AFRH_AFRH5_Msk
#define GPIO_AFRH_AFRH14_Pos              (24U)
#define GPIO_AFRH_AFRH14_Msk              (0xFU << GPIO_AFRH_AFRH6_Pos)         /*!< 0x0F000000 */
#define GPIO_AFRH_AFRH14                  GPIO_AFRH_AFRH6_Msk
#define GPIO_AFRH_AFRH15_Pos              (28U)
#define GPIO_AFRH_AFRH15_Msk              (0xFU << GPIO_AFRH_AFRH7_Pos)         /*!< 0xF0000000 */
#define GPIO_AFRH_AFRH15                  GPIO_AFRH_AFRH7_Msk
#endif




#define FSMC_DATA_SPEED     S_VH
#define LCD_RST_ON          GPIOD->BSRR = GPIO_BSRR_BR12
#define LCD_RST_OFF         GPIOD->BSRR = GPIO_BSRR_BS12

//#define FMC_REMAP_BANK

#ifdef FMC_REMAP_BANK
#define LCD_DATA    		    ((uint32_t)0xC0020000)
#define LCD_REG   		  	    ((uint32_t)0xC0000000)
#else
#define LCD_DATA    		    ((uint32_t)0x60020000)
#define LCD_REG   		  	    ((uint32_t)0x60000000)
#endif

/*
Таймиги
*/
#define FSMC_DATA_SETUP 2
#define FSMC_ADDR_SETUP 14

/*
Эти тайминги в данной конфигурации не работают
Нужны только для установки корректного значения в регистре
*/
#define FSMC_DATA_Lat   1
#define FSMC_ADDR_HOLD  1
#define FSMC_CLK_DIV    15

#define DISP_WIDTH  800
#define DISP_HEIGHT 480




void timer2_init(void);
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TP_CS_Pin GPIO_PIN_11
#define TP_CS_GPIO_Port GPIOB
#define TP_IRQ_Pin GPIO_PIN_12
#define TP_IRQ_GPIO_Port GPIOB
#define BL_Pin GPIO_PIN_13
#define BL_GPIO_Port GPIOD
#define LCD_RST_Pin GPIO_PIN_6
#define LCD_RST_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
