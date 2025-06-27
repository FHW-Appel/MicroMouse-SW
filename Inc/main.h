/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
void GyroSensor(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define display_out1_Pin GPIO_PIN_14
#define display_out1_GPIO_Port GPIOC
#define motor_ra1_Pin GPIO_PIN_15
#define motor_ra1_GPIO_Port GPIOC
#define inf_in1_Pin GPIO_PIN_0
#define inf_in1_GPIO_Port GPIOA
#define inf_in2_Pin GPIO_PIN_1
#define inf_in2_GPIO_Port GPIOA
#define inf_in3_Pin GPIO_PIN_2
#define inf_in3_GPIO_Port GPIOA
#define motor_rb2_Pin GPIO_PIN_3
#define motor_rb2_GPIO_Port GPIOA
#define gyro_clock_Pin GPIO_PIN_4
#define gyro_clock_GPIO_Port GPIOA
#define motor_rstby_Pin GPIO_PIN_5
#define motor_rstby_GPIO_Port GPIOA
#define inf_in4_Pin GPIO_PIN_6
#define inf_in4_GPIO_Port GPIOA
#define motor_rpwm_Pin GPIO_PIN_7
#define motor_rpwm_GPIO_Port GPIOA
#define motor_la2_Pin GPIO_PIN_0
#define motor_la2_GPIO_Port GPIOB
#define motor_lpwm_Pin GPIO_PIN_1
#define motor_lpwm_GPIO_Port GPIOB
#define motor_ra2_Pin GPIO_PIN_8
#define motor_ra2_GPIO_Port GPIOA
#define motor_stby_Pin GPIO_PIN_9
#define motor_stby_GPIO_Port GPIOA
#define gyro_data_Pin GPIO_PIN_10
#define gyro_data_GPIO_Port GPIOA
#define motor_rb1_Pin GPIO_PIN_11
#define motor_rb1_GPIO_Port GPIOA
#define motor_la1_Pin GPIO_PIN_12
#define motor_la1_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define VCP_RX_Pin GPIO_PIN_15
#define VCP_RX_GPIO_Port GPIOA
#define display_clock_Pin GPIO_PIN_3
#define display_clock_GPIO_Port GPIOB
#define display_out2_Pin GPIO_PIN_4
#define display_out2_GPIO_Port GPIOB
#define display_data_Pin GPIO_PIN_5
#define display_data_GPIO_Port GPIOB
#define motor_lb2_Pin GPIO_PIN_6
#define motor_lb2_GPIO_Port GPIOB
#define motor_lb1_Pin GPIO_PIN_7
#define motor_lb1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
