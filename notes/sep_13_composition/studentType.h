#ifndef STUDENTTYPE_H
#define STUDENTTYPE_H
#include <iostream>
#include <fstream>
#include "student.h"

class StudentType:public Student{
    private:
        std::string stdType;
        int age;
        Student stdObj;
    public:
        StudentType(){
            stdType = "";
        };
        StudentType(std::string type){
            stdType = type;
        };
        StudentType(std::string name, int points, std::string type):Student(name, points){
            stdType = type;
        }
        void setStudentType(){
            Student::setData();
            cout << endl;
            cout << "Student Type:  " << stdType << endl;
        }
        std::string getStudentType(){
            return(stdType);
        }
        void printData(){
            Student::printData();
        }
};

#endif