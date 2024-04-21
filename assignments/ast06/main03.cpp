#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
	myString s1("Day");
	myString s2;

	s2 = "Green" + s1;
	cout << s2 << endl;

	s2 = 'A' + s1;
	cout << s2 << endl;
	
	return 0;
}