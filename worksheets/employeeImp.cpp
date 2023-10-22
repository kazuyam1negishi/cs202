// This is your employeeImp.cpp.

#include <iostream>
#include "employee.h"

// BASE CLASS

Employee::Employee(){
    ID = " ";
    age = 0;
    salary = 0;
}

Employee::Employee(string ID, int ag, double sal){
    this->ID = ID;
    age = ag;
    salary = sal;
}

void Employee::printData(){
    cout << "ID: " << ID << endl
        << "Age: " << age <<  endl
        << "Salary: " << salary << endl;
}

Employee::Employee(Employee const & emObj){
    this->ID = emObj.ID;
    this->age = emObj.age;
    this->salary = emObj.salary;
}

// Nothing here, since there is nothing
// on the heap that needs deallocating.
Employee::~Employee(){
    cout << "Base destructor invoked." << endl;
}

// DERIVED CLASS

employeeType::employeeType(){
    eType = " ";
    serviceYears = new int;
    * serviceYears = 0;
}

employeeType::employeeType(string ident, int age, double salary, string empType, int serYears):Employee(ident, age, salary){
    eType = empType;
    serviceYears = new int;
    * serviceYears = serYears;
}

void employeeType::printData(){
    Employee::printData();
    cout << "Employee type: " << eType << endl
        << "Service years: " << *serviceYears << endl;
}

employeeType::~employeeType(){
    cout << "Derived destructor invoked." << endl;
    delete serviceYears;
    serviceYears = nullptr;
}