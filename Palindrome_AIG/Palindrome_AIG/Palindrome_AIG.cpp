// Ariel Guerrero
// 4/4/2019
// Palindrome
// checks a random string from the user and tells you if the word is a palindrome

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

// quick function to convert any uppercase letters in the users string to check if theyre the same character
// takes in the users string and length of the string as parameters
string toLowerString(string strUserInputString,int intUserStrLen) {
	string strLowerCaseUsrStr = "";
	for (int intCurrentChar = 0; intCurrentChar < intUserStrLen; intCurrentChar++) {
		strLowerCaseUsrStr += tolower(strUserInputString.at(intCurrentChar)); // at ever char make it lowercase then add that char to a new string to return back
	}
	return strLowerCaseUsrStr;
}

// meat of the logic is here takes in the users string passes it to tolowerstring to make sure all letters are equal and then 
// calculates to see if each set of characters are equal to each other    
// 
//				   1 2 3 3 2 1
//	1st pass ->    *         *      : compares these then we move +1 on the left for half the length and -1 on the right for the same duration
//  2nd pass ->      *     *
//  3rd pass ->        * *          : finishes here and returns true since they are equal at those positions 

bool isPalindrome(string strUserInputString) {
	int intUsrStrLen = strUserInputString.length();
	// makes everything lowercase
	strUserInputString = toLowerString(strUserInputString,intUsrStrLen);
	// logic part check visual above for the process
	for (int intLoopIndex = 0; intLoopIndex < (intUsrStrLen/2); intLoopIndex++) {
		if (strUserInputString.at(intLoopIndex) != strUserInputString.at(intUsrStrLen-1-intLoopIndex)) {
			return false;
		}
	}
	return true;
}


// bootstraps the code and gets it running, this is the source of the input that gets the program running 
int main()
{
	string strInputString = "";
	char charUserRepeatOption = 'y';
	do {
		cout << "Input a String to test if it is a Palindrome: ";
		cin >> strInputString;
		if (isPalindrome(strInputString)) {
			cout << endl << strInputString << " is a Palindrome!" << endl << endl;
		}
		else {
			cout << endl << strInputString << " is NOT a Palindrome " << endl << endl;
		}
		cout << " Would you like to repeat? (y for YES n for NO!) : " ;
		cin >> charUserRepeatOption; 
		charUserRepeatOption = tolower(charUserRepeatOption);
		cout << endl << endl;
	} while (charUserRepeatOption == 'y');
}
