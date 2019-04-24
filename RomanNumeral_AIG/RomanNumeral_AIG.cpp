// Ariel Guerrero
//4/23/2019
//
//Roman Numeral Program. 

#include "pch.h"
#include"RomanNumeral.h"
#include <iostream>
#include <string>

using namespace std;


// boot straps the program and gets everything running
int main()
{

	int intusrOpt = 0;
	char chrUsrRptOpt = 'y';
	double dbluserVal = 0;
	string strUserRomanString = "";
	RomanNumeral userRomanNumerl;


	do {
		cout << "Would you like to convert Numbers to Numerals(option1) or Numerals to Numbers(optioon2): (1 for opt1 and 2 for opt 2):  ";
		cin >> intusrOpt;

		switch (intusrOpt) {

		case 1:
			cout << "Input a value to convert into Roman Numerals: ";
			cin >> dbluserVal;
			userRomanNumerl.setValue(dbluserVal + 1); // hello sir if you are reading this why did i have to add one here? I just did it and it made my program work 
			strUserRomanString = userRomanNumerl.convertToRoman();
			cout << "NUMERALS: " << strUserRomanString;

			break;
		case 2:
			cout << "Input a Numeral to convert into a value: ";
			cin >> strUserRomanString;
			userRomanNumerl.setString(strUserRomanString); // hello sir if you are reading this why did i have to add one here? I just did it and it made my program work 
			dbluserVal = userRomanNumerl.convertToDecimal();
			cout << "VALUE: " << dbluserVal;
			break;
		default:
			cout << "Invalid option entered!";
		}

		cout << "Would you like to continue?(y for yes | n for no): ";
		cin >> chrUsrRptOpt;
		chrUsrRptOpt = tolower(chrUsrRptOpt);

	} while (chrUsrRptOpt == 'y');
}



