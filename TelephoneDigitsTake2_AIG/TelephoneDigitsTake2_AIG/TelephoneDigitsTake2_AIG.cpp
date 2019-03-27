// TelephoneDigitsTake2_AIG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strUsrInputString = "DEFAULT";
	string strPhoneNumber = "";
	char chrCurrentCharacterHolder = ' ';
	char chrUserRepeatOption = 'y';
	do {
		cout << "Enter Letters corresponding to a phone number: " << endl;
		getline(cin,strUsrInputString);
		// make sure the user is using the right length 
		if (strUsrInputString.size() != 7) {
			cout << "Enter Letters corresponding to a phone number: " << endl;
			cout << "EXACTLY 7 LETTERS ARE NEEDED! " << endl;
			getline(cin,strUsrInputString);
		}
		// just need it to go through for 7 digits after that I dont care 
		for (unsigned int charCheck = 0; charCheck < 7; charCheck++) {
			chrCurrentCharacterHolder = strUsrInputString.at(charCheck);
			cout << "Current Char: " << chrCurrentCharacterHolder << endl;
			//																									a-z
			// only converting characters to uppercase if they are a lowercase letter in between 96 and 123 so 97-122
			if (((int)chrCurrentCharacterHolder > 96) && ((int)chrCurrentCharacterHolder < 123)) {
				chrCurrentCharacterHolder = toupper(chrCurrentCharacterHolder);
			}
			// magic happens here
			switch (chrCurrentCharacterHolder) {
			case ' ':
				strPhoneNumber += "1"; // needs more work here and for the last case 
				break;
			case 'A': case 'B': case 'C':
				strPhoneNumber += "2";
				break;
			case 'D': case 'E': case 'F':
				strPhoneNumber += "3";
				break;
			case 'G': case 'H': case 'I':
				strPhoneNumber += "4";
				break;
			case 'J': case 'K': case 'L':
				strPhoneNumber += "5";
				break;
			case 'M': case 'N': case 'O':
				strPhoneNumber += "6";
				break;
			case 'P': case 'Q': case 'R': case 'S':
				strPhoneNumber += "7";
				break;
			case 'T': case 'U': case 'V':
				strPhoneNumber += "8";
				break;
			case 'W': case 'X': case 'Y': case 'Z':
				strPhoneNumber += "9";
				break;
			case '+':
				strPhoneNumber += "0"; // couldnt get this to work... hmmm?
				break;
			default:
				cout << "THIS IS NOT A LETTER!" << endl;
				cout << "AN \"X\" WILL BE SHOWN IN THE PHONE NUMBER IN PLACE OF THE INCORRECT INPUT!" << endl;
				strPhoneNumber += "X";
			}
		}
		// taking pride in my work and making things look good-ish	
		strPhoneNumber = strPhoneNumber.substr(0, 3) + "-" + strPhoneNumber.substr(3, 4);
		cout << "Your phone number produced is: " << strPhoneNumber << endl;
		strPhoneNumber = "";
		// easier for testing so i dont have to keep having to reset 
		cout << "Would you like to repeat this process? (y for yes, n for no): " << endl;
		cin >> chrUserRepeatOption;
	} while (chrUserRepeatOption == 'y');
	return 0;
}