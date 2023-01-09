#include <stdio.h>

#include "typewise-alert.h"
#include "breachClassifier.h"
#include "alerter.h"

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);

  alertBatterStatus(alertTarget, breachType);
}
