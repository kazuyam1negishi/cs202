#include <iostream>
using namespace std;

class myString
{
public:
	myString();
	myString(const char str[]);
	myString(const myString&);
	myString(char);
	char& operator[](int);
	int length() const;
	const myString& operator=(const myString&);
	const myString& operator=(const char[]); 
	const myString& operator=(char);
	myString operator+(const myString&) const;
	myString operator+(const char[]) const;
	myString operator+(char) const;
	const myString& operator+=(const myString&);
	const myString& operator+=(const char[]);
	const myString operator+=(char);
	bool operator==(const myString&) const;
	~myString();
	friend myString operator+(const char[], const myString&);
	friend myString operator+(char, const myString&);
	friend ostream& operator<<(ostream& out, const myString&);
	friend istream& operator>>(istream& in, myString&);
private:
	int sLength;
	char * s;
};