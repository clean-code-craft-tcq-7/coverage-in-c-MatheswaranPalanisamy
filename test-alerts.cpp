#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <stdio.h>
#include <string.h>

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "alerter.h"
#include "alerterMock.h"

extern char *testDest;
extern char *testMsg;

TEST_CASE("Alert Controller for Normal") {
  testDest = NULL;
  testMsg = NULL;

  alertBatteryStatus(TO_CONTROLLER, NORMAL, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 0") == 0);
}

TEST_CASE("Alert Controller for too low") {
  testDest = NULL;
  testMsg = NULL;

  alertBatteryStatus(TO_CONTROLLER, TOO_LOW, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 1") == 0);
}

TEST_CASE("Alert Controller for too high") {
  testDest = NULL;
  testMsg = NULL;

  alertBatteryStatus(TO_CONTROLLER, TOO_HIGH, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 2") == 0);
}

TEST_CASE("Alert email for too high") {
  testDest = NULL;
  testMsg = NULL;

  alertBatteryStatus(TO_EMAIL, TOO_HIGH, mockEmailAlerter);

  REQUIRE(strcmp(testDest, "a.b@c.com"));
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too high") == 0);
}

TEST_CASE("Alert email for too low") {
  testDest = NULL;
  testMsg = NULL;

  alertBatteryStatus(TO_EMAIL, TOO_LOW, mockEmailAlerter);

  REQUIRE(strcmp(testDest, "a.b@c.com"));
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too low") == 0);
}

TEST_CASE("No Alert by email for Normal") {
  testDest = NULL;
  testMsg = NULL;

  alertBatteryStatus(TO_EMAIL, NORMAL, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}

TEST_CASE("No Alert when alert type is invalid while breach is too low") {
  testDest = NULL;
  testMsg = NULL;

  alertBatteryStatus(MAX_ALERTER_TARGETS, TOO_LOW, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}

TEST_CASE("No Alert when alert type is invalid while breach is too high") {
  testDest = NULL;
  testMsg = NULL;

  alertBatteryStatus(MAX_ALERTER_TARGETS, TOO_HIGH, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}
