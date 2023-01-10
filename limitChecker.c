#include "typewise-alert.h"
#include "limitChecker.h"

BreachType inferBreach(double value, double lowerLimit, double upperLimit)
{
  // Check lower limit breach
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  // Check upper limit breach
  if(value > upperLimit) {
    return TOO_HIGH;
  }

  // Return normal when temperature within limit
  return NORMAL;
}
