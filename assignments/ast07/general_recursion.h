#ifndef RECURSION_H
#define RECURSION_H

#include <iostream>
#include <string>

using namespace std;

//This file contains several functions that solve generic recursive problems. 
//TODO: Please finish each and test them using the provided main

/* Your description here */
void countBackwards(int num){
	//This function should recursively print all integers backwards stopping at 0
	//Consider your base case and how you might print the next number
	if(num == 0){
		cout << num << endl;
		return;
	} else {
		cout << num << ", ";
	}
	countBackwards(num - 1);
}

/* */
int sumToN(int n)
{
	//Recursively compute the sum up to n of a number. 
	//To problem solve, consider how you might break up the problem to reduce it
	//And what a trivial base case that is easy to sum might be
	if(n == 0){
		return(0);
	}
	return(n + sumToN(n-1));
}

/* */
bool isValueInArray(int arr[], int start, int length, const int& value)
{
	/*
	*Check if the array is of length 0, in which case, the solution is trivial
	*(we can't find any value in an empty array)
	
	*Check if the current element being looked at is a match
	*If so, we found it

	*If we did not find the element, recursively search for it.
	*Knowing that the list is already sorted, if the value is less than the middle of the list,
	*search the sub array to the left, else search the array to the right.
	*Please see the provided video for a more detalied explanation */
	
	int leftLength = length / 2; //Length of the left array
	int rightLength = length - leftLength; //Length of the right subarray
	int middle = start + leftLength;

	if(length == 0){
		return(false);
	}
	if(arr[middle] == value){
		return(true);
	}
	if(arr[middle] > value){
		return(isValueInArray(arr, start, leftLength - 1, value));
	}
	if(arr[middle] < value){
		return(isValueInArray(arr, middle + 1, rightLength - 1, value));
	}
	return(false);
	// also ooh binary search :D
}

#endif
