#include <iostream>
#include <fstream>
#include "student.h"
#include "studentType.h"
using namespace std;

int main(){
    ifstream fileReader;
    Student stdFor;
    stdFor.getDataFromFile(fileReader);
    return(0);
}