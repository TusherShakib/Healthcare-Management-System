#include "appointment.c"
#include <stdio.h>

int main()
{
    int success = 1;

    printf("Test 1 - scheduleAppointment exists: ");
    void (*ptr1)() = scheduleAppointment;
    if (ptr1 != NULL)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
        success = 0;
    }

    printf("Test 2 - viewAppointments exists: ");
    void (*ptr2)() = viewAppointments;
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
