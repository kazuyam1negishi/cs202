/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 6
    Description: Custom string class
    Input: String (>>), or length and string (sLength, s).
    Output: String formed using overloaded functions.
*/

#include <iostream>
#include <cstdlib>
#include "myString.h"
using namespace std;

/*---------------------------------------------
Default constructor
---------------------------------------------*/
myString::myString(){
  s = NULL;
  sLength = 0;
}
/*---------------------------------------------
Constructor that sets the object equal to a
string literal passed into it
---------------------------------------------*/
myString::myString(const char str[]){
  // Runs through string to find size,
  // sets size and creates char array.
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }
  sLength = i;
  s = new char [sLength];
  // Adds str values to s until '\0'.
  i = 0;
  while(str[i] != '\0'){
    s[i] = str[i];
    i++;
  }
}
/*---------------------------------------------
Overloading the default copy constructor since
we have a pointer variable in the class
---------------------------------------------*/
myString::myString(const myString& str){
  sLength = str.length();
  s = new char [sLength];
  if(sLength != 0){
    for(int i = 0; i < sLength; i++){
    s[i] = str.s[i];
    }
  } else {
    delete [] s;
    s = nullptr;
    sLength = 0;
  }
}
/*---------------------------------------------
Constructor that sets the object equal to a
character passed into it
---------------------------------------------*/
myString::myString(char c){
  sLength = 1;
  s = new char [sLength];
  s[0] = c;
}
/*---------------------------------------------
Function: [] operator overload
Parameters: integer
Return: myString s value at given integer
Description: get value from myObject s array
---------------------------------------------*/
char& myString::operator[](int i){
  return(s[i]);
}
/*---------------------------------------------
Function: length getter function
Parameters: none
Return: myString length
Description: return length of myString object
---------------------------------------------*/
int myString::length() const{
  return(sLength);
}
/*---------------------------------------------
Function: = overload
Parameters: myString object
Return: *this, or currently working object
Description: sets current object equal to given object
---------------------------------------------*/
const myString& myString::operator=(const myString& str){
  // Checks if the strings are not equal
  // If not, our code runs.
  if (this != &str){
    // If the initial string is not
    // empty, empty it.
    if(s != nullptr){
      delete [] s;
      s = nullptr;
      sLength = 0;
    }
    // Checks if str is empty. If so,
    // this-> remains empty. If not,
    // str gets copied over.
    if(str.s != nullptr){
      sLength = str.sLength;
      s = new char [sLength];
      for(int i = 0; i < sLength; i++){
        s[i] = str.s[i];
      }
    }
  }
  return *this; 
}
/*---------------------------------------------
Function: = overload
Parameters: char[]
Return: *this, or currently working object
Description: sets current object equal to char array
---------------------------------------------*/
const myString& myString::operator=(const char str[]){
  // Checks if s is not empty.
  if(s != nullptr){
    delete [] s;
    s = nullptr;
    sLength = 0;
  }
  // Checks if str[] is empty.
  // If not, copying starts.
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }
  sLength = i;
  s = new char [sLength];
  // Adds str values to s until '\0'.
  i = 0;
  while(str[i] != '\0'){
    s[i] = str[i];
    i++;
  }
  return(*this);
} 
/*---------------------------------------------
Function: = overload
Parameters: char
Return: *this, or current working object
Description: sets object equal to given char
---------------------------------------------*/
const myString& myString::operator=(char rhs){
  // Checks if s is not empty.
  if(s != nullptr){
    delete [] s;
    s = nullptr;
  }
  // There is no way this can be empty,
  // so this statically sets the length
  // and char from the rhs variable.
  sLength = 1;
  s = new char [sLength];
  s[0] = rhs;
  // Exit.
  return(*this);
}
/*---------------------------------------------
Function: == overload
Parameters: myString object
Return: true if same string, false if not
Description: checks current object to see if same as given object
---------------------------------------------*/
bool myString::operator==(const myString& str) const{
  // Initial check to see if length is same
  if(sLength != str.sLength){
    return(false);
  }
  // Checks if both lengths are 0
  if(sLength == 0 && str.sLength == 0){
    return(false);
  }
  // Checks if any letter in either string is not equal
  for(int i = 0; i < sLength; i++){
    if(s[i] != str.s[i]){
      return(false);
    }
  }
  // If everything checks out, the strings are equal
  return(true);
}
/*---------------------------------------------
Function: + overload
Parameters: myString object
Return: *this, or currently working object.
Description: adds myString str to current object.
---------------------------------------------*/
myString myString::operator+(const myString& str) const{
  // Checks if str is empty or unallocated.
  // If not, copying can happen.
  if(str.s != nullptr){
    // Temp object allocated to store new char array.
    // I'm using this-> keywords for these functions
    // because I KNOW I'm going to forget this. Probably.
    myString temp;
    temp.sLength = str.sLength + this->sLength;
    temp.s = new char [temp.sLength];
    // Copying from this-> to temp.
    for(int i = 0; i < sLength; i++){
      temp.s[i] = s[i];
    }
    // Now copying from str to temp.
    for(int i = 0; i < str.sLength; i++){
      temp.s[i + this->sLength] = str.s[i];
    }
    // Returns temp only if concatenation successful.
    return(temp);
  }
  // Otherwise, *this returned.
  return(*this);
}
/*---------------------------------------------
Function: + overload
Parameters: char[]
Return: this.s[] added with rhs[]
Description: adds rhs[] at end of this.s[]
---------------------------------------------*/
myString myString::operator+(const char rhs[]) const{
  // Checks how many chars long rhs is.
  int rightCount = 0;
  while(rhs[rightCount] != '\0'){
    rightCount++;
  }
  // If 0, then copying fails.
  // If not 0, copying starts.
  if(rightCount != 0){
    myString temp;
    temp.sLength = this->sLength + rightCount;
    temp.s = new char [temp.sLength];
    // Copying from this-> to temp.
    for(int i = 0; i < sLength; i++){
      temp.s[i] = s[i];
    }
    // Now copying from rhs to temp.
    for(int i = 0; i < rightCount; i++){
      temp.s[i + sLength] = rhs[i];
    }
    return(temp);
  }
  return(*this);
}
/*---------------------------------------------
Function: + overload
Parameters: char
Return: s[] added with char
Description: adds char at end of object's s[]
---------------------------------------------*/
myString myString::operator+(char rhs) const{
  myString temp;
  temp.sLength = this->sLength + 1;
  temp.s = new char [temp.sLength];
  for(int i = 0; i < sLength; i++){
    temp.s[i] = s[i];
  }
  temp.s[this->sLength] = rhs;
  return(temp);
}
/*---------------------------------------------
Function: += overload
Parameters: myString object
Return: this.s[] added with rhs.s[]
Description: adds current object's s[] with rhs.s[]
---------------------------------------------*/
const myString& myString::operator+=(const myString& rhs){
  // Checks if str is empty or unallocated.
  // If not, copying can happen.
  if(rhs.s != nullptr){
    // Temp object allocated to store new char array.
    // I'm using this-> keywords for these functions
    // because I KNOW I'm going to forget this. Probably.
    myString temp;
    temp.sLength = rhs.sLength + this->sLength;
    temp.s = new char [temp.sLength];
    // Copying from this-> to temp.
    for(int i = 0; i < sLength; i++){
      temp.s[i] = s[i];
    }
    // Now copying from str to temp.
    for(int i = 0; i < rhs.sLength; i++){
      temp.s[i + this->sLength] = rhs.s[i];
    }
    delete [] s;
    s = new char [temp.sLength];
    sLength = temp.sLength;
    for(int i = 0; i < temp.sLength; i++){
      s[i] = temp.s[i];
    }
  }
  // Otherwise, *this returned.
  return(*this);
}
/*---------------------------------------------
Function: += overload
Parameters: char[]
Return: myString s[] added with rhs[]
Description: adds rhs[] at end of s[]
---------------------------------------------*/
const myString& myString::operator+=(const char rhs[]){
  // Checks how many chars long rhs is.
  int rightCount = 0;
  while(rhs[rightCount] != '\0'){
    rightCount++;
  }
  // If 0, then copying fails.
  // If not 0, copying starts.
  if(rightCount != 0){
    myString temp;
    temp.sLength = this->sLength + rightCount;
    temp.s = new char [temp.sLength];
    // Copying from this-> to temp.
    for(int i = 0; i < sLength; i++){
      temp.s[i] = s[i];
    }
    // Now copying from rhs to temp.
    for(int i = 0; i < rightCount; i++){
      temp.s[i + sLength] = rhs[i];
    }
    delete [] s;
    s = new char [temp.sLength];
    sLength = temp.sLength;
    for(int i = 0; i < temp.sLength; i++){
      s[i] = temp.s[i];
    }
  }
  return(*this);
}
/*---------------------------------------------
Function: += overload
Parameters: char
Return: myString s[] added with given char
Description: adds char at end of s[]
---------------------------------------------*/
const myString myString::operator+=(char rhs){
  myString temp;
  temp.sLength = this->sLength + 1;
  temp.s = new char [temp.sLength];
  for(int i = 0; i < sLength; i++){
    temp.s[i] = s[i];
  }
  temp.s[this->sLength] = rhs;
  delete [] s;
  s = new char [temp.sLength];
  sLength = temp.sLength;
  for(int i = 0; i < temp.sLength; i++){
    s[i] = temp.s[i];
  }
  return(*this);
}
/*---------------------------------------------
Function: destructor
Parameters: none
Return: none
Description: deallocates used memory
---------------------------------------------*/
myString::~myString(){
  if(s != nullptr){
    delete [] s;
    s = nullptr;
    sLength = 0;
  }
}
/*---------------------------------------------
Function: + overload
Parameters: char[] and myString object
Return: char[] added with char[] from myString
Description: adds lhs[] with rhs.s[]
---------------------------------------------*/
myString operator+(const char lhs[], const myString& rhs){
  int leftCount = 0;
  while(lhs[leftCount] != '\0'){
    leftCount++;
  }
  myString temp;
  temp.sLength = leftCount + rhs.sLength;
  temp.s = new char [temp.sLength];
  for(int i = 0; i < leftCount; i++){
    temp.s[i] = lhs[i];
  }
  for(int i = 0; i < rhs.sLength; i++){
    temp.s[i + leftCount] = rhs.s[i];
  }
  return(temp);
}
/*---------------------------------------------
Function: + overload
Parameters: char and myString object
Return: char added with char[] from myString
Description: adds lhs to rhs.s[]
---------------------------------------------*/
myString operator+(char lhs, const myString& rhs){
  myString temp;
  temp.sLength = rhs.sLength + 1;
  temp.s = new char [temp.sLength];
  // Set char first
  temp.s[0] = lhs;
  for(int i = 0; i < rhs.sLength; i++){
    temp.s[i+1] = rhs.s[i];
  }
  return(temp);
}
/*---------------------------------------------
Function: output operator overload
Parameters: ostream and myString object
Return: ostream object
Description: prints out str.s[] until '\n'
---------------------------------------------*/
ostream& operator<<(ostream& out, const myString& str){
  //Your code goes here
  if(str.s != nullptr){
    for(int i = 0; i < str.sLength; i++){
      out << str.s[i];
    }
    out << endl;
  }
  return out;
}
/*---------------------------------------------
Function: input operator overload;
Parameters: istream and myString object
Return: istream object
Description: grabs user string and sets equal to str.s[]
---------------------------------------------*/
istream& operator>>(istream& in, myString& str){
  // Char to store current char from in.
  if(str.s != nullptr){
    delete [] str.s;
    str.s = nullptr;
    str.sLength = 0;
  }
  char ch = ' ';
  while(in.get(ch) && ch != '\n'){
    str += ch;
  }
  return in;
}