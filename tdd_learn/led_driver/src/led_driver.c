#include <stdio.h>
#include "led_driver.h"

static uint16_t convertLedNumberToBit(int led_no);
static void update_hardware(void);

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};

static uint16_t *led_address;
static uint16_t led_image;

void LedDriver_Create(uint16_t *address)
{
	led_address = address;
	led_image = ALL_LEDS_OFF;
	update_hardware();
}

void LedDriver_TurnOn(int led_no)
{
	led_image |= convertLedNumberToBit(led_no);
	update_hardware();
}

void LedDriver_TurnOff(int led_no)
{
	led_image &= ~(convertLedNumberToBit(led_no));
	update_hardware();
}

static uint16_t convertLedNumberToBit(int led_no)
{
	return (1 << (led_no - 1));
}

void LedDriver_TurnAllOn()
{
	led_image = ALL_LEDS_ON;
	update_hardware();
}

static void update_hardware(void)
{
	*led_address = led_image;
}
