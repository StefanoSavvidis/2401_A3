

#include "string.h"
#include "stdio.h"
#include "patient.h"

/********************************************************************/
void printPatient(PersonRec person)

{

    printf("%s %s\tDepartment:%d\tDays in Hospital:%d\tSeverity:%d\tDaily Cost:%d\tTotal Cost:%d\n",
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

    int numberOfPatients = 0;
    double totalCost = 0;
    double totalDailyCost = 0;
    double averageCost = 0;
    for (int i = 0; i < numRecords; i++)
    {
        if (!person[i].emplyeeOrPatient)
        {
            numberOfPatients++;
            totalDailyCost += person[i].patient.dailyCost;
            totalCost += person[i].patient.dailyCost * person[i].patient.numDaysInHospital;
        }
    }

    averageCost = totalDailyCost/numberOfPatients;
    printf("Total Number of Patients:%d\tTotal Cost To-Date:%f\tAverage Cost Per Patient To-Date:%f\n", 
    numberOfPatients, totalCost, averageCost);
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
