typedef void (*alerterFunc) (BreachType, void (*alerter_func)(char *, char *));

void alertBatteryStatus(AlertTarget alertTarget, BreachType breachType, void (*alerter_func)(char *, char *));
