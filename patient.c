

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
}

/********************************************************************/
void printPatients(PersonRec *person, int numRecords)
{
    for (int i = 0; i < numRecords; i++)
    {
        if (person[i].emplyeeOrPatient)
        {
            printPatient(person[i]);
        }
    }
}


/********************************************************************/
void printPatientSummary(PersonRec *person, int numRecords)
{
    int patientsInDepartment[6] = {0};
    int numberOfPatients = 0;

    double totalCostDepartment[6] = {0};
    double totalCost = 0;

    double totalDailyCostDepartment[6] = {0};
    double totalDailyCost = 0;

    double averageCostDepartment[6] = {0};
    double averageCost = 0;

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
    scanf("%s", lastName);
    printf("\n");
    for (int i = 0; i < numRecords; i++)
    {
        if(strcmp(lastName, person[i].familyName) == 0 && person[i].emplyeeOrPatient) {
            printPatient(person[i]);
        }
    }

}
