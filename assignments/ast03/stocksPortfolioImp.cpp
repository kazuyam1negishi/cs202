/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 3
    Description: Calculates profit/loss using given values.
    Input: 4 doubles for 3 price changes and 1 stock value,
    and an investorType object for stock and basic info.
    Output: Profits if value higher than initial stock value,
    or loss if value less than initial stock value.
*/

#include "stocksPortfolio.h"
#include "investorType.h"
#include "stockInvestor.h"
#include <fstream>
#include <iomanip>

// Default constructor.
stocksPortfolio::stocksPortfolio(){
    priceOne = 0.0;
    priceTwo = 0.0;
    priceThree = 0.0;
    stockValue = 0.0;
}
// Parameterized constructor.
// No adjustments are made to pOne-pThree just yet
// if any price or ID checks are invalid.
// That is done in calculateStockValue.
stocksPortfolio::stocksPortfolio(double pOne, double pTwo, double pThree, investorType invTemp){
    priceOne = pOne;
    priceTwo = pTwo;
    priceThree = pThree;
    invTypeObj = invTemp;
}
// Parameterized constructor.

// No adjustments are made to pOne-pThree just yet
// if any price or ID checks are invalid.
// That is done in calculateStockValue.
void stocksPortfolio::setPortfolio(double pOne, double pTwo, double pThree, investorType invTemp){
    priceOne = pOne;
    priceTwo = pTwo;
    priceThree = pThree;
    invTypeObj = invTemp;
}

// Prints data to file.
void stocksPortfolio::printPriceChanges(ostream &output) const{
    output << "Price One: " << priceOne << endl
        << "Price Two: " << priceTwo << endl
        << "Price Three: " << priceThree << endl;
}
// Calculates profit/loss based on price changes.
// Only run if ID is valid and if no stock values are 0.
void stocksPortfolio::calculateStockValue(investorType invTemp, ostream &output){
    // Initial stock value, set regardless
    // of whether ID and stock values are correct.
    // The value is changed later if any condition fails.
    stockValue = invTemp.getStockPrice() * invTemp.getStockCount();
    // Bool to see if function is run or not.
    bool validNums = true;
    // Checks if stock count is valid...
    if(invTemp.getStockCount() < 0){
        stockValue = 0;
        validNums = false;
    }
    // If stock price is valid...
    if(invTemp.getStockPrice() < 0){
        stockValue = 0;
        validNums = false;
    }
    // And if the ID is valid.
    if(invTemp.checkInvestorID(invTemp.getID()) == false){
        stockValue = 0;
        validNums = false;
    }
    // IF ID is valid and stock values are valid, run.
    if(validNums == true){
        // Double used for comparisons later.
        double finalStockPrice = invTemp.getStockCount() * priceThree;
        // Reports stock value after price changes.
        output << "Stock Value with investor Price: "
            << stockValue << endl
            << "Stock Value with a priceOne change: "
            << invTemp.getStockCount() * priceOne << endl
            << "Stock Value with a priceTwo change: "
            << invTemp.getStockCount() * priceTwo << endl
            << "Stock Value with a priceThree change: "
            << invTemp.getStockCount() * priceThree << endl;
        // If there are losses, use this.
        // This prints only the losses.
        if(finalStockPrice < stockValue){
            output << "Final Stock Value: "
                << finalStockPrice - stockValue << endl
                << "Loss on an investment: "
                << -(finalStockPrice - stockValue) << endl;
        }
        // If there are profits, use this.
        // This prints the final price, and not just
        // the difference between the initial
        // and final stock values.
        if(finalStockPrice > stockValue){
            output << "Final Stock Value: "
                << finalStockPrice << endl
                << "Profit on an investment: "
                << finalStockPrice - stockValue << endl;
        }
        // Reports price changes regardless.
        output << "Price Changes: " << setw(8) << setfill(' ')
            << priceOne << setw(8) << setfill(' ')
            << priceTwo << setw(8) << setfill(' ')
            << priceThree << endl;
    }
    // If not, no calculations are run, and 0s are returned.
    else {
        // Since no calculations are made, 0.00 are already expected,
        // which is why they are printed as-is.
        output << "Stock Value with investor Price: "
            << stockValue << endl
            << "Stock Value with a priceOne change: " << 0.00 << endl
            << "Stock Value with a priceTwo change: " << 0.00 << endl
            << "Stock Value with a priceThree change: " << 0.00 << endl;
        // Price values are reported regardless.
        // Since the stock value is 0, stockValue is used for
        // profit, as the value stays the same.
        output << "Final Stock Value: " << stockValue << endl
            << "Profit on an investment: " << stockValue << endl
            << "Price Changes: " << setw(8) << setfill(' ')
            << priceOne << setw(8) << setfill(' ')
            << priceTwo << setw(8) << setfill(' ')
            << priceThree << endl;
    }
    // Prints stars footer.
    string stars;
    stars.append(65, '*');
    output << stars << endl;
}
// Writes price changes to &output.
void stocksPortfolio::writePriceChangesToFile(ostream &output) const{
    output << setw(10) << setfill(' ') << priceOne
        << setw(10) << setfill(' ') << priceTwo
        << setw(10) << setfill(' ') << priceThree << endl;
}

// Getter functions.
double stocksPortfolio::getInvestorPrice() const{
    return(invTypeObj.getStockPrice());
}
double stocksPortfolio::getPriceOne() const{
    return(priceOne);
}
double stocksPortfolio::getPriceTwo() const{
    return(priceTwo);
}
double stocksPortfolio::getPriceThree() const{
    return(priceThree);
}
double stocksPortfolio::getStockValue() const{
    return(stockValue);
}