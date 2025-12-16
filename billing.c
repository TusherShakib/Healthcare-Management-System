#include <stdio.h>

#define BILL_FILE "bills.txt"

typedef struct
{
    char patientName[50];
    float amount;
    char status[20]; // paid/unpaid
} Bill;

void generateBill()
{
    Bill b;
    FILE *fp = fopen(BILL_FILE, "a");

    printf("Patient Name: ");
    scanf(" %[^\n]", b.patientName);
    printf("Amount: ");
    scanf("%f", &b.amount);
    strcpy(b.status, "unpaid");

    fprintf(fp, "%s,%.2f,%s\n", b.patientName, b.amount, b.status);
    fclose(fp);
    printf("Bill generated.\n");
}

void viewBills()
{
    Bill b;
    char line[100];
    FILE *fp = fopen(BILL_FILE, "r");

    printf("\n--- BILLS ---\n");
    if (!fp)
    {
        printf("No bills found.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%[^,],%f,%s", b.patientName, &b.amount, b.status);
        printf("%s | %.2f | %s\n", b.patientName, b.amount, b.status);
    }
    fclose(fp);
}
