#ifndef BATTERY_CLASSIFIER_
#define BATTERY_CLASSIFIER_

typedef struct
{
    double lowerLimit;
    double upperLimit;

}temperatureLimits;

temperatureLimits getTemperatureLimits(CoolingType coolingType);

#endif //BATTERY_CLASSIFIER_
