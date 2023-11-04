#ifndef STUDENTDETAILS_H
#define STUDENTDETAILS_H
#include <iostream>
#include <fstream>
#include "student.h"

class StudentDetails{
    private:
        int age;
        Student studentObj;
    public:
        StudentDetails();
        StudentDetails(Student sObj, int age){
            this->studentObj = sObj;
            this->age = age;
        };
};

#endif