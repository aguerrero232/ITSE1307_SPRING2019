// Ariel Guerrero
// 2/21/2019
// calculation for in class exercise  finding the value of c given a and b from the user.

#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

/*
		 Name: Main
   Parameters:
  Description: takes two floating point values to do some calcualtion and returns the result 
			   which is also a floating point value and displays it to the screen so the user
			   can see the results
				

*/
int main()
{
	// variables we will be using for our calcualtion,input and output.
	double top = 0;
	double bot = 0;
	double a = 0;
	double b = 0;
	double c = 0;

	// prompt the user to enter in what we want.
	cout << " we will find the answer to c = ab / a-b." << endl;
	
	// prompts the user to get a and b
	cout << "Please enter a: ";
	cin >> a;

	cout << "Please enter b: ";
	cin >> b;

	// math for the user 
	top= a*b;
	bot = a-b;
	
	c = top/bot;
	if (bot == 0) {
		c = 0;
	}

	// output data to the user 
	cout << "The answer to " << a << "*" << b << "/" << a << "-" << b << " is equal to " << c << endl;
}