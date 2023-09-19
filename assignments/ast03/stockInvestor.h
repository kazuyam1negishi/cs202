#ifndef STOCKINVESTOR_H
#define STOCKINVESTOR_H
#include<string>
using namespace std;

class stockInvestor{
public:
    stockInvestor(); //Default constructor
    
    stockInvestor(string fName, string lName, string id);
    // parameterized constructor
   //Sets firstName, lastName, and id according to the parameters.
   //The default values of the parameters are empty strings.

    void setStockInvestor(string fName, string lName, string id);
    // Mutator function
   //Sets firstName, lastName, and id according to the parameters.
   //The default values of the parameters are empty strings.
   

    bool checkInvestorID(string investorIDTemp) const;
    //return false if ID is incorrect

    void setInvestorID(string id);
     // Mutator function to set investor ID
    
    void setName(string fName, string lName);
   //Function to set firstName and lastName according 
   //to the parameters.

   string getID() const;
   //Function to return the id

   string getFirstName() const;
   //Function to return the first name.
      
   string getLastName() const;
   //Function to return the last name.

   void print(ostream &output) const;
   //Function to print the member variables 
       

 private:
   string firstName; //variable to store the first name
   string lastName;  //variable to store the last name
   string ID; //variable to store the id

};
#endif