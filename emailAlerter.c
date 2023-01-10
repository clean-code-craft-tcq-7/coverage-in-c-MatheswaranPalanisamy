#include <stdio.h>
#include <string.h>
#include "typewise-alert.h"
#include "emailAlerter.h"

const char *alertMessage[MAX_BREACH_TYPES] = 
{
    NULL,
    "Hi, the temperature is too low",
    "Hi, the temperature is too high"
};

// If needed, an API can be provided for the user to change the email id in the field
char recepient[MAX_EMAIL_ID_STR_LEN] = "a.b@c.com";


static const char* getAlertMessage(BreachType breachType)
{
    if(breachType < MAX_BREACH_TYPES)
    {
        return alertMessage[breachType];
    }

    return NULL;
}

void sendToEmail(BreachType breachType, void (*alerterFunc)(char *, char *)) {
  const char *alertMsg = getAlertMessage(breachType);

  if(alertMsg != NULL)
  {
    alerterFunc(recepient, alertMsg);
  }
}

#if 0
void setRecepient(char *emailId, int len)
{
  memset(recepient, 0, MAX_EMAIL_ID_STR_LEN);
  strncpy(recepient, emailId, len);
}
#endif