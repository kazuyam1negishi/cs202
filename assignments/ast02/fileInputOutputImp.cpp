#include "fileInputOutput.h"
#include "multiplication.h"

FileClass::FileClass(string file_name){
    inFile.open(file_name);
    if(inFile.fail() == true){
        cout << "Failed to open the file." << endl;
        exit(0);
    }
    outFile.open("output.txt");
};

FileClass::~FileClass(){
    inFile.close();
    outFile.close();
};

void getData(std::vector<Multiplication> &multiplications, const std::string &filename){
    FileClass input(filename);
    Multiplication tempStore;
    while(input.inFile.good()){
        // Multiplicand Multiplier      Bits
        // Note: works without header.
        // Get that fixed.
        // 
        input.inFile >> tempStore.multiplicand
            >> tempStore.multiplier
            >> tempStore.bits;
        cout << tempStore.multiplicand
            << tempStore.multiplier
            << tempStore.bits << endl;
        multiplications.push_back(tempStore);
    }
};