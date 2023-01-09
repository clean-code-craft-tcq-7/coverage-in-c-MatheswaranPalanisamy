#include <stdio.h>

#include "typewise-alert.h"
#include "batteryLimits.h"

temperatureLimits BatteryTemperatureLimits[MAX_COOLING_TYPES] = 
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
    if(coolingType < MAX_COOLING_TYPES)
    {
        temp_limits.lowerLimit = BatteryTemperatureLimits[coolingType].lowerLimit;
        temp_limits.upperLimit = BatteryTemperatureLimits[coolingType].upperLimit;
    }

    return temp_limits;
}
