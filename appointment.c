#include <stdio.h>
#include <string.h>

#define APPOINT_FILE "appointments.txt"

typedef struct
{
    char patientName[50];
    char doctorName[50];
    char date[20];
    char time[10];
} Appointment;

void scheduleAppointment()
{
    Appointment a;
    FILE *fp = fopen(APPOINT_FILE, "a");

    printf("Patient Name: ");
    scanf(" %[^\n]", a.patientName);
    printf("Doctor Name: ");
    scanf(" %[^\n]", a.doctorName);
    printf("Date (DD-MM-YYYY): ");
    scanf("%s", a.date);
    printf("Time (HH:MM): ");
    scanf("%s", a.time);

    fprintf(fp, "%s,%s,%s,%s\n", a.patientName, a.doctorName, a.date, a.time);
    fclose(fp);
    printf("Appointment scheduled.\n");
}

void viewAppointments()
{
    Appointment a;
    char line[200];
    FILE *fp = fopen(APPOINT_FILE, "r");

    printf("\n--- APPOINTMENTS ---\n");
    if (!fp)
    {
        printf("No appointments found.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%[^,],%[^,],%[^,],%s", a.patientName, a.doctorName, a.date, a.time);
        printf("%s | %s | %s | %s\n", a.patientName, a.doctorName, a.date, a.time);
    }
    fclose(fp);
}
