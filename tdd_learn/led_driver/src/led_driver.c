#include <stdio.h>
#include "led_driver.h"

static uint16_t convertLedNumberToBit(int led_no);
static uint16_t *led_address;

void LedDriver_Create(uint16_t *address)
{
	led_address = address;
	*led_address = 0;
}

void LedDriver_TurnOn(int led_no)
{
	*led_address |= convertLedNumberToBit(led_no);
}

void LedDriver_TurnOff(int led_no)
{
	*led_address = 0;
}

static uint16_t convertLedNumberToBit(int led_no)
{
	return (1 << (led_no - 1));
}

void LedDriver_TurnAllOn()
{
}
