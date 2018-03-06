

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
    printf("2. Summary of Employees Data\n");
    printf("5. Summary of Patients Data\n");
    printf("6. Size of structures\n");
    printf("0. Quit\n%s\n", line);
    scanf("%d", &choice);
    return choice;
}

int main()
{
    struct person person[NUM_RECORDS];
	char rc = 0;


    // populating the array person with data of patients and employees
    populateRecords(person, NUM_RECORDS);
    
    /*
    int menuOption;
    do {
        menuOption = menu();

    } while (menuOption != 0);
    */

    //printEmployees(person, NUM_RECORDS);
    printEmployeesSummary(person, NUM_RECORDS);

    // add code here
    //

    
    return 0;
}



