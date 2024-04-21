#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
	myString s1("Bye");
	myString s2;

	s2 += s1;
	s2 += s1;
	s2 += s1;

	cout << s2 << endl;

	s1 += "Everyone";

	cout << s1 << endl;

	s1 += '!';

	cout << s1 << endl;

	return 0;
}