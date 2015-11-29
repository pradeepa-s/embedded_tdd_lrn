#include "unity_fixture.h"
#include "RuntimeErrorStub.h"
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

TEST(led_driver, OutOfBoundsTurnOnChangesNothing)
{
	LedDriver_TurnOn(-1);
	LedDriver_TurnOn(0);
	LedDriver_TurnOn(17);
	LedDriver_TurnOn(3141);
	
	TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(led_driver, OutOfBoundsTurnOffChangesNothing)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(-1);
	LedDriver_TurnOff(0);
	LedDriver_TurnOff(17);
	LedDriver_TurnOff(3141);
	
	TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

TEST(led_driver, OutOfBoundLedOnProducesRuntimeError)
{
	LedDriver_TurnOn(-1);
	TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED ON", RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

TEST(led_driver, OutOfBoundLedOffProducesRuntimeError)
{	
	LedDriver_TurnOff(-1);
	TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED OFF", RuntimeErrorStub_GetLastError());
	TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

TEST(led_driver, IsOn)
{
	TEST_ASSERT_FALSE(LedDriver_IsOn(11));
	LedDriver_TurnOn(11);
	TEST_ASSERT_TRUE(LedDriver_IsOn(11));
}

TEST(led_driver, OutOfBoundsLedsAreAlwaysOffForIsOn)
{
	LedDriver_TurnAllOn();
	TEST_ASSERT_FALSE(LedDriver_IsOn(0));	
	TEST_ASSERT_FALSE(LedDriver_IsOn(17));
	TEST_ASSERT_FALSE(LedDriver_IsOn(-1));
	TEST_ASSERT_FALSE(LedDriver_IsOn(3145));
}

TEST(led_driver, IsOff)
{
	TEST_ASSERT_TRUE(LedDriver_IsOff(14));
	LedDriver_TurnOn(14);
	TEST_ASSERT_FALSE(LedDriver_IsOff(14));
}

TEST(led_driver, OutOfBoundsLedsAreOffForIsOff)
{

}
