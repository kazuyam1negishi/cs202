/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 3
    Description: Sets up data for user's stock investment.
    Input: 2 strings for trader type & stock, int for amount or
    shares, and double for share price.
    Output: Values for all varibles with print(), or errors if
    any values are invalid.
*/

#include "investorType.h"
#include "stockInvestor.h"
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Default constructor
investorType::investorType(){
    typeName = "";
    stockName = "";
    stockCount = 0;
    stockPrice = 0.0;
}
// Parameterized constructor
investorType::investorType(string ID, string fName,
    string lName, string tyName, string stName, int stCount,
    double stPrice, ostream &output){
        // Sets up basic user info with public function.
        stockInvestor::setStockInvestor(fName, lName, ID);
        // Used to omit another message if ID is already invalid.
        bool omitMsg = false;
        // Skips any calculations for user if ID invalid.
        // Returns error if true.
        if(checkInvestorID(ID) == false){
            output << "Invalid ID; No calculations for "
                << fName << "; ID " << ID << endl;
            omitMsg = true;
        }
        // Values set regardless.
        typeName = tyName;
        stockName = stName;
        stockCount = stCount;
        stockPrice = stPrice;
        // Messages for invalid price or amount.
        // Skipped if ID is already invalid.
        // Returns error if price invalid...
        if(stockPrice <= 0 && omitMsg == false){
            output << fName << "'s stock price is invalid" << endl;
        }
        // Or if the amount is invalid.
        if(stockCount <= 0 && omitMsg == false){
            output << fName << "'s stock count is invalid" << endl;
        }
    }
// Parameterized constructor.
void investorType::setInvestorInfo(string id, string fName, string lName,
    string tyName, string stName, int stCount, double stPrice){
        // Basic user info set using setStockInvestor function.
        stockInvestor::setStockInvestor(fName, lName, id);
        // investorType variables are declared here.
        typeName = tyName;
        stockName = stName;
        stockCount = stCount;
        stockPrice = stPrice;
    }

// Setter functions.
void investorType::setType(string tyName){
    typeName = tyName;
}
void investorType::setStockName(string stName){
    stockName = stName;
}
void investorType::setStockCount(int stCount){
    stockCount = stCount;
}
void investorType::setStockPrice(double stPrice){
    stockPrice = stPrice;
}

// Getter functions.
// Top 3 are obtained by calling
// functions from stockInvestor.
string investorType::getID() const{
    return(stockInvestor::getID());
}
string investorType::getFirstName() const{
    return(stockInvestor::getFirstName());
}
string investorType::getLastName() const{
    return(stockInvestor::getLastName());
}
// These four are for values
// already in investorType.
string investorType::getType() const{
    return(typeName);
}
string investorType::getStockName() const{
    return(stockName);
}
double investorType::getStockPrice() const{
    return(stockPrice);
}
double investorType::getStockCount() const{
    return(stockCount);
}

// Prints data to outFile
void investorType::print(ostream &outFile) const{
    // Prints stars header.
    string stars;
    stars.append(65, '*');
    outFile << stars << endl;
    // Prints if personal or trading account.
    outFile << "Investor Type:" << endl
        << "Type Name: " << typeName << endl;
    // Calls print() from stockInvestor for basic info.
    stockInvestor::print(outFile);
    // Prints out stock info, like name, amount of shares,
    // and the price paid.
    outFile << endl <<  "Stock Name: " << stockName << endl
        << "Stock Count: " << fixed << setprecision(2)
        << double(stockCount) << endl << "Stock Price: "
        << fixed << setprecision(2) << stockPrice << endl;
    // Prints dashes footer.
    string dashes;
    dashes.append(50, '_');
    outFile << dashes << endl;
}
// Also prints data to outFile, but also references
// tempObj for basic investor info.
void investorType::writeDataToFile(ofstream &outFile, investorType &tempObj){
    // Prints info with iomanip adjustments.
    // Uses tempObj functions for basic info.
    outFile << setw(10) << setfill(' ') << tempObj.getID()
        << setw(10) << setfill(' ') << tempObj.getFirstName()
        << setw(10) << setfill(' ') << tempObj.getLastName()
        << setw(10) << setfill(' ') << getType()
        << setw(10) << setfill(' ') << getStockName()
        << setw(12) << setfill(' ') << getStockCount()
        << setw(12) << setfill(' ') << getStockPrice();
}