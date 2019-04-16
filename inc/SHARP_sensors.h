#infdef SHARP_LIB_H_
#define SHARP_LIB_H_

#include "stm32f0xx_hal.h" // Change to preferred STM MCU series

struct sharp{
  GPIO_TypeDef sensorPort;
  uint16_t sensorPin;
};

struct sensorArray{
  uint32_t sensorNo;
  struct sharp* sensors[];
  uint_fast8_t data[];
};

void initSensors(struct sensorArray* array, uint32_t sensorNo, sharp* sensors[]);
void readSensors(struct sensorArray* array);


#endif
