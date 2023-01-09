#include "typewise-alert.h"
#include "batteryLimits.h"
#include "limitChecker.h"
#include "breachClassifier.h"

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) 
{
  // Get the limits for battery classification
  temperatureLimits tempLimits = getTemperatureLimits(coolingType);
  // Return the breach type 
  return inferBreach(temperatureInC, tempLimits.lowerLimit, tempLimits.upperLimit);
}
