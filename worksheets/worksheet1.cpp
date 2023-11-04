#include <iostream>
#include <vector>
using namespace std;

struct Employee{
    string name;
    int age;
    double salary;
    string department;
};

void setEmployeeData(Employee&);
void printEmployeeData(Employee);

const int MAXEMPLOYEE = 2;

int main(){
    Employee employeelist[MAXEMPLOYEE];
    for(int i = 0; i < MAXEMPLOYEE; i++){
        cout << "Enter Employee " << i + 1 <<
            " Details:" << endl;
        setEmployeeData(employeelist[i]);
    }
    cout << "Printing Employee Details:" << endl;
    for(int i = 0; i < MAXEMPLOYEE; i++){
        cout << "Employee " << i + 1 << ":" << endl;
        printEmployeeData(employeelist[i]);
    }
    return(0);
}

void setEmployeeData(Employee& eObj){
    cout << "Enter name: ";
    cin >> eObj.name;
    cout << "Enter age: ";
    cin >> eObj.age;
    cout << "Enter salary: ";
    cin >> eObj.salary;
    cout << "Enter department: ";
    cin >> eObj.department;
}

void printEmployeeData(Employee eObj){
    cout << eObj.name << " " << eObj.age <<
        " " << eObj.department << " " << eObj.salary << endl;
}