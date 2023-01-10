#include "test/catch.hpp"
#include "typewise-alert.h"
#include "emailAlerter.h"


TEST_CASE("Alert email for too high") {
  testDest = NULL;
  testMsg = NULL;

  sendToEmail(TOO_HIGH, mockEmailAlerter);

  REQUIRE(strcmp(testDest, "a.b@c.com") == 0);
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too high") == 0);
}

TEST_CASE("Alert email for too low") {
  testDest = NULL;
  testMsg = NULL;

  sendToEmail(TOO_LOW, mockEmailAlerter);

  REQUIRE(strcmp(testDest, "a.b@c.com") == 0);
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too low") == 0);
}

TEST_CASE("No Alert by email for Normal") {
  testDest = NULL;
  testMsg = NULL;

  sendToEmail(NORMAL, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}

TEST_CASE("No Alert by email for invalid breach type") {
  testDest = NULL;
  testMsg = NULL;

  sendToEmail(MAX_BREACH_TYPES, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}