#include <stdio.h>
#include <string.h>

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "emailAlerter.h"
#include "alerterMock.h"

extern char *testDest;
extern char *testMsg;

TEST_CASE("email Alert for too high") {
  testDest = NULL;
  testMsg = NULL;

  sendToEmail(TOO_HIGH, mockEmailAlerter);

  REQUIRE(strcmp(testDest, "a.b@c.com") == 0);
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too high") == 0);
}

TEST_CASE("email Alert for too low") {
  testDest = NULL;
  testMsg = NULL;

  sendToEmail(TOO_LOW, mockEmailAlerter);

  REQUIRE(strcmp(testDest, "a.b@c.com") == 0);
  REQUIRE(strcmp(testMsg, "Hi, the temperature is too low") == 0);
}

TEST_CASE("No email Alert for Normal") {
  testDest = NULL;
  testMsg = NULL;

  sendToEmail(NORMAL, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}

TEST_CASE("No email Alert for invalid breach type") {
  testDest = NULL;
  testMsg = NULL;

  sendToEmail(MAX_BREACH_TYPES, mockEmailAlerter);

  REQUIRE(testDest == NULL);
  REQUIRE(testMsg == NULL);
}
