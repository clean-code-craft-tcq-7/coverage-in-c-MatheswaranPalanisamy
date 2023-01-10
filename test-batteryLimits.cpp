#include "test/catch.hpp"
#include "typewise-alert.h"
#include "batteryLimits.h"

TEST_CASE("limits for passive cooling") {
  temperatureLimits tempLimits = getTemperatureLimits(PASSIVE_COOLING);
  REQUIRE(tempLimits.lowerLimit == 0);
  REQUIRE(tempLimits.upperLimit == 35);
}

TEST_CASE("limits for High Active cooling") {
  temperatureLimits tempLimits = getTemperatureLimits(HI_ACTIVE_COOLING);
  REQUIRE(tempLimits.lowerLimit == 0);
  REQUIRE(tempLimits.upperLimit == 45);
}

TEST_CASE("limits for Medium Active cooling") {
  temperatureLimits tempLimits = getTemperatureLimits(MED_ACTIVE_COOLING);
  REQUIRE(tempLimits.lowerLimit == 0);
  REQUIRE(tempLimits.upperLimit == 40);
}

TEST_CASE("limits for Invalid type") {
  temperatureLimits tempLimits = getTemperatureLimits(MAX_COOLING_TYPES);
  REQUIRE(tempLimits.lowerLimit == 0);
  REQUIRE(tempLimits.upperLimit == 0);
}