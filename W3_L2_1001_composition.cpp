#include<iostream>
#include<fstream>
using namespace std;

class Student{
private:
    string name;
    int score;
    char grade;
public:
    Student()//Default constructor
    {
        cout<<"Default Constructor Invoked"<<endl;
        name="   ";
        score=0;
        grade=' ';
    }
    Student(string, int);
    void setStudentData( );
    void printData();
    void calculateGrade();
    int getScore() const;
    void getDataFromFile(ifstream &);
    ~Student();
protected:
    string collegeName;
};

Student::Student(string name, int score):name(name),score(score){
    cout<<"Parameterized Constructor Invoked"<<endl;
}
void Student::setStudentData(){
    cout<<"Enter name: ";
    cin>>name;

    cout<<"Enter score: ";
    cin>>score;

}

void Student::printData(){
    cout<<name<<"   "<<score<<" "<<grade<<endl;
    cout << "College Name: "<<collegeName<<endl;
}
void Student::calculateGrade(){
    if(score>=90){
        grade = 'A';
        cout<<"Final Grade: A"<<endl;
    }
        
    else if(score>=80){
        grade = 'B';
        cout<<"Final Grade: B"<<endl;
    }
       
    else if(score>=70){
        grade = 'C';
        cout<<"Final Grade: C"<<endl;
    }
    else if(score>=60){
        grade = 'D';
        cout<<"Final Grade: D"<<endl;
    }
    else {
        grade = 'F';
        cout<<"Final Grade: F"<<endl;
    }
    
}


int Student::getScore() const{
   
    return score;
}

void Student::getDataFromFile(ifstream &inFile){
    inFile.open("studentData.txt");
    string line; //To read the header
    int count=0;
    getline(inFile, line);

    while(inFile>>name>>score){
        
        Student(name, score);
        calculateGrade();
        printData();
        count++;

    }
    cout<<"Total Entries: "<<count<<endl;
    inFile.close();

}

Student::~Student(){
    cout<<"Destructor Invoked   "<<name<<endl;
}

class studentType:public Student{
private:
    string stType;
public:
    studentType();
    studentType(string type);
    studentType(string nm, int points, string type);
    studentType(string nm, int points, string clgName, string type);

    void setStudentType(string type);
    string getStudentType() const;
    void printData();

};
studentType::studentType(){
    stType = "  ";
}
studentType::studentType(string type){
    stType=type;
}

studentType::studentType(string nm, int points, string type):Student(nm, points){
    stType=type;
}
studentType::studentType(string nm, int points, string clgName, string type)
    :Student(nm, points){
        collegeName = clgName;
        stType = type;

}
void studentType::setStudentType(string type){
      stType=type;
}

string studentType::getStudentType() const{
    return stType;
}

void studentType::printData(){
    Student::printData();
    cout<<endl;
    cout<<"Student type: "<<stType<<endl;
}

class studentDetails{
private:
    int age;
    Student tempStd;
public:
    studentDetails();
    studentDetails(Student sObj, int ag); //param1-object of Student, parm2-age
    void print();
};


studentDetails::studentDetails(){
    age=0;
}
studentDetails::studentDetails(Student sObj, int ag):tempStd(sObj), age(ag){

}

void studentDetails::print(){
    tempStd.printData();
   // cout<<"Score: "<<Student::getScore()<<endl;
    cout<<"Age: "<<age<<endl;
}

int main(){
    // ifstream inFile;
    // Student stdObj;
    // stdObj.getDataFromFile(inFile);

    Student sdObj("John", 88);
   

    // studentType typeObj("Jaden", 76, "Full-Time");
    // typeObj.printData();
    
    // studentType typeObj2("Jaden", 76, "UNLV", "Full-Time");
    // typeObj2.printData();

    studentDetails sDetails(sdObj, 23);
    sDetails.print();
   

    cout<<endl;
    return 0;
   
}