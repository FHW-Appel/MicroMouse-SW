/*
 * motor.h
 *
 *  Created on: Jun 27, 2025
 *      Author: alieb
 */


#include "main.h"
#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#ifdef __cplusplus
extern "C" {
#endif

 int16_t grad ;// negative Grad Rückwärts, positive Grad Vorwärts
 int16_t step;
 uint8_t stby ;
 uint8_t stop ;
 const uint16_t PWM ; //(Duty-cycle = 35%)  Strom und Spannungsbegrenzung für den Motor sollte nicht geändert werden, da sonst der Motor kaputt geht und, wenn nur unter genauer Beobachtung
 int8_t currentstep ;
 uint8_t start ;

 int16_t gradr ;// negative Grad Rückwärts, positive Grad Vorwärts
  int16_t stepr;
  uint8_t stbyr ;
  uint8_t stopr ;
  const uint16_t PWMr ; //(Duty-cycle = 35%)  Strom und Spannungsbegrenzung für den Motor sollte nicht geändert werden, da sonst der Motor kaputt geht und, wenn nur unter genauer Beobachtung
  int8_t currentstepr ;
  uint8_t startr ;


#endif /* INC_MOTOR_H_ */
