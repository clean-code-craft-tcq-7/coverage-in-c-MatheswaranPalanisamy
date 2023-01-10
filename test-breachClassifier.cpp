#include "test/catch.hpp"
#include "typewise-alert.h"
#include "breachClassifier.h"

TEST_CASE("too low in passive cooling") {
  BreachType breachType = classifyTemperatureBreach(PASSIVE_COOLING, -5);
  REQUIRE(breachType == TOO_LOW);
}

TEST_CASE("Normal in passive cooling") {
  BreachType breachType = classifyTemperatureBreach(PASSIVE_COOLING, 1);
  REQUIRE(breachType == NORMAL);
}

TEST_CASE("too High in passive cooling") {
  BreachType breachType = classifyTemperatureBreach(PASSIVE_COOLING, 36);
  REQUIRE(breachType == TOO_HIGH);
}

TEST_CASE("too low in High Active cooling") {
  BreachType breachType = classifyTemperatureBreach(HI_ACTIVE_COOLING, -1);
  REQUIRE(breachType == TOO_LOW);
}

TEST_CASE("Normal in High Active cooling") {
  BreachType breachType = classifyTemperatureBreach(HI_ACTIVE_COOLING, 2);
  REQUIRE(breachType == NORMAL);
}

TEST_CASE("too High in High Active cooling") {
  BreachType breachType = classifyTemperatureBreach(HI_ACTIVE_COOLING, 46);
  REQUIRE(breachType == TOO_HIGH);
}

TEST_CASE("too low in Medium Active cooling") {
  BreachType breachType = classifyTemperatureBreach(MED_ACTIVE_COOLING, -3);
  REQUIRE(breachType == TOO_LOW);
}

TEST_CASE("normal in Medium Active cooling") {
  BreachType breachType = classifyTemperatureBreach(MED_ACTIVE_COOLING, 3);
  REQUIRE(breachType == NORMAL);
}

TEST_CASE("too high in Medium Active cooling") {
  BreachType breachType = classifyTemperatureBreach(MED_ACTIVE_COOLING, 41);
  REQUIRE(breachType == TOO_HIGH);
}

TEST_CASE("invalid breach type for invalid cooling type") {
  BreachType breachType = classifyTemperatureBreach(MAX_COOLING_TYPES, 100);
  REQUIRE(breachType == MAX_BREACH_TYPES);
}
