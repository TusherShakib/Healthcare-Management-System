#include "auth.c"
#include <stdio.h>

int main()
{
    int success = 1;

    printf("Test 1 - patientSignup exists: ");
    void (*ptr1)() = patientSignup;
    if (ptr1 != NULL)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
        success = 0;
    }

    printf("Test 2 - changePassword exists: ");
    void (*ptr2)() = changePassword;
    if (ptr2 != NULL)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
        success = 0;
    }

    return success ? 0 : 1;
}
