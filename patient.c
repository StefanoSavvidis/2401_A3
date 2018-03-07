

#include "string.h"
#include "stdio.h"
#include "patient.h"

/********************************************************************/
void printPatient(PersonRec person)

{

    printf("%-15s %-15s\tDepartment:%-1d\tDays in Hospital:%-2d\tSeverity:%-1d\tDaily Cost:%-2d\tTotal Cost:%-4d\n",
    person.firstName, person.familyName,
    person.patient.department, person.patient.numDaysInHospital, person.patient.severity, person.patient.dailyCost,
    (person.patient.dailyCost * person.patient.numDaysInHospital)
    );
    // prints all patient data
}

/********************************************************************/
void printPatients(PersonRec *person, int numRecords)
{
    for (int i = 0; i < numRecords; i++) // itterate through every person
    {
        if (person[i].emplyeeOrPatient) // check if therye a patient
        {
            printPatient(person[i]); // print patient
        }
    }
}


/********************************************************************/
void printPatientSummary(PersonRec *person, int numRecords)
{
    int patientsInDepartment[6] = {0}; // number of patients in department
    int numberOfPatients = 0; // number of patients

    double totalCostDepartment[6] = {0}; // total cost of department
    double totalCost = 0; // total cost

    double totalDailyCostDepartment[6] = {0}; // total daily cost of department
    double totalDailyCost = 0; // total daily cost

    double averageCostDepartment[6] = {0}; // average cost of department
    double averageCost = 0; // average cost

    /* ADD PATIENT DATA TO RELEVANT STORAGE */
    for (int i = 0; i < numRecords; i++)
    {
        if (person[i].emplyeeOrPatient)
        {
            numberOfPatients++;
            patientsInDepartment[person[i].patient.department - 1] += 1;

            totalDailyCost += person[i].patient.dailyCost;
            totalDailyCostDepartment[person[i].patient.department - 1] += person[i].patient.dailyCost;

            totalCost += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
            totalCostDepartment[person[i].patient.department - 1] += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
        }
    }

    /* PRINT ALL COLLECTED DATA */
    averageCost = totalDailyCost/numberOfPatients;
    printf("Total Number of Patients: %-2d\tTotal Cost To-Date: %-6.0f\tAverage Cost Per Patient To-Date: %-4.2f\n", 
    numberOfPatients, totalCost, averageCost);
    printf("\n");
    for (int j = 0; j < 6; j++)
    {
        if (patientsInDepartment[j] > 0)
        {
            averageCostDepartment[j] = totalDailyCostDepartment[j] / patientsInDepartment[j];
        }
        else
        {
            averageCostDepartment[j] = 0;
        }

        printf("Department[%d] Patients: %-2d\tTotal Cost To-Date: %-6.0f\tDaily Cost: %-4.0f\tAverage Cost Per Patient To-Date: %-4.2f\n",
        j + 1, patientsInDepartment[j], totalCostDepartment[j], (patientsInDepartment[j] * averageCostDepartment[j]), averageCostDepartment[j]);
    }
}


/********************************************************************/
void searchPatient(PersonRec *person, int numRecords)
{  
    printf("What is the family name of the patient?\n");
    char lastName[14];
    scanf("%s", lastName); // get searched last name
    printf("\n");
    int countMatches = 0;
    for (int i = 0; i < numRecords; i++)
    {
        if(strcmp(lastName, person[i].familyName) == 0 && person[i].emplyeeOrPatient) {
            printPatient(person[i]);
            countMatches ++;
        }
    }

    if (countMatches == 0) {
        printf("NO MATCHES FOUND");
    }

}
