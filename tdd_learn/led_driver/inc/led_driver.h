#ifndef _LED_DRIVER_H
#define _LED_DRIVER_H

#include <stdint.h>
#include "RuntimeError.h"

void LedDriver_Create(uint16_t *address);
void LedDriver_TurnOn(int led_no);
void LedDriver_TurnOff(int led_no);
void LedDriver_TurnAllOn();
uint8_t LedDriver_IsOn(int led_no);
uint8_t LedDriver_IsOff(int led_no);

#endif
