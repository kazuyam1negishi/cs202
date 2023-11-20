/*
    Name: Jimmy Soto Agustin, 5008099390, 1001, Assignment 7
    Description: Matryoshka doll function definitions
    Input: None
    Output: All dolls being opened (along with which number doll)
*/

#include "matryoshka.h"

/* */
void MatryoshkaDoll::openDoll()
{
	//TODO: Finish the function
	//This should print the doll that is being opened, and then open the next doll
	//To do the same if there is a doll inside this one.
	printDoll();
	if(dollInside != nullptr){
		dollInside->openDoll();
	}
}

/* */
MatryoshkaDoll::~MatryoshkaDoll()
{
	//TODO: Finish the function
	//Deallocate any dolls contained within this one if they exist
	if(dollInside != nullptr){
		delete dollInside;
	}
}

/* Prints that the doll is being opened alongside its id */
void MatryoshkaDoll::printDoll()
{
	cout << "Opening doll (" << id << " / " << count << ")" << endl;
}