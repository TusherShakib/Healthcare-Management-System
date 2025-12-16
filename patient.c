#include <stdio.h>
#include <string.h>

#define PATIENT_FILE "patients.txt"

typedef struct
{
    char name[50];
    int age;
    char gender[10];
    char illness[100];
} Patient;

void addPatient()
{
    Patient p;
    FILE *fp = fopen(PATIENT_FILE, "a");

    printf("Patient Name: ");
    scanf(" %[^\n]", p.name);
    printf("Age: ");
    scanf("%d", &p.age);
    printf("Gender: ");
    scanf("%s", p.gender);
    printf("Illness: ");
    scanf(" %[^\n]", p.illness);

    fprintf(fp, "%s,%d,%s,%s\n", p.name, p.age, p.gender, p.illness);
    fclose(fp);

    printf("Patient added successfully.\n");
}

void viewPatients()
{
    Patient p;
    FILE *fp = fopen(PATIENT_FILE, "r");
    char line[200];

    printf("\n--- PATIENT LIST ---\n");
    if (!fp)
    {
        printf("No patients found.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%[^,],%d,%[^,],%[^\n]", p.name, &p.age, p.gender, p.illness);
        printf("%s | %d | %s | %s\n", p.name, p.age, p.gender, p.illness);
    }
    fclose(fp);
}
