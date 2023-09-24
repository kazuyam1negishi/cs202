/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 3
    Description: Reads data from fileReader. organized in fileWriter.
    Input: User data from fileReader, with header (1st) line skipped.
    Output: Data reorganized to fileWriter and output file.
*/

#include "fileIO.h"
#include "investorType.h"
#include "stocksPortfolio.h"
#include <iostream>
#include <sstream>

// Reads and writes data between two predetermined files.
unsigned int fileIO::readWriteDataFile(ifstream &fileReader, ofstream &fileWriter){
    // Count for how many lines are input.
    unsigned int count = 0;
    // Line to store from fileReader into stringstream.
    string line = "";
    // Get line 1, but skip.
    getline(fileReader, line);
    // Runs until fstream is empty.
    while(getline(fileReader, line)){
        // Inputs line as a stringstream.
        stringstream ss(line);
        // Temporary variables for organizing data.
        string ID, fName, lName, invType, stName;
        double stAmount, stPrice, priOne, priTwo, priThree;
        ss >> ID >> fName >> lName >> invType >> stName
            >> stAmount >> stPrice >> priOne >> priTwo
            >> priThree;
        // investorType setup with data from variables.
        investorType user(ID, fName, lName, invType, stName,
            stAmount, stPrice, fileWriter);
        stocksPortfolio userSP(priOne, priTwo, priThree, user);
        // print() and calcSV() prints info to file.
        user.print(fileWriter);
        userSP.calculateStockValue(user, fileWriter);
        count++;
    }
    string stars;
    stars.append(65, '*');
    // Appends total entries to end.
    fileWriter << endl << stars << endl
        << "Total Entries: " << count << endl;
    std::cout << "Total Entries: " << count << endl;
    // Returns total count.
    return(count);
}