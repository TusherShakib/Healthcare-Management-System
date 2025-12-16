#include "patient.c"
#include <stdio.h>

int main()
{
    int success = 1;

    printf("Test 1 - addPatient exists: ");
    void (*ptr1)() = addPatient;
    if (ptr1 != NULL)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
        success = 0;
    }

    printf("Test 2 - viewPatients exists: ");
    void (*ptr2)() = viewPatients;
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
