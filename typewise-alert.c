#include <stdio.h>

#include "typewise-alert.h"
#include "breachClassifier.h"
#include "alerter.h"

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
  // Classify the breach
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  // Alert the breach
  alertBatterStatus(alertTarget, breachType);
}
