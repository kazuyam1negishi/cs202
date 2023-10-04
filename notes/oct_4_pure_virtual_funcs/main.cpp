/*
Difference between virtual and pure virtual functions

Virtual - virtual void print(){};
Pure virtual - virtual void print() = 0;

This allows derived classes to implement their own
definitions for said functions, which is a form
of polymorphism. This also makes the class an abstract class.
*/

#include <iostream>
using namespace std;

// Person is an abstract class.
// This means you can use any function
// in this class, but you cannot declare
// an object of this type anymore.
class Person{
    private:
        string name;
        int age;
    public:
        Person();
        Person(string, int);
        virtual void print() const;
        virtual void setData() = 0;
        virtual ~Person() = 0;
};

// Employee is a derived class,
// and this can create and use
// objects of the Person class.
class Employee:public Person{
    private:
        string eRole;
        int salary;
        int * service;
    public:
        Employee();
        Employee(string, int, int);
        Employee(string, int, string, int, int);
        void print() const;
        void setData();
        ~Employee();
};

Person::Person(){
    name = " ";
    age = 0;
}
Person::Person(string name, int age){
    this->name = name;
    this->age = age;
}
void Person::print() const{
    cout << "Name: " << name << endl
        << "Age: " << age << endl;
}
Person::~Person(){
    cout << "Person destructor called for " << name << endl;
}

Employee::Employee(){
    eRole = " ";
    salary = 0;
    service = new int;
    // Do not set * values inside constructors
    // like this! The whole class will share this
    // value, and if it goes out of scope, you
    // could end up calling a deleted value,
    // resulting in a memory leak.
    * service = 0;
}
Employee::Employee(string role, int sal, int ser){
    eRole = role;
    salary = sal;
    service = new int;
    * service = ser;
}
Employee::Employee(string perName, int perAge, string role, int sal, int ser):Person(perName, perAge){
    eRole = role;
    salary = sal;
    service = new int;
    * service = ser;
}
void Employee::print() const{
    Person::print();
    cout << "Role: " << eRole << endl
        << "Salary: " << salary << endl
        << "Service: " << *service << endl;
}
void Employee::setData(){
    cout << "Set Data function called.";
}
Employee::~Employee(){
    delete service;
    service = nullptr;
    cout << "Employee destructor called for " << salary << endl;
}

void globalPrint(Person &p){
    p.print();
}

int main(){
    Employee emObj("Jim", 19, "Testing", 60000, 2);
    emObj.print();
    cout << endl;

    Person * pObj2 = &emObj;
    pObj2->print();
    cout << endl;

    Person * pObj3 = new Employee("Tom", 23, "Hardware", 190000, 7);
    pObj3->print();
    cout << endl;

    Employee * emObj2;
    emObj2 = dynamic_cast<Employee *>(pObj3);
    emObj2->print();
    cout << endl;

    delete pObj3;
    pObj3 = nullptr;
}