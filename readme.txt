Name: Stefano Savvidis
ID: 101078280
Date: March 6, 2018 

Purpose:
  Keep track of 20 people (some patients, and some employees)
  Store different attributes for these people depending on if theyre an employee or student
  Display this data at the users request

Organization:
  struct.h - holds the struct that we will be using to store all the data
  main.c - allows the user to interact with the data by navigating a menu (also has the print struct size func)
  employee.c - contains all the functions for displaying different aspects of the employee data
  patient.c - contains all function for displaying different asspects of the patient data
            - also contains a function to allow the user to search for patients by familyname

Compile & Run:
  gcc hospital.c employee.c patient.c populateRecords.c
    - this will compile the given code and create an a.out file to actually run the program
  
  ./a.out
    - enter this to actually use the program after its been compiled

Use:
  Now that its been compiled there are a few different ways you can use its

You can:
  print all employees (this prints all employees name, salary, position, etc.)
  print all patients (this prints all patients name, daily cost, severity, etc.)
  saerch for patients (enter the last name and the program will return all patients with matching family name)
  get a summary of all the employees data (subcategorizes it by position)
  get a summary of all the patients data (subcategorizes it by department)
  lastly there is the option to see the size of all the structs

  and of course you can quit

Limitations:
  cant actually interact or edit the data, only view it

