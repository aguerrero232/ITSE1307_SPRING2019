// Ariel Guerrero
// 3/20/2019
// SumOfDigits_AIG.cpp - finds the sum of the digits within a certain value inputted by the user
//

#include "pch.h"
#include <iostream>

using namespace std;
/*
		       Name: main
	     Parameters: n/a
		Description: takes in a number from the user and adds up all the numbers that make it up then dispays the current digit while looping
					 once the calcualtions are finished.

*/
int main()
{

	int intUserNumber = 0;
	int intUserNumHolder = 0;
	int intModHolder = 0;
	int intSumOfDigits = 0;
	
	cout << "Input a whole number so we can find its Sum of Digits: ";
	cin >> intUserNumber; 

	intUserNumHolder = intUserNumber;

	while(intUserNumHolder !=0){
		
		intModHolder = intUserNumHolder % 10; // gets the number all the way to the right
		cout << "Current Digit (right to left):  " << intModHolder << endl;
		intSumOfDigits += intModHolder;
		intUserNumHolder = intUserNumHolder / 10; // gets rid of the number we just got moving over the next closest value also makes sure we arent looping infinitely

	}

	// output for the user 
	cout << "The Sum of Digits for " << intUserNumber << " is " << intSumOfDigits << "!"<< endl;

}

