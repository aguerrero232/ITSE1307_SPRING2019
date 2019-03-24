// Ariel Guerrero
// 3/24/2019
// Converts Telephone numbers to alphabet letters and vise versa

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

/*
name: main
parameters: n/a
description: meat of the entire program, everything resides in here. just takes in either a phone number or characters and outputs which ever wasnt entered.
			 I should make alot of this into functions but I "technically" dont know how yet 

*/
int main()
{
	string strTNum = "";
	string strTNumHolder = "";
	string strFormattedTNum = "";

	char chrFirstChar = ' ';
	char chrSecondChar = ' ';
	char chrThirdChar = ' ';
	char chrRepeatOpt = 'y';
	char chrTNumChHolder = ' ';
	
	unsigned int intChrPos = 0;
	int intSkipLoop = 0;
	int intPosOfset1 = 0;
	int intPosOfset2 = 0;
	int intNumPortionHolder = 0;
	int intLength = 0; 
	int intUserChoice = 0;
	int intFirstRun = 0;

	bool choice = true;
	
	// big super loop with alot of loops inside 
	do {
		
		cout << "Would you like to Convert Phone Numbers to Characters or Characters to Phone Numbers? " << endl;
		cout << endl << "     1 for Phone Numbers to Characters || 2 for Characters to Phone Numbers || 3 to exit the program! " << endl;
		cin >> intUserChoice;
		
		switch (intUserChoice) {
		case 1:
			// NUMS TO CHAR
			do {
				strTNumHolder = "";
				// Prompting for the users input
				cout << endl << "Please enter a Telephone Number (NUMBERS ONLY!): ";
				// why not have fun with it 
				if (intFirstRun == 0) {
					cout << endl << "-> this program is (210)873-1169 test the number to reveal the code!" << endl;
					intFirstRun++;
				}
				// input 
				cin >> strTNum;
				// checking to see if the input in valid
				if (strTNum.length() != 10 && strTNum.length() > 7) {
					cout << endl << "ERROR USE ONLY NUMBERS!";
					cout << endl << "PLEASE USE FORMAT XXXXXXXXXX for numbers with an area code or XXXXXXX for numbers without an area code!";
					cout << endl << "Please enter a VALID Telephone Number: ";
					cin >> strTNum;
				}
				//logic part
				for (unsigned int position = 0; position < strTNum.length(); ) {
					intPosOfset1 = position + 1;
					intPosOfset2 = position + 2;
					// look for three digit numbers starting with a 1
					if (strTNum.at(position) == '1' && (strTNum.length() - position >= 3) && intSkipLoop != 1) {
						// gets the first 3 numbers 
						chrFirstChar = strTNum.at(position);
						chrSecondChar = strTNum.at(intPosOfset1);
						chrThirdChar = strTNum.at(intPosOfset2);
						//	cout << chrFirstChar << "," << chrSecondChar << "," << chrThirdChar << endl; // debugging
						intNumPortionHolder = ((int)(chrFirstChar)-48) * 100 + ((int)(chrSecondChar)-48) * 10 + ((int)(chrThirdChar)-48);
						//	cout << "NUMBER: " << intNumPortionHolder << endl; // debugging
						if (intNumPortionHolder < 123) {
							strTNumHolder += (char)intNumPortionHolder;
							cout << endl << "LOWERCASE LETTER:" << (char)intNumPortionHolder << endl;
							cout << "NUMBER: " << intNumPortionHolder << endl; // debugging
							intSkipLoop = 0;
							position += 3;
						}
						else { // not between 100 and 122
							cout << endl << "ERROR NOT A LETTER:" << (char)intNumPortionHolder << endl;
							cout << "NUMBER: " << intNumPortionHolder << endl; // debugging
							intSkipLoop = 1;
						}
					}
					// check to see if the value converts to charachters A-Z or a-c if not then goes to next digit
					else if ((strTNum.length() - position >= 2)) {
						chrFirstChar = strTNum.at(position);
						chrSecondChar = strTNum.at(intPosOfset1);
						//	cout << chrFirstChar << "," << chrSecondChar << endl; // debugging
						intNumPortionHolder = ((int)(chrFirstChar)-48) * 10 + ((int)(chrSecondChar)-48);
						//	cout << "NUMBER: " << intNumPortionHolder << endl; // debugging
						// first if checks for lowercase a-c
						if (intNumPortionHolder > 96 && intNumPortionHolder < 100) {
							strTNumHolder += (char)intNumPortionHolder;
							cout << endl << "LOWERCASE LETTER:" << (char)intNumPortionHolder << endl;
							cout << "NUMBER: " << intNumPortionHolder << endl; // debugging
							position += 2;
						}
						// checks if the number converts to characters A - Z
						else if (intNumPortionHolder < 91 && intNumPortionHolder > 64) {
							strTNumHolder += (char)intNumPortionHolder;
							cout << endl << "CAPITAL LETTER:" << (char)intNumPortionHolder << endl;
							cout << "NUMBER: " << intNumPortionHolder << endl; // debugging
							position += 2;
						}
						// not characters A-Z or a-c so goes to the next character
						else {
							cout << endl << "ERROR NOT A LETTER:" << (char)intNumPortionHolder << endl;
							cout << "NUMBER: " << intNumPortionHolder << endl; // debugging
							position++;
						}
					}
					// length-position = 1
					else {
						chrFirstChar = strTNum.at(position);
						intNumPortionHolder = ((int)(chrFirstChar)-48);
						cout << endl << "ERROR NOT A LETTER:" << (char)intNumPortionHolder << endl;
						cout << "NUMBER: " << intNumPortionHolder << endl; // debugging
						position++;
					}
				}
				strTNumHolder = "\"" + strTNumHolder + "\"";
				cout << endl << "YOUR PHONE NUMBER SPELLS: " << strTNumHolder << "!" << endl;
				cout << "Would you like to repeat converting Telphone numbers into Charachters? (y for YES n for NO): " << endl;
				cin >> chrRepeatOpt;
				chrRepeatOpt = towlower(chrRepeatOpt);
			} while (chrRepeatOpt == 'y');
			choice = false;
			break;

		case 2:
			// CHARS TO NUMS
			do {
				cout << endl << "Please enter Characters to convert to a Phone Number: ";
				cin >> strTNum;
				// reset all the variables to be safe after redoing 
				strTNumHolder = "";
				intLength = strTNum.length();
				intNumPortionHolder = 0;
				chrTNumChHolder = ' ';
				intChrPos = 0; // why does this have to be an unsigned int?
				// keeps looping till we have a number at the length we want 
				while (strTNumHolder.length() < 10) {
					if ( intChrPos >= strTNum.length()) {
						cout << "NOT ENOUGH CHARACTERS ADDED PADDING WITH 0s" << endl;
							strTNumHolder += "0";
					}
					else {
						chrTNumChHolder = strTNum.at(intChrPos);
						intNumPortionHolder = (int)chrTNumChHolder;
						// check to see if the char is valid (letters only)
						if ((intNumPortionHolder > 64 && intNumPortionHolder < 91) || (intNumPortionHolder > 96 && intNumPortionHolder < 123)) {

							strTNumHolder += to_string(intNumPortionHolder);
							cout << "CHAR: " << chrTNumChHolder << endl;
							cout << "INT: " << intNumPortionHolder << endl;
							cout << "STRING: " << strTNumHolder << endl;
						}
						else {
							cout << endl << "ERROR " << chrTNumChHolder << "IS NOT A LETTER!" << endl;
						}
					}
					while (strTNumHolder.length() > 10) {
						cout << "TOO MANY CHARACTERS ENTERED REMOVING: " << strTNumHolder.at(strTNumHolder.size()-1) << endl;
						strTNumHolder.erase(strTNumHolder.size() - 1);
					}	
					intChrPos++;
				}
				//format is easy because it'll always be of length 10 meaning you always have an area code 
				strFormattedTNum = "(" + strTNumHolder.substr(0,3) + ")" + strTNumHolder.substr(3,3) + "-" + strTNumHolder.substr(6, 4);
				cout << endl <<"TELEPHONE NUMBER CREATED: " << strFormattedTNum << endl;
				cout << endl << "Would you like to repeat converting Telphone numbers into Charachters? (y for YES n for NO): " << endl;
				cin >> chrRepeatOpt;
				chrRepeatOpt = towlower(chrRepeatOpt);
			} while (chrRepeatOpt == 'y');
			choice = false;
			break;

		case 3:
			// EXIT PROGRAM
			choice = true;
			break;

		default:
			// USER INPUT MISTAKE
			cout << "INVALID OPTION ENTERED!" << endl;
			choice = false;
		}
	} while (!choice);
	
	return 0;
}