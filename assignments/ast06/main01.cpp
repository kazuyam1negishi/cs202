#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
	myString s1("Hello");
	myString s2("World");
	myString s3('#');
	myString s4;

	s4 = s1 + s2;
	cout << s4 << endl;

	s4 = s1 + s3 + s2;
	cout << s4 << endl;

	s4 = s1 + "Rockview";
	cout << s4 << endl;

	s4 = s2 + '!';
	cout << s4 << endl;

	return 0;
}