
#include "SHARP_sensors.h"

void initSensors(struct sensorArray* array, uint32_t sensorNo, sharp* sensors[]){
  array->sensorNo = sensorNo;
  array->sensors = sensors;
  array->data=malloc(sensorNo * sizeof(uint_fast8_t));
}

void readSensors(struct sensorArray* array){
  for(uint32_t i=0; i<array->sensorNo; i++){
    HAL_GPIO_ReadPin(array->sensors[i]->sensorPort,
                     array->sensors[i]->sensorPin,
                     array->data[i]);
  }
}
