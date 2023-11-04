#include "multiplication.h"
#include <iostream>
#include <fstream>
#include <cmath>

Multiplication::Multiplication(){
    manMcand = 0;
    manMplier = 0;
    multiplicand = 0;
    multiplier = 0;
    bits = 0;
    result = 0;
}; // Default constructor
void Multiplication::setMultiplicand(int mcand){
    cout << "Enter multiplicand= ";
    cin >> mcand;
    multiplicand = mcand;
}; //To set multiplicand
void Multiplication::setMultiplier(int mplier){
    cout << "Enter multiplier= ";
    cin >> mplier;
    multiplier = mplier;
}; //To set multiplier
int Multiplication::getMultiplicand() const{
    return(multiplicand);
}; //returns multiplicand
int Multiplication::getMultiplier() const{
    return(multiplier);
}; //returns multiplier





Multiplication::Multiplication(int mc, int ml, int b){
    manMcand = mc;
    manMplier = ml;
    multiplicand = 0;
    multiplier = 0;
    bits = b;
    result = 0;
};

/*check if output file is open and then call performBoothAlgorithm()
and write the output to an output file*/
void Multiplication::writeOutputToFile(std::ofstream &outputFile) const{
    if(!outputFile.is_open()){
        cout << "Failed to write to output file." << endl;
    }
    performBoothAlgorithm(outputFile);
};

/*Use booth's algorithm to perform signed binary multiplication and 
write the results to an output file*/ 
void Multiplication::performBoothAlgorithm(std::ostream &output) const{
    int accumulator[10];
    int multiplier[10];
    int multiplicand[10];
    int tempArray[10];
    int boothBit = 0;
    decimalToBinary(this->multiplier, multiplier, this->bits);
    decimalToBinary(this->multiplicand, multiplicand, this->bits);
    for(int i = 0; i < bits; i++){
        if(multiplier[bits - 1] == 0 &&
            boothBit == 0){
                arithShiftRight(accumulator, multiplier, boothBit, 10, output);
                continue;
            }
        if(multiplier[bits - 1] == 0 &&
            boothBit == 1){
                for(int i = 0; i < bits; i++){
                    tempArray[i] = multiplicand[i];
                }
                add(accumulator, tempArray, bits);
                arithShiftRight(accumulator, multiplier, boothBit, 10, output);
                continue;
            }
        if(multiplier[bits - 1] == 1 &&
            boothBit == 0){
                for(int i = 0; i < bits; i++){
                    tempArray[i] = multiplicand[i];
                }
                add(accumulator, tempArray, bits);
                arithShiftRight(accumulator, multiplier, boothBit, 10, output);
                continue;
            }
        if(multiplier[bits - 1] == 1 &&
            boothBit == 1){
                arithShiftRight(accumulator, multiplier, boothBit, 10, output);
                continue;
            }
    }
};

/*This function takes the decimal number as input and converts it
to binary and stores it in binary [] */
void Multiplication::decimalToBinary(int num, int binary[], int length) const{
    int tempNum = num;
    for(int i = 0; i < length; i++){
        if(tempNum % 2 == 1){
            binary[i] = 1;
        }
        else if(tempNum % 2 == 0){
            binary[i] = 0;
        }
        tempNum = tempNum / 2;
    }
    reverseArray(binary, length);
};

/*This function reverses the given array */
void Multiplication::reverseArray(int arr[], int length) const{
    int tempArr[10];
    int count = length - 1;
    for(int i = 0; i < length; i++){
        tempArr[i] = arr[count];
        count--;
    }
    for(int i = 0; i < length; i++){
        arr[i] = tempArr[i];
    }
};

/* This function prints the given number in binary*/
void Multiplication::printBinary(int num, int bits, std::ostream &output) const{
    int arr[10];
    decimalToBinary(num, arr, bits);
    for(int i = 0; i < bits; i++){
        output << arr[i];
    }
    output << endl;
};

/*This function adds the accumulator and multiplicand bitwise and 
store/write back the addition result to the accumulator in binary*/
void Multiplication::add(int accumulator[], int mcnadBinary[], int mplierLength) const{
    bool carry = false;
    for(int i = mplierLength - 1; i >= 0; i--){
        if(accumulator[i] + mcnadBinary[i] == 0){
            accumulator[i] = 0;
            carry = false;
            continue;
        }
        if(accumulator[i] + mcnadBinary[i] == 0 
            && carry == true){
            accumulator[i] = 1;
            carry = false;
            continue;
        }
        if(accumulator[i] + mcnadBinary[i] == 1){
            accumulator[i] = 1;
            carry = false;
            continue;
        }
        if(accumulator[i] + mcnadBinary[i] == 1
            && carry == true){
            accumulator[i] = 0;
            carry = true;
            continue;
        }
        if(accumulator[i] + mcnadBinary[i] == 2){
            accumulator[i] = 0;
            carry = true;
            continue;
        }
        if(accumulator[i] + mcnadBinary[i] == 2
            && carry == true){
            accumulator[i] = 1;
            carry = true;
            continue;
        }
    }
};

/*This function does the 1s complement to the given binary[]
and stores/write back it in binary[] */
void Multiplication::complement(int binary[], int n) const{
    for(int i = 0; i < n; i++){
        if(binary[i] == 0){
            binary[i] = 1;
            break;
        }
        if(binary[i] == 1){
            binary[i] = 0;
            break;
        }
    }
};

/*This function does the arithmetic shift right, extending the MSB of 
accumulator[]; In this, accumulator[] lsb is shifted to MSB of 
mplierBiary[] and so on; check sample output */
void Multiplication::arithShiftRight(int accumulator[], int mplierBinary[], 
    int &mplierLSB, int mplierLength, std::ostream &output) const{
        // Stores/sets LSBs
        int accuLSB = accumulator[mplierLength - 1];
        // This sets the new booth's bit.
        mplierLSB = mplierBinary[mplierLength - 1];
        // Loops to shift all values to right
        for(int i = mplierLength - 1; i > 0; i--){
            accumulator[i] = accumulator[i - 1];
            mplierBinary[i] = mplierBinary[i - 1];
        }
        // Sets mplier MSB equal to accu LSB.
        mplierBinary[0] = accuLSB;
        for(int i = 0; i < bits; i++){
            output << accumulator[i];
        }
        for(int i = 0; i < bits; i++){
            output << mplierBinary[i];
        }
    };

/*This function is to display the parameters accumulator[], 
mplierBinary[]; if output file is selected it writes to output file,
else prints on terminal window; It depends on your ostream object*/
void Multiplication::display(int accumulator[], int mplierBinary[], int mplierLength, 
    std::ostream &output) const{
        for(int i = mplierLength - 1; i >= 0; i--){
            output << accumulator[i];
        }
        output << endl;
        for(int i = mplierLength - 1; i >= 0; i--){
            output << mplierBinary[i];
        }
        output << endl;
    };

/*Use booth's algorithm to perform signed binary multiplication and 
write the results in terminal/console window*/ 
void Multiplication::performBoothAlgorithmUserInput(){
    cout << "Number of multiplicand bits=";
    cin >> bits;
    cout << "Enter the multiplicand in decimal=";
    cin >> multiplicand;
    cout << "Multiplicand in binary: ";
    cout << "Number of multiplier bits=";
    cin >> bits;
    cout << "Enter the multiplier in decimal=";
    cin >> multiplier;
    cout << "Multiplier in binary: ";

    performBoothAlgorithm(cout);
    cout << "Result in binary=";
    cout << "Result in decimal=";
};

/*This function gets the accumulator[], mplierBinary[] as input and 
converts it to decimal. It writes the result to an output file or terminal
depends upon the ofstream object */
void Multiplication::binaryToDecimal(int accumulator[], int mplierBinary[], 
    int mplierLength, std::ostream &output) const{
        int mplierPower = mplierLength - 1;
        int finalDec;
        if(accumulator[0] == 0){
            for(int i = mplierLength - 1; i < 0; i--){
                if(accumulator[i] == 1){
                    finalDec += pow(2, mplierPower + bits);
                }
                if(mplierBinary[i] == 1){
                    finalDec += pow(2, mplierPower);
                }
                mplierPower--;
            }   
        }
        if(accumulator[0] == 1){
            for(int i = mplierLength - 1; i < 0; i--){
                if(accumulator[i] == 0){
                    finalDec += pow(2, mplierPower + bits);
                }
                if(mplierBinary[i] == 1){
                    finalDec += pow(2, mplierPower);
                }
                mplierPower--;
            }   
        }
        output << finalDec << endl;
    };