

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"

#define NUM_RECORDS 20


int menu()
{
    char line[] = "------------------------------------";
    int choice;
    printf("What would you like to do?\n%s\n", line);
    printf("1. Print all employees\n");
    printf("2. Print all patients\n");
    printf("3. Search patient using Family Name\n");
    printf("4. Summary of Employees Data\n");
    printf("5. Summary of Patients Data\n");
    printf("6. Size of structures\n");
    printf("0. Quit\n%s\n", line);
    scanf(" %d", &choice);
    return choice;
}

void sizeOfStructs(struct person *person)
{
    printf("Person Size: %d\n", sizeof(PersonRec));
    printf("Employee Size: %d\n", sizeof(EmployeeRec));
    printf("Patient Size: %d\n", sizeof(PatientRec));
   
}

int main()
{
    struct person person[NUM_RECORDS];
	char rc = 0;

    char command[50];

    strcpy(command, "clear");
    
    // populating the array person with data of patients and employees
    populateRecords(person, NUM_RECORDS);
    
    char choice = ' ';
    char quit = 0;
    int menuOption;
    system(command);
    do {
        menuOption = menu();
        system(command);
        switch(menuOption) {
            case 0: 
                printf("Would you like to quit? (y/n)\n");
                scanf(" %c", &choice);
                if (choice == 'y'){
                    quit = 1;
                }
                break;
            case 1:
                printEmployees(person, NUM_RECORDS);
                break;
            case 2:
                printPatients(person, NUM_RECORDS);
                break;
            case 3:
                searchPatient(person, NUM_RECORDS);
                break;
            case 4:
                printEmployeesSummary(person,NUM_RECORDS);
                break;
            case 5:
                printPatientSummary(person,NUM_RECORDS);
                break;
            case 6:
                sizeOfStructs(person);
                break;
        }
        printf("\n\n");
    } while (quit == 0);
    
    return 0;
}



