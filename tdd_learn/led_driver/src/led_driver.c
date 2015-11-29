#include <stdio.h>
#include "led_driver.h"

static uint16_t convertLedNumberToBit(int led_no);
static void update_hardware(void);
static uint8_t is_led_outofbound(uint16_t led_no);

enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum {FIRST_LED = 1, FINAL_LED = 16};

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
	if(is_led_outofbound(led_no)){
		RUNTIME_ERROR("LED Driver: out-of-bounds LED ON", -1);
		return;
	}

	led_image |= convertLedNumberToBit(led_no);
	update_hardware();
}

void LedDriver_TurnOff(int led_no)
{
	if(is_led_outofbound(led_no)){
		RUNTIME_ERROR("LED Driver: out-of-bounds LED OFF", -1);
		return;
	}

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

uint8_t LedDriver_IsOn(int led_no)
{
	return 0;
}

static void update_hardware(void)
{
	*led_address = led_image;
}

static uint8_t is_led_outofbound(uint16_t led_no)
{
	return (led_no < FIRST_LED || led_no > FINAL_LED);
}
