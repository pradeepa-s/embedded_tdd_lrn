#include "unity_fixture.h"

static void RunAllTests(void)
{
	RUN_TEST_GROUP(group1);
}

int main(int argc, char * argv[])
{
return UnityMain(argc, argv, RunAllTests);
}
