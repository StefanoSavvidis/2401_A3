#include "employee.h"
#include "stdio.h"

void printEmployee(PersonRec person)

{
    printf("Department:%hu\tSalary:%f\tPosition:%d\tYears of service:%hu\n",
    person.emp.department, person.emp.salary, person.emp.position, person.emp.yearsService);
}

void printEmployees(PersonRec *person, int numRecords)
{
    
    for(int i = 0; i < numRecords; i++) {
        if (!person[i].emplyeeOrPatient) {
            printEmployee(person[i]);
        }
        
    }
}


void printEmployeesSummary(PersonRec *person, int numRecords)
{

    // add code

}
