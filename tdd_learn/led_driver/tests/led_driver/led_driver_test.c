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

TEST(led_driver, TurnOnMultipleLeds)
{
	LedDriver_TurnOn(8);
	LedDriver_TurnOn(9);
	TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

TEST(led_driver, TurnOffAnyLed)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(8);
	TEST_ASSERT_EQUAL_HEX16(0xFF7F, virtualLeds);
}

TEST(led_driver, AllOn)
{
	LedDriver_TurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

TEST(led_driver, LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8);
	TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);
}

TEST(led_driver, UpperAndLowerBounds)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(16);
	TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
}
