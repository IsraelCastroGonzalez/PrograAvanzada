#include <stdio.h>
#include "operations.h"

void printTestMessage(int, char *, char *);

int main()
{
    //Test Addition
    int a = 2147483644;
    int b = 2;
    int resultAddition = add(a, b);
    int expectedAddition = a + b;
    printTestMessage(resultAddition == expectedAddition, "Addition Test passed.", "Addition Test failed.");

    //Test Substraction
    int d = 2147483644;
    int f = 2;
    int resultSubstraction = substraction(d, f);
    int expectedSubstraction = d - f;
    printTestMessage(resultSubstraction == expectedSubstraction, "Substraction Test passed.", "Substraction Test failed.");

    return 0;
}

void printTestMessage(int testResult,
                      char *passedMessage,
                      char *failedMessage)
{
    if (testResult)
    {
        printf("%s\n", passedMessage);
    }
    else
    {
        printf("%s\n", failedMessage);
    }
}