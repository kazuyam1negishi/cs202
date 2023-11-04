//This file exists to test your file reading in the Store class.
//Nothing needs to be added here, the makefile will use this to build a testing program
#include "../item.h"
#include "../store.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

const string INPUT_FILE = "input/toy_catalog.txt";

int main()
{
	ifstream infile(INPUT_FILE);
	if(!infile.good())
	{
		cout << "Could not find file: " + INPUT_FILE << endl;
		cout << "Are the input files still in the input directory?" << endl;
		return 1;
	}
	
	cout << "Testing reading from file..." << endl;
	Store store;
	store.readItemsFromFile(infile);
	store.printCatalog();

	return 0;
}


