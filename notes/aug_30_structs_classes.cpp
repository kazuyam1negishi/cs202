// File I/O

// Structs (all members public by default)

/*
#include <iostream>
using namespace std;

struct Student{
	string name;
	int score;
	char grade;
};

void setData(Student&);
void printData(Student);
void calculateGrade(int);

int main(){
	Student stdObj;
	setData(stdObj);
	calculateGrade(stdObj.score);
	printData(stdObj);
}

void setData(Student& sObj){
	cout << "Enter name: ";
	cin >> sObj.name;
	cout << "Enter score: ";
	cin >> sObj.score;
}

void printData(Student sObj){
	cout << sObj.name << " " << sObj.score << endl;
}

void calculateGrade(int score){
	if (score >= 90)
		cout << "Final Grade: A" << endl;
	else if (score >= 80)
		cout << "Final Grade: B" << endl;
	else if (score >= 70)
		cout << "Final Grade: C" << endl;
	else if (score >= 60)
		cout << "Final Grade: D" << endl;
	else if (score >= 50)
		cout << "Final Grade: F" << endl;
}
*/

// Structs and vectors

/*
#include <iostream>
#include <vector>
using namespace std;

struct Student{
	string name;
	int score;
	char grade;
};

void setData(vector<Student>&);
void printData(vector<Student>);
void calculateGrade(int);

int main(){
	vector<Student> stdObj;
	setData(stdObj);
	calculateGrade(stdObj.score);
	printData(stdObj);
}

void setData(vector<Student>& sObj, int length){
	for (int i = 0; i = length; i++){
		Student temp;
		cout << "Enter name: ";
		cin >> temp.name;
		cout << "Enter score: ";
		cin >> temp.score;
		sObj.push_back(temp);
	}
}

void printData(Student sObj){
	cout << sObj.name << " " << sObj.score << endl;
}

void calculateGrade(int score){
	if (score >= 90)
		cout << "Final Grade: A" << endl;
	else if (score >= 80)
		cout << "Final Grade: B" << endl;
	else if (score >= 70)
		cout << "Final Grade: C" << endl;
	else if (score >= 60)
		cout << "Final Grade: D" << endl;
	else if (score >= 50)
		cout << "Final Grade: F" << endl;
}
*/

// Classes (all members private by default)

#include <iostream>
using namespace std;

class Student{
	private:
		string name;
		int score;
		char grade;
	public:
		void setData();	
		void printData();
		void calculateGrade();
};

int main(){
	Student stdObj;
	stdObj.setData();
	stdObj.calculateGrade();
	stdObj.printData();
}

void Student::setData(){
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter score: ";
	cin >> score;
}

void Student::printData(){
	cout << name << " " << score << endl;
}

void Student::calculateGrade(){
	if (score >= 90)
		cout << "Final Grade: A" << endl;
	else if (score >= 80)
		cout << "Final Grade: B" << endl;
	else if (score >= 70)
		cout << "Final Grade: C" << endl;
	else if (score >= 60)
		cout << "Final Grade: D" << endl;
	else if (score >= 50)
		cout << "Final Grade: F" << endl;
}