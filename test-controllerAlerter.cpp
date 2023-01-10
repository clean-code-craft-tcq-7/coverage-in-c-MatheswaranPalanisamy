#include "test/catch.hpp"
#include "typewise-alert.h"
#include "controllerAlerter.h"

TEST_CASE("Alert Controller for Normal") {
  testDest = NULL;
  testMsg = NULL;

  sendToController(NORMAL, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 0") == 0);
}

TEST_CASE("Alert Controller for too low") {
  testDest = NULL;
  testMsg = NULL;

  sendToController(TOO_LOW, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 1") == 0);
}

TEST_CASE("Alert Controller for too high") {
  testDest = NULL;
  testMsg = NULL;

  sendToController(TOO_HIGH, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(strcmp(testMsg, "feed : 2") == 0);
}

TEST_CASE("No Alert Controller for invalid breach type") {
  testDest = NULL;
  testMsg = NULL;

  sendToController(MAX_BREACH_TYPES, mockControllerAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}
