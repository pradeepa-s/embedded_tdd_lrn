#ifndef _LED_DRIVER_H
#define _LED_DRIVER_H

#include <stdint.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_TurnOn(int led_no);

#endif
