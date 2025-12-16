// #include <stdio.h>
// #include <string.h>

// void generatePatientReport()
// {
//     FILE *fp = fopen("patients.txt", "r");
//     char line[200];
//     printf("\n--- PATIENT REPORT ---\n");
//     if (!fp)
//     {
//         printf("No patient data.\n");
//         return;
//     }
//     while (fgets(line, sizeof(line), fp))
//     {
//         printf("%s", line);
//     }
//     fclose(fp);
// }

// void generateAppointmentReport()
// {
//     FILE *fp = fopen("appointments.txt", "r");
//     char line[200];
//     printf("\n--- APPOINTMENT REPORT ---\n");
//     if (!fp)
//     {
//         printf("No appointment data.\n");
//         return;
//     }
//     while (fgets(line, sizeof(line), fp))
//     {
//         printf("%s", line);
//     }
//     fclose(fp);
// }

#include <stdio.h>
#include "report.h"

void generatePatientReport()
{
    FILE *fp = fopen("patients.txt", "r");
    char line[200];
    printf("\n--- PATIENT REPORT ---\n");
    if (!fp)
    {
        printf("No patient data.\n");
        return;
    }
    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }
    fclose(fp);
}

void generateAppointmentReport()
{
    FILE *fp = fopen("appointments.txt", "r");
    char line[200];
    printf("\n--- APPOINTMENT REPORT ---\n");
    if (!fp)
    {
        printf("No appointment data.\n");
        return;
    }
    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }
    fclose(fp);
}
