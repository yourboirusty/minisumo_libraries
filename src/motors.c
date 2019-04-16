
#include "motors.h"
#include <stdlib.h>

void motorInit(struct motor* mot,  __IO uint32_t* pwmReg,
                GPIO_TypeDef* forwardPort, uint16_t forwardPin,
                GPIO_TypeDef* backwardPort, uint16_t backwardPin) {
    mot->pwmReg = pwmReg;
    mot->forwardPort = backwardPort;
    mot->forwardPin = forwardPin;
    mot->backwardPort = backwardPort;
    mot->backwardPin = backwardPin;
}

void driverInit(struct driver*, motors, struct motor* left,
                struct motor* right){
    driver->motL = left;
    driver->motR = right;
}

void motorMove(struct driver* mot, int16_t power_left, int16_t power_right){

  if(power_left == 0){
    HAL_GPIO_WritePin(mot->left->forwardPort, mot->left->forwardPin,0);
    HAL_GPIO_WritePin(mot->left->backwardPort, mot->left->backwardPort, 0);
  }
  else if(power_left>0){
    HAL_GPIO_WritePin(mot->left->forwardPort, mot->left->forwardPin,1);
    HAL_GPIO_WritePin(mot->left->backwardPort, mot->left->backwardPin,0);
  }
  else if(power_left<0){
      HAL_GPIO_WritePin(mot->left->forwardPort, mot->left->forwardPin,0);
      HAL_GPIO_WritePin(mot->left->backwardPort, mot->left->backwardPin,1);
  }


  if(power_right == 0){
    HAL_GPIO_WritePin(mot->right->forwardPort, mot->right->forwardPin,0);
    HAL_GPIO_WritePin(mot->right->backwardPort, mot->right->backwardPort, 0);
  }
  else if(power_right>0){
    HAL_GPIO_WritePin(mot->right->forwardPort, mot->right->forwardPin,1);
    HAL_GPIO_WritePin(mot->right->backwardPort, mot->right->backwardPin,0);
  }
  else if(power_right<0){
      HAL_GPIO_WritePin(mot->right->forwardPort, mot->right->forwardPin,0);
      HAL_GPIO_WritePin(mot->right->backwardPort, mot->right->backwardPin,1);
  }
  mot->left->pwmReg = abs(power_left);
  mot->right->pwmReg = abs(power_right);
}

void testDir(struct motor* mot){
  motorMove(mot, 40, 40);
  HAL_Delay(1000);
  motorMove(mot, 0, 0);
  HAL_Delay(1000);
  motorMove(mot,-40, -40);
  HAL_Delay(1000);
  motorMove(mot,0,0);
}
