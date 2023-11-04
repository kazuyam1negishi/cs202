#include <iostream>
using namespace std;

class Employee{
    private:
        string name;
        int age;
        double salary;
        string department;
    public:
        Employee(){
            name = "";
            age = 0;
            salary = 0;
            department = "";
        };
        ~Employee(){

        };
        void setEmployeeData(){
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter salary: ";
            cin >> salary;
            cout << "Enter department: ";
            cin >> department;
        };
        void printEmployeeData() const{
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Salary: " << salary << endl;
            cout << "Department: " << department << endl;
        }
};

const int MAXEMPLOYEE = 2;

int main(){
    Employee employeelist[MAXEMPLOYEE];
    for(int i = 0; i < MAXEMPLOYEE; i++){
        cout << "Enter Employee " << i + 1 << " details:" << endl;
        employeelist[i].setEmployeeData();
    }
    for(int i = 0; i < MAXEMPLOYEE; i++){
        cout << "**Printing Employee Details**" << endl;
        cout << "Employee " << i + 1 << endl;
        employeelist[i].printEmployeeData();
    }
    return(0);
}