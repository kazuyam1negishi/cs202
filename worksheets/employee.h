#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee{
    private:
        string ID;
        int age;
        double salary;
    public:
        Employee(); //Default Constructor
        Employee(string, int, double); //constructor with parameters
        virtual void printData(); // virtual function to printData()
        Employee (Employee const &); //Employee copy constructor
        virtual ~Employee(); //virtual Base Destructor
};
class employeeType:public Employee{
    private:
        string eType;
        int *serviceYears;
    public:
        employeeType(); //Default constructor
        employeeType(string, int, double, string, int );
        //Parameterized constructor
        void printData(); // This function needs to print Employee
        // Data and employeeType data
        ~employeeType(); //Derived Destructor
};
#endif
