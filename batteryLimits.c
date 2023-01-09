#include <stdio.h>

#include "typewise-alert.h"
#include "batteryLimits.h"

const temperatureLimits BatteryTemperatureLimits[MAX_COOLING_TYPES] = 
{
    {
        .lowerLimit = 0,
        .upperLimit = 35,
    },
    {
        .lowerLimit = 0,
        .upperLimit = 45,
    },
    {
        .lowerLimit = 0,
        .upperLimit = 40,
    },
};

temperatureLimits getTemperatureLimits(CoolingType coolingType)
{
    temperatureLimits temp_limits = {0, 0};
    // check for validity of battery cooling type
    if(coolingType < MAX_COOLING_TYPES)
    {
        // Fill the limits
        temp_limits.lowerLimit = BatteryTemperatureLimits[coolingType].lowerLimit;
        temp_limits.upperLimit = BatteryTemperatureLimits[coolingType].upperLimit;
    }

    // Return limits
    return temp_limits;
}
