#define MAX_CTRL_ALERT_MSG_LEN     10

void sendToController(BreachType breachType, void (*alerter_func)(char *, char *));
