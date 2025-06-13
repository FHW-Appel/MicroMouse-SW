/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
     PA7   ------> S_TIM21_ETR
     PA15   ------> USART2_RX
     PB3   ------> SPI1_SCK
     PB5   ------> SPI1_MOSI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, display_out1_Pin|motor_ra1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, motor_rb2_Pin|motor_rstby_Pin|motor_ra2_Pin|motor_stby_Pin
                          |motor_rb1_Pin|motor_la1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, motor_la2_Pin|display_out2_Pin|motor_lb2_Pin|motor_lb1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : display_out1_Pin motor_ra1_Pin */
  GPIO_InitStruct.Pin = display_out1_Pin|motor_ra1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : motor_rb2_Pin motor_rstby_Pin motor_ra2_Pin motor_stby_Pin
                           motor_rb1_Pin motor_la1_Pin */
  GPIO_InitStruct.Pin = motor_rb2_Pin|motor_rstby_Pin|motor_ra2_Pin|motor_stby_Pin
                          |motor_rb1_Pin|motor_la1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : motor_rpwm_Pin */
  GPIO_InitStruct.Pin = motor_rpwm_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_TIM21;
  HAL_GPIO_Init(motor_rpwm_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : motor_la2_Pin display_out2_Pin motor_lb2_Pin motor_lb1_Pin */
  GPIO_InitStruct.Pin = motor_la2_Pin|display_out2_Pin|motor_lb2_Pin|motor_lb1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : VCP_RX_Pin */
  GPIO_InitStruct.Pin = VCP_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF4_USART2;
  HAL_GPIO_Init(VCP_RX_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : display_clock_Pin display_data_Pin */
  GPIO_InitStruct.Pin = display_clock_Pin|display_data_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF0_SPI1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
