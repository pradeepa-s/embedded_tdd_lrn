#include "unity_fixture.h"

TEST_GROUP(led_driver);

TEST_SETUP(led_driver)
{
    
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
