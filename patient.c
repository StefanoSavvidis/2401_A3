

#include "string.h"
#include "stdio.h"
#include "patient.h"

/********************************************************************/
void printPatient(PersonRec person)

{

    printf("Department:%hu\tDays in Hospital:%f\tSeverity:%d\tDaily Cost:%d\n",
    person.patient.department, person.patient.numDaysInHospital, person.patient.severity, person.patient.dailyCost);
}

/********************************************************************/
void printPatients(PersonRec *person, int numRecords)
{
    for (int i = 0; i < numRecords; i++)
    {
        if (person[i].emplyeeOrPatient)
        {
            printEmployee(person[i]);
        }
    }
}


/********************************************************************/
void printPatientSummary(PersonRec *person, int numRecords)
{

    // add code 

}


/********************************************************************/
void searchPatient(PersonRec *person, int numRecords)

{

    // add code 

}
