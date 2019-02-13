//Ariel Guerrero
// 2/12/2019
// Description: Program that calculates total amount of money 
//				given the number of each type of coin given by the user
//

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;
/*
        Name: Main
  Parameters: None
 Description: takes the amount of pennies nickles dimes quarters and half dollars in the users pocket to 
			  calculate the total dollar amount 
*/
int main()
{
	//variables for the number of each coin in the users pocket
	int numP = 0;
	int numN = 0;
	int numD = 0;
	int numQ = 0;
	int numH = 0;
	
	// value to hold the total number of coins in the users pocket 
	int totalC = 0;
	
	// value each coin has 
	double pVal = 0.01;
	double nVal = 0.05;
	double dVal = 0.10;
	double qVal = 0.25;
	double hVal = 0.50;

	//total value of each coin in the users pocket 
	double pFVal = 0.0;
	double nFVal = 0.0;
	double dFVal = 0.0;
	double qFVal = 0.0;
	double hFVal = 0.0;

	// this variable is used to store the final amount of money once all other calculations have been made
	double totalAmount = 0.0;




	// prompt the user what we want them to do in this case enter in all the 
	// different coins they have so we can math for them
	cout << "Calculate the total value of your coins!" << endl;
	cout << "INPUT NUMBER OF PENNIES: ";
	cin >> numP;
	cout << "INPUT NUMBER OF NICKLES: ";
	cin >> numN;
	cout << "INPUT NUMBER OF DIMES: ";
	cin >> numD;
	cout << "INPUT NUMBER OF QUARTERS: ";
	cin >> numQ;
	cout << "INPUT NUMBER OF HALF DOLLARS: ";
	cin >> numH;

	// adds up all the coins to tell the user how many coins they had 
	totalC = numP + numN + numD + numQ + numH;

	// gets the total values for each type of coin and makes sure the value is in cents 
	
	pFVal = numP * pVal;
	
	nFVal = numN * nVal;
	
	dFVal = numD * dVal;
	
	qFVal = numQ * qVal;
	
	hFVal = numH * hVal;
	
	// final amount of money ( adding up all the values of all the coins)
	totalAmount = (pFVal + nFVal + dFVal + qFVal + hFVal);
	
	// displaying final results to the screen for the user to see 
	cout << "\n YOUR RESULTS ARE:  " << endl;
	cout << setprecision(2) << fixed << numP << " Pennie(s) for " << pFVal << " Dollar(s)" << endl;
	cout << setprecision(2) << fixed << numN << " Nickle(s) for " << nFVal << " Dollar(s)" << endl;
	cout << setprecision(2) << fixed << numD << " Dime(s) for " << dFVal << " Dollar(s)" << endl;
	cout << setprecision(2) << fixed << numQ << " Quarter(s) for " << qFVal << " Dollar(s)" << endl;
	cout << setprecision(2) << fixed << numH << " Half Dollar(s) for " << hFVal << " Dollar(s)" << endl;

	cout << "For a total of " << totalC << " coins and a total value of $" << totalAmount << " Dollar(s)" << endl;

}