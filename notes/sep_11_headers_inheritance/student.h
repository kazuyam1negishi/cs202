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

#endif