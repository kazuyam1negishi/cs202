#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
	myString str;

	cout << "Enter a string: ";
	cin >> str;
	cout << endl;

	cout << str << endl;

	cout << "Enter another string: ";
	cin >> str;
	cout << endl;

	cout << str << endl;
	
	return 0;
}