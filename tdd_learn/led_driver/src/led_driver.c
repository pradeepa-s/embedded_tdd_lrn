#include <stdio.h>
#include "led_driver.h"

static uint16_t *led_address;

void LedDriver_Create(uint16_t *address)
{
	led_address = address;
	*led_address = 0;
}

void LedDriver_TurnOn(int led_no)
{
	*led_address = 1;
}
