#include <stdio.h>
#include "typewise-alert.h"
#include "controllerAlerter.h"

void sendToController(BreachType breachType) 
{
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}
