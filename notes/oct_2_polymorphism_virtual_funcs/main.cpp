#include <iostream>
using namespace std;

class Person{
    private:
        string name;
        int age;
    public:
        Person();
        Person(string, int);
        virtual void print() const;
};

class Employee:public Person{
    private:
        string eRole;
        int salary;
        int service;
    public:
        Employee();
        Employee(string, int, int);
        Employee(string, int, string, int, int);
        void print() const;
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

Employee::Employee(){
    eRole = " ";
    salary = 0;
    service = 0;
}
Employee::Employee(string role, int sal, int ser){
    eRole = role;
    salary = sal;
    service = ser;
}
Employee::Employee(string name, int age, string role, int sal, int ser):Person(name, age){
    eRole = role;
    salary = sal;
    service = ser;
}
void Employee::print() const{
    Person::print();
    cout << "Role: " << eRole << endl
        << "Salary: " << salary << endl
        << "Service: " << service << endl;
}

void globalPrint(Person &p){
    p.print();
}

int main(){
    Person pObj("John", 32);
    pObj.print();
    cout << endl;

    Employee emObj("Jim", 19, "Testing", 60000, 2);
    emObj.print();
    cout << endl;

    // Invalid upcasting example:
    // Introduces slicing issue
    pObj=emObj;
    pObj.print();
    cout << endl;

    // Valid upcasting examples:
    // To overcome slicing, declare a base pointer,
    // declare a derived object, and pass the derived
    // objcet to the base class pointer.
    Person * pObj2 = &emObj;
    pObj2->print();
    cout << endl;
    
    // You can also declare a new object
    // of the derived class instead.
    Person * pObj3 = new Employee("Tom", 23, "Hardware", 190000, 7);
    pObj3->print();
    cout << endl;

    // Downcasting example:
    // Passing base to derived class
    Employee * emObj2;
    emObj2 = dynamic_cast<Employee *>(pObj3);
    emObj2->print();
    cout << endl;

    // Erasing...
    // delete pObj2;
    // pObj2 = nullptr;
    delete pObj3;
    pObj3 = nullptr;
}