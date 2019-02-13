// Ariel Guerrero
// 2/8/2019
// conversion_AGuerrero.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;
/*
 
 Meat of the program that prompts the user on screen to enter the amount of miles to convert and 
 multiplies it by the conversion factor to get the Kilometers that equal to the same amount of 
 miles provided by the user.

*/
int main()
{
	// constant factor used to convert miles to km	
	double CONVERSIONFACTOR = 1.609;
	
	// variables that change: 
	double km = 0;
	double mi = 0;
	
	// prompts the user to do what we want them to do	
	cout << "Enter the Miles(mi) you would like to convert to Kilometers(km): ";

	// takes in the user input and stores it the variable for miles
	cin >> mi;

	// sets our variable for kilometers to miles * the conversion factor
	km = mi * CONVERSIONFACTOR;
	
	// display our results for the user to see on screen
	cout << fixed(3) << setprecision(3) <<"There are " << km << "km in " << mi << "mi." << endl;
}

