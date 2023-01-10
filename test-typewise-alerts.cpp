#include <stdio.h>
#include <string.h>

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "alerterMock.h"

extern char *testDest;
extern char *testMsg;

TEST_CASE("Alert Controller for Passive cooling Normal") {
  testDest = NULL;
  testMsg = NULL;
  BatteryCharacter batteryChar = {"EXIDE", PASSIVE_COOLING};
  checkAndAlert(TO_CONTROLLER, batteryChar, 1, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 0") == 0);
}

TEST_CASE("Alert Controller for passive cooling too low") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", PASSIVE_COOLING};
  checkAndAlert(TO_CONTROLLER, batteryChar, -1, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 1") == 0);
}

TEST_CASE("Alert Controller for passive cooling too high") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", PASSIVE_COOLING};
  checkAndAlert(TO_CONTROLLER, batteryChar, 36, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 2") == 0);
}

TEST_CASE("Alert Controller for Hi Active cooling Normal") {
  testDest = NULL;
  testMsg = NULL;
  BatteryCharacter batteryChar = {"AMARON", HI_ACTIVE_COOLING};
  checkAndAlert(TO_CONTROLLER, batteryChar, 41, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 0") == 0);
}

TEST_CASE("Alert Controller for Hi Active cooling too low") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"AMARON", HI_ACTIVE_COOLING};
  checkAndAlert(TO_CONTROLLER, batteryChar, -5, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 1") == 0);
}

TEST_CASE("Alert Controller for Hi Active cooling too high") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"AMARON", HI_ACTIVE_COOLING};
  checkAndAlert(TO_CONTROLLER, batteryChar, 47, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 2") == 0);
}

TEST_CASE("Alert Controller for Med Active cooling Normal") {
  testDest = NULL;
  testMsg = NULL;
  BatteryCharacter batteryChar = {"EVEREADY", MED_ACTIVE_COOLING};
  checkAndAlert(TO_CONTROLLER, batteryChar, 39, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 0") == 0);
}

TEST_CASE("Alert Controller for Med Active cooling too low") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EVEREADY", MED_ACTIVE_COOLING};
  checkAndAlert(TO_CONTROLLER, batteryChar, -3, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 1") == 0);
}

TEST_CASE("Alert Controller for Med Active cooling too high") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EVEREADY", MED_ACTIVE_COOLING};
  checkAndAlert(TO_CONTROLLER, batteryChar, 41, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 2") == 0);
}

TEST_CASE("Alert email for Passive cooling too high") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", PASSIVE_COOLING};
  checkAndAlert(TO_EMAIL, batteryChar, 36, mockEmailAlerter);
  
  REQUIRE(strcmp(testDest, "a.b@c.com") == 0);
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too high") == 0);
}

TEST_CASE("Alert email for Passive cooling too low") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", PASSIVE_COOLING};
  checkAndAlert(TO_EMAIL, batteryChar, -1, mockEmailAlerter);

  REQUIRE(strcmp(testDest, "a.b@c.com") == 0);
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too low") == 0);
}

TEST_CASE("No Alert by email for Passive cooling Normal") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", PASSIVE_COOLING};
  checkAndAlert(TO_EMAIL, batteryChar, 35, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}

TEST_CASE("Alert email for Hi Active cooling too high") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", HI_ACTIVE_COOLING};
  checkAndAlert(TO_EMAIL, batteryChar, 46, mockEmailAlerter);
  
  REQUIRE(strcmp(testDest, "a.b@c.com") == 0);
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too high") == 0);
}

TEST_CASE("Alert email for Hi Active cooling too low") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", HI_ACTIVE_COOLING};
  checkAndAlert(TO_EMAIL, batteryChar, -1, mockEmailAlerter);

  REQUIRE(strcmp(testDest, "a.b@c.com") == 0);
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too low") == 0);
}

TEST_CASE("No Alert by email for Hi Active cooling Normal") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", HI_ACTIVE_COOLING};
  checkAndAlert(TO_EMAIL, batteryChar, 44, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}

TEST_CASE("Alert email for Med Active cooling too high") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", MED_ACTIVE_COOLING};
  checkAndAlert(TO_EMAIL, batteryChar, 42, mockEmailAlerter);
  
  REQUIRE(strcmp(testDest, "a.b@c.com") == 0);
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too high") == 0);
}

TEST_CASE("Alert email for Med Active cooling too low") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", MED_ACTIVE_COOLING};
  checkAndAlert(TO_EMAIL, batteryChar, -1, mockEmailAlerter);

  REQUIRE(strcmp(testDest, "a.b@c.com") == 0);
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too low") == 0);
}

TEST_CASE("No Alert by email for Med Active cooling Normal") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", MED_ACTIVE_COOLING};
  checkAndAlert(TO_EMAIL, batteryChar, 39, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}

TEST_CASE("No Alert for invalid alert target while breach is too low") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", PASSIVE_COOLING};
  checkAndAlert(MAX_ALERTER_TARGETS, batteryChar, -5, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}

TEST_CASE("No Alert for invalid alert target while breach is too high") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", PASSIVE_COOLING};
  checkAndAlert(MAX_ALERTER_TARGETS, batteryChar, 45, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}

TEST_CASE("No Alert for invalid cooling type while breach is too low") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", MAX_COOLING_TYPES};
  checkAndAlert(TO_EMAIL, batteryChar, -5, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}

TEST_CASE("No Alert for invalid cooling type while breach is too high") {
  testDest = NULL;
  testMsg = NULL;

  BatteryCharacter batteryChar = {"EXIDE", MAX_COOLING_TYPES};
  checkAndAlert(TO_EMAIL, batteryChar, 45, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}
