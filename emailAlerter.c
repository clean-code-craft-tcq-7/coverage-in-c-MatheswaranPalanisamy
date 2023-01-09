#include <stdio.h>

#include "typewise-alert.h"
#include "emailAlerter.h"

const char *alertMessage[MAX_BREACH_TYPES] = 
{
    NULL,
    "Hi, the temperature is too low",
    "Hi, the temperature is too high"
};

const char* recepient = "a.b@c.com";


static char* getAlertMessage(BreachType breachType)
{
    if(breachType < MAX_BREACH_TYPES)
    {
        return alertMessage[breachType];
    }

    return NULL;
}

void sendToEmail(BreachType breachType) {
  char *alertMsg = getAlertMessage(breachType);

  if(alertMsg != NULL)
  {
    printf("To: %s\n", recepient);
    printf("%s\n", getAlertMessage(breachType));
  }
}
