// Ariel Guerrero
// isVowel
// 4/3/2019
// takes in a char from the user and tells them if its a vowel.. using a function to do it 

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*
name : isVowel 
parameters : chrUserChar - passes in as user input main data that we are testing
description : takes in a char and returns true if its a vowel else it will return false

*/
bool isVowel(char chrUserChar) {
	// vowels are a e i o u 
	char chrTestChar = tolower(chrUserChar);
	switch (chrUserChar) {
	case 'a':
		return true;
		break;
	case 'e':
		return true;
		break;
	case 'i':
		return true;
		break;
	case 'o':
		return true;
		break;
	case 'u':
		return true;
		break;
	default:
		return false;
	}
}

/*


*/
int main(){
	char chrUserChar = ' ';
	char chrUserRptOpt = 'y';

	do{
		cout << "Enter in a character to test if its a vowel" << endl;
		cin >> chrUserChar;
		cin.clear(); // makes sure to get rid of the extra just in case the user didnt give just one char
		if (isVowel(chrUserChar) == true) { // goes through function and returns true if a e i o and u
			cout << chrUserChar << " is a Vowel!" << endl << endl;
		}
		else { // else its not a vowel
			cout << chrUserChar << " is not a Vowel!" << endl<< endl;
		}
		cout << "Would you like to repeat? (y for yes n for no)" << endl; // repeat option for testing
		cin >> chrUserRptOpt;
		cin.clear(); // clear again because we only want one char
		cout << endl; 
	} while (chrUserRptOpt == 'y');
}


