// RomanNumeral_AIG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include"RomanNumeral.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int intuserVal = 0;
	string strUserRomanString = "";
	

	cout << "Input an Integer value to convert into Roman Numerals: ";
	cin >> intuserVal;
	RomanNumeral userRomanNumerl(intuserVal);

	cout << userRomanNumerl.toString;

}



