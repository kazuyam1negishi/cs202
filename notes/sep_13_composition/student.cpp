#include <iostream>
#include <fstream>
#include "student.h"
#include "studentType.h"
using namespace std;

int main(){
    ifstream fileReader;

    /*
	Student stdOne;
	stdOne.setData();
	stdOne.calculateGrade();
	stdOne.printData();

    Student stdTwo;
	stdTwo.setData();
	stdTwo.calculateGrade();
	stdTwo.printData();

    Student stdThr("Joe", 75);
    stdThr.calculateGrade();
    stdThr.printData();
    */

    Student stdFor;
    stdFor.getDataFromFile(fileReader);

    // cout << stdOne.getScore() << " " << stdTwo.getScore() << " " << stdThr.getScore() << endl;
    return(0);
}