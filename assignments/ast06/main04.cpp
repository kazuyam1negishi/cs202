#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
	myString s1("Rickenbacker");
	myString s2("Rickenbacker");
	myString s3("Fender");
	myString s4("Fendre");

	if (s1 == s2)
		cout << "Same string" << endl;

	if (!(s2 == s3))
		cout << "Not the same string" << endl;
	
	if (!(s3 == s4))
		cout << "Not the same string" << endl;

	return 0;
}