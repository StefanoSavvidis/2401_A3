#include "employee.h"
#include "stdio.h"

void printEmployee(PersonRec person)

{
    printf("%-15s %-15s\tDepartment:%-1d\tSalary:%-9.2f\tPosition:%-1d\tYears of service:%-2d\n",
    person.firstName, person.familyName,
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
    int employeesInPosition[4] = {0};
    int numberOfEmployees = 0;
    double totalSalaryPosition[4] = {0};
    double totalSalary=0;
    double averageSalary=0;
    double averageSalaryPosition[4];
    for (int i = 0; i < numRecords; i++)
    {
        if (!person[i].emplyeeOrPatient)
        {
            numberOfEmployees++;
            totalSalary += person[i].emp.salary;
            employeesInPosition[person[i].emp.position] += 1;
            totalSalaryPosition[person[i].emp.position] += person[i].emp.salary;
        }
    }

    averageSalary = totalSalary/numberOfEmployees;
    printf("Total Number of Employees:%-2d\tTotal Salary:%-11.2f\tAverage Salary:%-9.2f\n", 
    numberOfEmployees, totalSalary, averageSalary);
    printf("\n");

    for (int j = 0; j < 4; j++) {
        if (employeesInPosition[j] > 0){
            averageSalaryPosition[j] = totalSalaryPosition[j] / employeesInPosition[j];
        } else {
            averageSalaryPosition[j] = 0;
        }
        printf("Position[%-1d] Employees:%-1d\t\tTotal Salary:%-11.2f\tAverage Salary:%-9.2f\n",
        j, employeesInPosition[j], totalSalaryPosition[j], averageSalaryPosition[j]);
    }
}
