#include <stdio.h>
#include <string.h>
#include "typewise-alert.h"
#include "controllerAlerter.h"

const unsigned short header = 0xfeed;
char alertMsg[MAX_CTRL_ALERT_MSG_LEN];

static char *getAlertMessage(BreachType breachType)
{
  if(breachType < MAX_BREACH_TYPES)
  {
    memset(alertMsg, 0, MAX_CTRL_ALERT_MSG_LEN);
    sprintf(alertMsg, "%x : %x", header, breachType);
    return alertMsg;
  }

  return NULL;
}

void sendToController(BreachType breachType, void (*alerter_func)(char *, char *)) 
{
  alerter_func(NULL, getAlertMessage(breachType));
}
