#include <iostream>
#include<iomanip>
#include "stockInvestor.h"
#include "investorType.h"
#include "stocksPortfolio.h"
#include "fileIO.h"
using namespace std;


int main()
{
    
    string stars;
    stars.append(65, '*');
    
    ofstream outFile;
    outFile.open("investorsData.txt");
    outFile << left ;
    
    outFile << setw(10) << "ID" << setw(10) << "FirstName" << setw(10)
    << "LastName" << setw(10) << "invType" << setw(10)
    << "stockName" << setw(12) << "stockCount";
    outFile << fixed << showpoint << setprecision(2); 
    outFile << setw(12) << "stockPrice" << setw(10) << "pCh1" << setw(10) <<
    "pCh2" << setw(10) << "pCh3" <<endl;

    cout << fixed << showpoint<< setprecision(2);

    stockInvestor andy("Andy", "Cartwright", "P23456");
    andy.print(cout);

    investorType fred("T12345", "Fred", "Weasley", "Trader", "AAL", 15, 35.78, cout);
    fred.print(cout);
    fred.writeDataToFile(outFile, fred);


   // cout << "ID from investorType: " << inObj1.getID() << endl;

    stocksPortfolio fredSP(37.89, 30.00, 25.66, fred);
    fredSP.calculateStockValue(fred, cout);
    fredSP.writePriceChangesToFile(outFile);


    investorType dennis("318345", "Dennis", "Reynolds", "Personal", "IDXX", 200, 152.05, cout);
    dennis.print(cout);
    dennis.writeDataToFile(outFile, dennis);

    stocksPortfolio dennisSP(153.89, 150.12, 162.33, dennis);
    dennisSP.calculateStockValue(dennis, cout);
    dennisSP.writePriceChangesToFile(outFile);


    investorType james("P29367", "James", "Johnson", "Personal", "AVGO", -65, 163.41, cout);
    james.print(cout);
    james.writeDataToFile(outFile, james);

    stocksPortfolio jamesSP(153.89, 172.98, 173.64, james);
    jamesSP.calculateStockValue(james, cout);
    jamesSP.writePriceChangesToFile(outFile);

    investorType ryan("T99988", "Ryan", "Myers", "Trader", "DISH", 120, -53.81, cout);
    ryan.print(cout);
    ryan.writeDataToFile(outFile, ryan);

    stocksPortfolio ryanSP(53.82, 50.12, 52.76, ryan);
    ryanSP.calculateStockValue(ryan, cout);
    ryanSP.writePriceChangesToFile(outFile);

    investorType maria("T78564", "Maria", "Garcia", "Trader", "CSCO", 252, 30.96, cout);
    maria.print(cout);
    maria.writeDataToFile(outFile, maria);

    stocksPortfolio mariSP(23.32, 20.55, 31.02, maria);
    mariSP.calculateStockValue(maria, cout);
    mariSP.writePriceChangesToFile(outFile);

    investorType oscar;
    oscar.setInvestorInfo("P7888", "Oscar", "Bluth", "Personal", "QCOM", -83, 61.95);
    oscar.print(cout);
    oscar.writeDataToFile(outFile, oscar);

    stocksPortfolio oscarSP(23.32, 20.55, 31.02, oscar);
    oscarSP.calculateStockValue(oscar, cout);
    oscarSP.writePriceChangesToFile(outFile);


    investorType robert;
    robert.setInvestorInfo("T55669", "Robert", "Smith", "Trader", "NVDA", 538, 56.24);
    robert.print(cout);
    robert.writeDataToFile(outFile, robert);

    stocksPortfolio robertSP(51.11, 57.34, 63.48, oscar);
    robertSP.calculateStockValue(robert, cout);
    robertSP.writePriceChangesToFile(outFile);


    investorType selma("S31860", "Selma", "Bouvier", "Personal", "NTES", 46, 200.00, cout);
    selma.print(cout);
    selma.writeDataToFile(outFile, selma);

    stocksPortfolio selmaSP(199.25, 180.67, 203.17, selma);
    selmaSP.calculateStockValue(selma, cout);
    selmaSP.writePriceChangesToFile(outFile);


    investorType luke;
    luke.setInvestorInfo("T13502", "Luke", "Skywalker", "Trader", "FOX", 512, 27.5);
    luke.print(cout);
    luke.writeDataToFile(outFile, luke);

    stocksPortfolio lukeSP(27.5, 27.51, 15.17, luke);
    lukeSP.calculateStockValue(luke, cout);
    lukeSP.writePriceChangesToFile(outFile);

    //setting the invalid(s)

    james.setStockCount(65);
    james.print(cout);
    james.writeDataToFile(outFile, james);
    jamesSP.calculateStockValue(james, cout);
    jamesSP.writePriceChangesToFile(outFile);

    ryan.setStockPrice(53.81);
    ryan.print(cout);
    ryan.writeDataToFile(outFile, ryan);
    ryanSP.calculateStockValue(ryan, cout);
    ryanSP.writePriceChangesToFile(outFile);

    oscar.setInvestorID("P78887");
    oscar.setStockCount(83);
    oscar.print(cout);
    oscar.writeDataToFile(outFile, oscar);
    oscarSP.calculateStockValue(oscar, cout);
    oscarSP.writePriceChangesToFile(outFile);

    selma.setInvestorID("P31860");
    selma.print(cout);
    selma.writeDataToFile(outFile, selma);
    selmaSP.calculateStockValue(selma, cout);
    selmaSP.writePriceChangesToFile(outFile);


    outFile.close();

    cout << "fileIO object declarations begin" <<endl;
    
    cout << endl << stars << endl;
    
    fileIO fObj;
    ifstream inFile;
  
    inFile.open("investorsData.txt");

    ofstream outData;
    outData.open("InvestorPortifolios.txt");

    fObj.readWriteDataFile(inFile, outData);

    return 0;
}
