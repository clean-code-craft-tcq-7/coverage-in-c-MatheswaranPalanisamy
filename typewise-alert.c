#include <stdio.h>

#include "typewise-alert.h"
#include "breachClassifier.h"
#include "alerter.h"

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC, void (*alerter_func)(char *, char *)) 
{
  // Classify the breach
  BreachType breachType = classifyTemperatureBreach(batteryChar.coolingType, temperatureInC);
  // Alert the breach
  alertBatteryStatus(alertTarget, breachType, alerter_func);
}
