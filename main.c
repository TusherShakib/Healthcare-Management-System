#include <stdio.h>
#include <string.h>
#include "auth.c"
#include "patient.c"
#include "appointment.c"
#include "billing.c"
#include "report.c"

// ---------- Admin Dashboard ----------
void adminMenu()
{
    int choice;
    do
    {
        printf("\n=== ADMIN DASHBOARD ===\n");
        printf("1. Add patient\n");
        printf("2. View patients\n");
        printf("3. Generate patient report\n");
        printf("0. Logout\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            viewPatients();
            break;
        case 3:
            generatePatientReport();
            break;
        case 0:
            printf("Admin logged out.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
}

// ---------- Doctor Dashboard ----------
void doctorMenu()
{
    int choice;
    do
    {
        printf("\n=== DOCTOR DASHBOARD ===\n");
        printf("1. View patients\n");
        printf("2. View appointments\n");
        printf("3. Generate appointment report\n");
        printf("0. Logout\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            viewPatients();
            break;
        case 2:
            viewAppointments();
            break;
        case 3:
            generateAppointmentReport();
            break;
        case 0:
            printf("Doctor logged out.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
}

// ---------- Patient Dashboard ----------
void patientMenu()
{
    int choice;
    do
    {
        printf("\n=== PATIENT DASHBOARD ===\n");
        printf("1. Schedule appointment\n");
        printf("2. View appointments\n");
        printf("3. Generate bill\n");
        printf("4. View bills\n");
        printf("0. Logout\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scheduleAppointment();
            break;
        case 2:
            viewAppointments();
            break;
        case 3:
            generateBill();
            break;
        case 4:
            viewBills();
            break;
        case 0:
            printf("Patient logged out.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
}

// ---------- Initial Menu ----------
void initialMenu()
{
    char role[20];
    int choice;
    do
    {
        printf("\n=== HEALTHCARE MANAGEMENT SYSTEM ===\n");
        printf("1. Admin login\n");
        printf("2. Doctor login\n");
        printf("3. Patient login\n");
        printf("4. Register as patient\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2 || choice == 3)
        {
            if (strcmp(secureLogin(role), "Success") == 0)
            {
                if (strcmp(role, "admin") == 0)
                    adminMenu();
                else if (strcmp(role, "doctor") == 0)
                    doctorMenu();
                else
                    patientMenu();
            }
        }
        else if (choice == 4)
        {
            patientSignup();
        }
        else if (choice == 0)
        {
            printf("Goodbye!\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
}

// ---------- main ----------
int main()
{
    initialMenu();
    return 0;
}
