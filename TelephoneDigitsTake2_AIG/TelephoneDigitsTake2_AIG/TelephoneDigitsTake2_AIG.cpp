
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
/*
name: main
parameters: n/a
description: gets the users input and spits out a phone number corresponding to the letter or number or character they pushed


*/
int main()
{
	string strUsrInputString = "DEFAULT";
	string strPhoneNumber = "";
	string strLeftover = "";
	
	char chrCurrentCharacterHolder = ' ';
	char chrUserRepeatOption = 'y';
	int intLoopCounter = 0;
	do {
		// just incase anything from last run is left over i just reset everything to make sure im starting off clean
		strUsrInputString = "DEFAULT";
		strPhoneNumber = "";
		cout << "Enter Letters corresponding to a phone number: " << endl;
		do {
			cin >> chrCurrentCharacterHolder;  // <-- how is this working if i can hit backspace and type multiple before hitting enter?
			// cout << "YOU NEED " << 10 - strPhoneNumber.size() << " MORE CHARACTERS!" << endl; // only want this to display once per enter 
			// only converting characters to uppercase if they are a lowercase letter in between 96 and 123 so 97-122
			if (((int)chrCurrentCharacterHolder > 96) && ((int)chrCurrentCharacterHolder < 123)) {
				chrCurrentCharacterHolder = toupper(chrCurrentCharacterHolder);
			}
			// magic happens here
			switch (chrCurrentCharacterHolder) {
			case '1':
				strPhoneNumber += "1";
				break;
			case '2': case 'A': case 'B': case 'C':
				strPhoneNumber += "2";
				break;
			case '3': case 'D': case 'E': case 'F':
				strPhoneNumber += "3";
				break;
			case '4': case 'G': case 'H': case 'I':
				strPhoneNumber += "4";
				break;
			case '5': case 'J': case 'K': case 'L':
				strPhoneNumber += "5";
				break;
			case'6':case 'M': case 'N': case 'O':
				strPhoneNumber += "6";
				break;
			case '7': case 'P': case 'Q': case 'R': case 'S':
				strPhoneNumber += "7";
				break;
			case '8': case 'T': case 'U': case 'V':
				strPhoneNumber += "8";
				break;
			case '9': case 'W': case 'X': case 'Y': case 'Z':
				strPhoneNumber += "9";
				break;
			case '0':
				strPhoneNumber += "0";
				break;
			case '*':
				strPhoneNumber += "*";
				break;
			case '#':
				strPhoneNumber += "#";
				break;
			default:
				cout << "ERROR "<< chrCurrentCharacterHolder <<" IS NOT A CHARACTER ON THE PHONE!" << endl;
			}
			
			chrCurrentCharacterHolder = ' ';
			intLoopCounter++;
		} while (strPhoneNumber.size() < 10);

			strPhoneNumber = "(" + strPhoneNumber.substr(0, 3) + ")" + strPhoneNumber.substr(3, 3) + "-" + strPhoneNumber.substr(6, 4);
			cout << "Your phone number produced is: " << strPhoneNumber << endl;

			// had to do this just incase they had used more than 10 chars 
		cin >> strLeftover;
		strLeftover = ""; // poof and now its gone
		// restore for next run!
		strPhoneNumber = "";
	
		// easier for testing so i dont have to keep reseting  
		cout << "Would you like to repeat this process? (y for yes, n for no): " << endl;
		cin >> chrUserRepeatOption;
		
		chrUserRepeatOption = tolower(chrUserRepeatOption);

	} while (chrUserRepeatOption == 'y');
	return 0;
}