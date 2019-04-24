// RomanNumeral_AIG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "RomanNumeral.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	double dblUserValue = 0.0;
	string strRomanNumerals = "";
	
	cout << "Input a Number you want to convert into Roman Numerals" << endl;
	cout << "NUMBER: " ;
	cin >> dblUserValue;

	RomanNumeral r1;
	r1.setValue(dblUserValue);
	strRomanNumerals = r1.convertToRoman();

	cout << "That is " << strRomanNumerals << " in Roman Numerals." << endl;

}