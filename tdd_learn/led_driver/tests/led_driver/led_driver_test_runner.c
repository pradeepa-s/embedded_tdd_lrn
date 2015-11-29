#include "unity_fixture.h"

TEST_GROUP_RUNNER(led_driver)
{
	RUN_TEST_CASE(led_driver, LedsOffAfterCreate);
	RUN_TEST_CASE(led_driver, TurnOnLedOne);
	RUN_TEST_CASE(led_driver, TurnOffLedOne);
	RUN_TEST_CASE(led_driver, TurnOnMultipleLeds);
	RUN_TEST_CASE(led_driver, TurnOffAnyLed);
	RUN_TEST_CASE(led_driver, AllOn);
	RUN_TEST_CASE(led_driver, LedMemoryIsNotReadable);
	RUN_TEST_CASE(led_driver, UpperAndLowerBounds);

	RUN_TEST_CASE(led_driver, OutOfBoundsTurnOnChangesNothing);


	RUN_TEST_CASE(led_driver, OutOfBoundsTurnOffChangesNothing);
}
