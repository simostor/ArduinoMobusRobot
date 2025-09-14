#include <unity.h>
#include "Watchdog.h"

// Test: watchdog should trip after timeout if heartbeat doesn't change
void test_watchdog_times_out(void) {
    Watchdog wd;
    wd.setTimeout(100);      // 100 ms timeout

    // first tick at time=0 with PLC heartbeat=1
    wd.tick(1, 0);
    TEST_ASSERT_TRUE(wd.isOk());   // should be alive initially

    // simulate 200 ms later, but heartbeat hasn't changed
    wd.tick(1, 200);
    TEST_ASSERT_FALSE(wd.isOk());  // should have timed out
}

// Test: watchdog stays ok if heartbeat increments within timeout
void test_watchdog_heartbeat_ok(void) {
    Watchdog wd;
    wd.setTimeout(100);

    wd.tick(1, 0);
    TEST_ASSERT_TRUE(wd.isOk());

    // 50 ms later, PLC heartbeat increments
    wd.tick(2, 50);
    TEST_ASSERT_TRUE(wd.isOk());
}

// Test: wrap-around should not break it
void test_watchdog_wraparound(void) {
    Watchdog wd;
    wd.setTimeout(100);

    // lastHb near max uint16_t
    wd.tick(65535, 0);
    TEST_ASSERT_TRUE(wd.isOk());

    // 10 ms later, plc heartbeat wrapped to 0
    wd.tick(0, 10);
    TEST_ASSERT_TRUE(wd.isOk());
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_watchdog_times_out);
    RUN_TEST(test_watchdog_heartbeat_ok);
    RUN_TEST(test_watchdog_wraparound);
    return UNITY_END();
}
