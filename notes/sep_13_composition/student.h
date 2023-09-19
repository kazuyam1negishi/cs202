#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>

class Student{
	private:
		std::string name;
		int score;
		char grade;
	public:
        // Default constructor with vars declared
        // Remember: don't set the data type here,
        // since the vars are already declared in
        // the private: section of the class.
        Student(){
            name = "";
            score = 0;
            grade = ' ';
        }
        // Parameterized constructor with vars
        // declared using this-> pointer.
        // You can also declare vars like this:
        // ...:name(name),score(score)
        // if you use the same name as the member vars.
        Student(std::string name, int score){
            this->name=name;
            this->score=score;
        }
		void setData();	
		void printData();
		void calculateGrade();
        // Use the const keyword at the end of
        // a function to block any modification
        // of member values.
        int getScore() const;
        void getDataFromFile(std::ifstream&);
        ~Student();
};

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

#endif