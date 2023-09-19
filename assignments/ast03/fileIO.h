#ifndef FILEIO_H
#define FILEIO_H

#include<iostream>
#include "investorType.h"
#include "stocksPortifolio.h"

class fileIO:public investorType, public stocksPortifolio{

public:
	unsigned int readWriteDataFile(ifstream &inFile, ofstream &outData);

};

#endif
