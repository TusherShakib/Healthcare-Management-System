#include "billing.c"
#include <stdio.h>

int main()
{
    int success = 1;

    printf("Test 1 - generateBill exists: ");
    void (*ptr1)() = generateBill;
    if (ptr1 != NULL)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
        success = 0;
    }

    printf("Test 2 - viewBills exists: ");
    void (*ptr2)() = viewBills;
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
