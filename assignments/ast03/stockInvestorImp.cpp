/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 3
    Description: Sets up basic details for investor.
    Input: Three strings for full name and ID.
    Output: Full name and ID with print() and error if ID invalid.
*/

#include "stockInvestor.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
stockInvestor::stockInvestor(){
    firstName = "";
    lastName = "";
    ID = "";
}
// Parameterized constructor
stockInvestor::stockInvestor(string fName, string lName, string ID){
    firstName = fName;
    lastName = lName;
    // Returns error if ID invalid.
    // Still sets ID if invalid.
    if(checkInvestorID(ID) == false){
        cout << "Error :- " << ID << " is invalid investorID for "
            << firstName << endl;
    }
    this->ID = ID;
}
// Parameterized constructor
void stockInvestor::setStockInvestor(string fName, string lName, string ID){
    firstName = fName;
    lastName = lName;
    // Returns error if ID invalid.
    // Still sets ID if invalid.
    if(checkInvestorID(ID) == false){
        cout << "Error :- " << ID << " is invalid investorID for "
            << firstName << endl;
    }
    this->ID = ID;
}
// Checks if ID valid by checking length,
// if ID[0] is T or P, and if rest of
// chars in ID are digits.
bool stockInvestor::checkInvestorID(string tempID) const{
    // Checks if length is 6...
    if(tempID.length() < 6){
        return(false);
    }
    // And if the first digit is T or P...
    else if(tempID[0] != 'T' && tempID[0] != 'P'){
        return(false);
    }
    // And if the rest of the ID is digits only.
    // NOTE: This function is run
    // assuming the ID length is already 6.
    // That is why the i < 6 condition is set.
    for(int i = 1; i < 6; i++){
        if(!isdigit(tempID[i])){
            return(false);
        }
    }
    // Returns true if all the conditions are met.
    return(true);
}

// Setter functions.
// Sets ID, regardless of whether it's valid or not.
void stockInvestor::setInvestorID(string ID){
    // If ID is invalid, error is printed.
    if(checkInvestorID(ID) == false){
        cout << "Error :- " << ID << " is invalid investorID for "
            << firstName << endl;
    }
    // ID set regardless.
    this->ID = ID;
}
// Sets full name.
void stockInvestor::setName(string fName, string lName){
    firstName = fName;
    lastName = lName;
}

// Getter functions.
string stockInvestor::getID() const{
    return(ID);
}
string stockInvestor::getFirstName() const{
    return(firstName);
}
string stockInvestor::getLastName() const{
    return(lastName);
}

// Prints info to &output.
void stockInvestor::print(ostream &output) const{
    output << "Investor ID: " << ID << endl
        << "First Name: " << firstName << endl
        << "Last Name: " << lastName << endl;
}