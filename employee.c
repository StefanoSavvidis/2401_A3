#include "employee.h"
#include "stdio.h"

void printEmployee(PersonRec person)

{
    printf("Department:%hu\tSalary:%f\tPosition:%d\tYtoears of service:%hu\n",
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
    int numberOfEmployees = 0;
    double totalSalary=0;
    double averageSalary=0;
    for (int i = 0; i < numRecords; i++)
    {
        if (!person[i].emplyeeOrPatient)
        {
            numberOfEmployees++;
            totalSalary += person[i].emp.salary;
        }
    }

    averageSalary = totalSalary/numberOfEmployees;
    printf("%d  %f  %f", numberOfEmployees, totalSalary, averageSalary);
}
