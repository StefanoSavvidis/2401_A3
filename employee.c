#include "employee.h"
#include "stdio.h"

void printEmployee(PersonRec person)

{
    printf("%-15s %-15s\tDepartment: %-1d\tSalary: %-9.2f\tPosition: %-1d\tYears of service: %-2d\tSalary To-Date: %-11.2f\n",
    person.firstName, person.familyName,
    person.emp.department, person.emp.salary, person.emp.position, person.emp.yearsService, person.emp.yearsService * person.emp.salary);
    // prints the employee data
}

void printEmployees(PersonRec *person, int numRecords)
{
    
    for(int i = 0; i < numRecords; i++) { // itterate through every person
        if (!person[i].emplyeeOrPatient) { // check if theyre an employee
            printEmployee(person[i]); // print data
        }
        
    }
}


void printEmployeesSummary(PersonRec *person, int numRecords)
{
    int employeesInPosition[4] = {0}; // number of employees in position
    int numberOfEmployees = 0; // number of employees

    double totalSalaryPosition[4] = {0}; // total salary in position
    double totalSalary=0; // total salary
    
    double averageSalary=0; // average salary
    double averageSalaryPosition[4]; // average salary in position
    
    /* ADD EMPLOYEE DATA TO RELEVANT STORAGE */
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

    /* PRINT ALL COLLECTED DATA */
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
