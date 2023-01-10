#define MAX_EMAIL_ID_STR_LEN    50
#define MAX_EMAIL_ALERT_MSG_LEN     100

void sendToEmail(BreachType breachType, void (*alerter_func)(char *, char *));
