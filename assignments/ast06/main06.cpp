#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
	myString str("Bracket operator test");

	for (int i = 0; i < str.length(); i++)
		cout << str[i] << " ";

	cout << endl;

	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);

	cout << str << endl;
	
	return 0;
}