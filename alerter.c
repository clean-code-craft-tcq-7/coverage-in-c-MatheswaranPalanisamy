#include <stdio.h>
#include "typewise-alert.h"
#include "alerter.h"
#include "controllerAlerter.h"
#include "emailAlerter.h"

const alerterFunc alerterFunctions[MAX_ALERTER_TARGETS] = 
{
    sendToController,
    sendToEmail
};

void alertBatterStatus(AlertTarget alertTarget, BreachType breachType)
{
  if(alertTarget < MAX_ALERTER_TARGETS)
  {
    alerterFunctions[alertTarget](breachType);
  }
}
