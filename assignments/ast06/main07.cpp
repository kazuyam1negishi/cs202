#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
	myString s1("Joey");
	myString s2("Johnny");
	myString s3("DeeDee");
	myString s4("Tommy");
	myString s5("Marky");
	myString s6;

	s3 = s1;

	cout << s3 << endl;
	
	s3 = s4;

	cout << s3 << endl;

	s3 = "Bill And Ted";

	cout << s3 << endl;

	s3 = 'R';

	cout << s3 << endl;

	return 0;
}