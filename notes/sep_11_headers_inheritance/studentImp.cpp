#include "student.h"
using namespace std;

void Student::setData(){
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter score: ";
	cin >> score;
}

void Student::printData(){
	cout << name << " " << score << " " << grade << endl;
}

void Student::calculateGrade(){
	if (score >= 90){
        grade = 'A';
		cout << "Final Grade: A" << endl;
    }
	else if (score >= 80){
        grade = 'B';
		cout << "Final Grade: B" << endl;
    }
	else if (score >= 70){
        grade = 'C';
		cout << "Final Grade: C" << endl;
    }
	else if (score >= 60){
        grade = 'D';
		cout << "Final Grade: D" << endl;
    }
	else if (score >= 50){
        grade = 'F';
		cout << "Final Grade: F" << endl;
    }
}

int Student::getScore() const{
    return(score);
}

void Student::getDataFromFile(ifstream& fileReader){
    fileReader.open("sep11data.txt");
    string crtLine;
    getline(fileReader, crtLine);
    int count;
    while(fileReader >> name >> score){
        Student(name, score);
        calculateGrade();
        printData();
        count++;
    }
    cout << "Total entries: " << count << endl;
}

// Default destructor
// This never has any variable calls.
Student::~Student(){
    cout << "Destructor called for " << name << endl;
}