#include "unity_fixture.h"

TEST_GROUP_RUNNER(led_driver)
{
	RUN_TEST_CASE(led_driver, LedsOffAfterCreate);
	RUN_TEST_CASE(led_driver, TurnOnLedOne);
}
