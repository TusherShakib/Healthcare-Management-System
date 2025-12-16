#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define USER_FILE "users.txt"

typedef struct
{
    char username[50];
    char password[50];
    char role[20]; // admin, doctor, patient
} User;

void patientSignup()
{
    User u;
    FILE *fp = fopen(USER_FILE, "a");

    printf("\n=== PATIENT SIGN UP ===\n");
    strcpy(u.role, "patient");

    printf("Enter username: ");
    scanf("%s", u.username);
    printf("Enter password: ");
    scanf("%s", u.password);

    fprintf(fp, "%s,%s,%s\n", u.username, u.password, u.role);
    fclose(fp);

    printf("Registration successful! You can login now.\n");
}

char *secureLogin(char *role)
{
    char username[50], password[50];
    User u;
    FILE *fp;

    fp = fopen(USER_FILE, "r");
    if (!fp)
    {
        fp = fopen(USER_FILE, "w");
        fprintf(fp, "admin,admin123,admin\n");
        fprintf(fp, "doctor,doc123,doctor\n");
        fclose(fp);
    }

    printf("\n=== LOGIN ===\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    fp = fopen(USER_FILE, "r");
    int authenticated = 0;
    while (fscanf(fp, "%[^,],%[^,],%s\n", u.username, u.password, u.role) != EOF)
    {
        if (strcmp(username, u.username) == 0 && strcmp(password, u.password) == 0)
        {
            strcpy(role, u.role);
            authenticated = 1;
            printf("Welcome %s (%s)\n", username, u.role);
            break;
        }
    }
    fclose(fp);
    return authenticated ? "Success" : "Failure";
}

void changePassword()
{
    char username[50], oldPass[50], newPass[50];
    User u;
    FILE *fp = fopen(USER_FILE, "r");
    FILE *temp = fopen("temp_users.txt", "w");
    int found = 0;

    printf("Username: ");
    scanf("%s", username);
    printf("Old Password: ");
    scanf("%s", oldPass);
    printf("New Password: ");
    scanf("%s", newPass);

    while (fscanf(fp, "%[^,],%[^,],%s\n", u.username, u.password, u.role) != EOF)
    {
        if (strcmp(username, u.username) == 0 && strcmp(oldPass, u.password) == 0)
        {
            strcpy(u.password, newPass);
            found = 1;
        }
        fprintf(temp, "%s,%s,%s\n", u.username, u.password, u.role);
    }
    fclose(fp);
    fclose(temp);

    if (found)
    {
        remove(USER_FILE);
        rename("temp_users.txt", USER_FILE);
        printf("Password updated successfully.\n");
    }
    else
    {
        remove("temp_users.txt");
        printf("Invalid username or password.\n");
    }
}
