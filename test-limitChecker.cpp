#include "test/catch.hpp"
#include "typewise-alert.h"
#include "limitChecker.h"

TEST_CASE("Too low when value less than lower limit") {
  BreachType breachType = inferBreach(-1, 0, 10);
  REQUIRE(breachType == TOO_LOW);
}

TEST_CASE("Normal when value equal to lower limit") {
  BreachType breachType = inferBreach(0, 0, 10);
  REQUIRE(breachType == NORMAL);
}

TEST_CASE("Normal when value greater than lower limit and less than upper limit") {
  BreachType breachType = inferBreach(2, 0, 10);
  REQUIRE(breachType == NORMAL);
}

TEST_CASE("Normal when value equal to upper limit") {
  BreachType breachType = inferBreach(10, 0, 10);
  REQUIRE(breachType == NORMAL);
}

TEST_CASE("Normal when value greater than upper limit") {
  BreachType breachType = inferBreach(11, 0, 10);
  REQUIRE(breachType == TOO_HIGH);
}
