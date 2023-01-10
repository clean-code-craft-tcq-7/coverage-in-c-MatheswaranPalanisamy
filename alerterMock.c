#include <stdio.h>
#include <string.h>

char *testDest = NULL;
char *testMsg = NULL;

static void setAlerterTestOutput(char *dest, char *msg)
{
    testDest = dest;
    testMsg = msg;
}

void mockControllerAlerter(char *dest, char *msg)
{
    setAlerterTestOutput(dest, msg);
    printf("%s\n", testMsg);
}

void mockEmailAlerter(char *dest, char *msg)
{
    setAlerterTestOutput(dest, msg);
    printf("TO: %s\n", testDest);
    printf("%s\n", testMsg);
}
