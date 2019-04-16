/*
  created on Apr 16
  author Kornel Koszela
  TB6612 dual-channel motor driver based

*/

#ifndef MOTORS_LIB_H_
#define MOTORS_LIB_H_

#include "stm32f0xx_hal.h" //Change to preferred STM MCU series

struct motor{
  __IO uint32_t* pwmReg;
  GPIO_TypeDef forwardPort, backwardPort;
  uint16_t forwardPin, backwardPin;
};

struct driver{
  struct motor* motL, motR;
};

void motorInit(struct motor* mot, __IO uint32_t* pwmReg,
                GPIO_TypeDef* Forward_Port, uint16_t Forward_Pin,
                GPIO_TypeDef* Backward_Port, uint16_t Backward_Pin);

void driverInit(struct motor* left, struct motor* right);

void motorMove(struct motor* mot, int16_t power_left, int16_t power_right);

void testDir(struct motor* mot);

#endif
