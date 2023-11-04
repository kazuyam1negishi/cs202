#ifndef FILEIO_H
#define FILEIO_H

#include<iostream>
#include "investorType.h"
#include "stocksPortfolio.h"

class fileIO:public investorType, public stocksPortfolio{

public:
	unsigned int readWriteDataFile(ifstream &inFile, ofstream &outData);

};

#endif
