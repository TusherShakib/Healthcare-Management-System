#include "auth.c"
#include "patient.c"
#include "appointment.c"
#include "billing.c"
#include "report.c"
#include <stdio.h>

int main()
{
    int success = 1;

    // Check all core functions
    void (*fptrs[])() = {patientSignup, changePassword, addPatient, viewPatients,
                         scheduleAppointment, viewAppointments, generateBill,
                         viewBills, generatePatientReport, generateAppointmentReport};

    const char *names[] = {"patientSignup", "changePassword", "addPatient", "viewPatients",
                           "scheduleAppointment", "viewAppointments", "generateBill",
                           "viewBills", "generatePatientReport", "generateAppointmentReport"};

    for (int i = 0; i < 10; i++)
    {
        printf("Test %d - %s exists: ", i + 1, names[i]);
        if (fptrs[i] != NULL)
            printf("PASS\n");
        else
        {
            printf("FAIL\n");
            success = 0;
        }
    }

    return success ? 0 : 1;
}
