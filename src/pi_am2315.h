//
// Created by Henry Seurer on 10/16/16.
//

#include <stdbool.h>
#include "version_config.h"

#ifndef PI_AM2315_PI_AM2315_H
#define PI_AM2315_PI_AM2315_H

int pi_am2315_open();
bool pi_am2315_readTemperatureAndHumidity(int fd, float *temperature, float *humidity);

#endif //PI_AM2315_PI_AM2315_H
