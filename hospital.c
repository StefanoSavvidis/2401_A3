

#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"

#define NUM_RECORDS 20


/* MAIN MENU */
int menu()
{
    char line[] = "------------------------------------";
    int choice;
    //presents user with a list of choices
    printf("What would you like to do?\n%s\n", line);
    printf("1. Print all employees\n");
    printf("2. Print all patients\n");
    printf("3. Search patient using Family Name\n");
    printf("4. Summary of Employees Data\n");
    printf("5. Summary of Patients Data\n");
    printf("6. Size of structures\n");
    printf("0. Quit\n%s\n", line);
    scanf(" %d", &choice); //gets choice from user
    return choice; // returns choice
}

/* SIZE OF STRUCTS */
void sizeOfStructs(struct person *person)
{
    printf("Size of PersonRec: %d\n", sizeof(PersonRec)); // size of person struct
    printf("Size of EmployeeRec: %d\n", sizeof(EmployeeRec)); // size of employee struct
    printf("Size of PatientRec: %d\n", sizeof(PatientRec)); // size of patient stuct
}

int main()
{
    struct person person[NUM_RECORDS];
	char rc = 0;

    char command[50];  // allows me to store a command

    strcpy(command, "clear"); // copy the clear command to the string
    
    // populating the array person with data of patients and employees
    populateRecords(person, NUM_RECORDS);
    
    char choice = ' ';
    char quit = 0;
    int menuOption;

    system(command);
    do {
        menuOption = menu(); // get the users menu choice
        system(command); // clear screen

        switch(menuOption) {
            case 0: 
                printf("Would you like to quit? (y/n)\n");
                scanf(" %c", &choice);
                if (choice == 'y'){ // if user says yes to quitting set quit to true
                    quit = 1;
                }
                break;
            case 1:
                printEmployees(person, NUM_RECORDS); // print all employee data
                break;
            case 2:
                printPatients(person, NUM_RECORDS); // print all patient data
                break;
            case 3:
                searchPatient(person, NUM_RECORDS); // search for patients by last name
                break;
            case 4:
                printEmployeesSummary(person,NUM_RECORDS); // print employees summary
                break;
            case 5:
                printPatientSummary(person,NUM_RECORDS); // print patient summary
                break;
            case 6:
                sizeOfStructs(person); // print size of structs
                break;
        }
        printf("\n\n");
    } while (quit == 0); // loop menu until the user wants to quit
    
    return 0;
}



