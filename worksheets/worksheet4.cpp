// This is your main.cpp.

#include <iostream>
#include "employee.h"
using namespace std;

int main(){
    // 1. Declare Employee and call printData().
    Employee newEmp("ABC123", 35, 1234.56);
    newEmp.printData();
    // 2. Declare employeeType and call printData().
    employeeType newEmpType("ABC123", 35, 1234.56, "Full-Time", 12);
    newEmpType.printData();
    // 3. Declare obj to invoke Employee copy const.
    Employee newEmpTwo(newEmp);
    newEmpTwo.printData();
    // 4. Declare Employee and employeeType, then upcast and print.
    Employee * newEmpThree = new employeeType("DEF456", 42, 2316.77, "Part-Time", 5);
    newEmpThree->printData();
    // 5. Declare Employee and employeeType, then downcast and print.
    Employee * newEmpFour = new employeeType("CSE202", 52, 2500.52, "Full-Time", 15);
    employeeType * newEmpTypeTwo;
    newEmpTypeTwo = dynamic_cast<employeeType *>(newEmpFour);
    newEmpTypeTwo->printData();
    // Erasing vars.
    delete newEmpThree;
    delete newEmpFour;
    newEmpThree = nullptr;
    newEmpFour = nullptr;
    /*
    Note to self: do not do this anymore:
    delete newEmpTypeTwo;
    This will try to delete something
    that has already been deleted.
    */
}