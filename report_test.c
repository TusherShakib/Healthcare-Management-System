// #include "report.c"
// #include <stdio.h>

// int main()
// {
//     int success = 1;

//     printf("Test 1 - generatePatientReport exists: ");
//     void (*ptr1)() = generatePatientReport;
//     if (ptr1 != NULL)
//     {
//         printf("PASS\n");
//     }
//     else
//     {
//         printf("FAIL\n");
//         success = 0;
//     }

//     printf("Test 2 - generateAppointmentReport exists: ");
//     void (*ptr2)() = generateAppointmentReport;
//     if (ptr2 != NULL)
//     {
//         printf("PASS\n");
//     }
//     else
//     {
//         printf("FAIL\n");
//         success = 0;
//     }

//     return success ? 0 : 1;
// }

#include "report.h"
#include <stdio.h>

int main()
{
    int success = 1;

    printf("Test 1 - generatePatientReport exists: ");
    void (*ptr1)() = generatePatientReport;
    if (ptr1 != NULL)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
        success = 0;
    }

    printf("Test 2 - generateAppointmentReport exists: ");
    void (*ptr2)() = generateAppointmentReport;
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
