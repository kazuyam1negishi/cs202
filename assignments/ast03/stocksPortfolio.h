/*
Name: KISHORE, NSHE: ABC123, CLASS-SECTION: CS202, ASSIGNMENT: 3
Description: In investing, what is comfortable is rarely profitable.
Input: Develop stockInvestor(base class) that can be useful to set 
firstName, lastName and ID; set the investors data using setters or 
constructors from stockInvestors class; 
investorType is a derived (inheritance: is-a relationship) class from 
stockInvestor class and is useful to set the investor type, stock name, 
number of stocks, and stock price; 
stocksPortfolio is a base class with an object of other 
class(investorType) (Composition: has-a relationshipinvestorType).
stocksPortfolio is to set 3 different prices;
Output: Write the investors data to a file(investorsData.txt) following 
the driver code in stocksMain.cpp. The objects declaration of different 
classes, using constructors, setters, member functions to calculate the
portfolio of each investor. The investors' portfolios (reports) are 
printed on terminal.
In fileIO:
This class has only one member function. The member function returns the 
number of entries
Read the data from (investorsData.txt) file; use constructors, setters, 
member functions to calculate the portfolio of each investor. Finally,
write the investors' portfolios (reports) to an outputfile 
(investorsPortfolio.txt). 
Note: You will upload the implementation files only (4 in total)
*/
#ifndef STOCKSPORTFOLIO_H
#define STOCKSPORTFOLIO_H
#include<fstream>
#include<iomanip>
#include "investorType.h"

class stocksPortfolio{
private:
    double priceOne;  //variable to store the priceOne
    double priceTwo;  //variable to store the priceTwo
    double priceThree;  //variable to store the priceThree
    double stockValue;  //variable to store the stockValue
    investorType invTypeObj; // object of investorType (Composition)

public:
	stocksPortfolio(); //Default constructor
	stocksPortfolio(double pOne, double pTwo, double pThree, investorType invTemp);
	//parameterized constructor
  	//Initialize the private member varaibles: priceOne, priceTwo, and priceThree 
  	//according to the parameters
  	//Initialize private member object of other class according to the given parameter
	
	void setPortfolio(double pOne, double pTwo, double pThree, investorType invTemp);
	//Initialize the private member varaibles: priceOne, priceTwo, and priceThree 
  	//according to the parameters
  	//Initialize private member object of other class according to the given parameter

    //To print three price changes
    void printPriceChanges(ostream &output) const;
    
	void calculateStockValue(investorType invTemp, ostream &output);
	//Calculate stockValue- multiply stockPrice with stockCount 
							//(both from investor type; use getters)
	//multiply stockCount with each new price and print statements accordingly
	//Finally print stockValue - Show Loss/Profit accordingly
	//Check sample output for more details 


	void writePriceChangesToFile(ostream &output) const; 
	//Write priceOne, priceTwo, and priceThree to the investorsData.txt
	//Check sample output, the prices should be in same line as id, name, etc.
	
	double getInvestorPrice() const; //get investor price from investorType
	double getPriceOne() const;
	double getPriceTwo() const;
	double getPriceThree() const;
	double getStockValue() const;
    //getter(Accessor) functions to return private member variables
    //accordingly
	
};

#endif
