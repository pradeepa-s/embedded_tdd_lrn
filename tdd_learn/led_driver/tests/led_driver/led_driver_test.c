#include "unity_fixture.h"
#include "led_driver.h"

TEST_GROUP(led_driver);

static uint16_t virtualLeds;

TEST_SETUP(led_driver)
{
	LedDriver_Create(&virtualLeds);    
}

TEST_TEAR_DOWN(led_driver)
{
}

TEST(led_driver, LedsOffAfterCreate)
{
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(led_driver, TurnOnLedOne)
{
	LedDriver_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(led_driver, TurnOffLedOne)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}
