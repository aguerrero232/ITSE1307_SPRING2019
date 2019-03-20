// crmhighlow.cpp : Defines the entry point for the console application.
// Main Programmer: Chris MacDougald 
// Additions: Ariel Guerrero 3/20/2019
// ITSE 1307
// Simple High Low Guessing Game

/*
	Pick a random number.
	Have the user guess the number.
	Display output based on users guess.
	Repeat asking for users guess until it is equal to random number.
	Display winning if user guessed random number.
*/

#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL)); //Get random time

	int intLimit = 100; //Set limit for guess

	int intGuess = rand() % intLimit + 1; //Give me a number between 0 and 51 then add 1.

	int intGuessCounter = 0;
	int intMaxGuess = 7;

	int intCheatFactor = intLimit / 10;
	int intCheatHint = 0;
	int intCheatOption = 0; // variable to store if the user decides to cheat or not 

	int intCurrentGuess = 1;
	do { //Not equal to guess


		while (intCheatOption < 1 || intCheatOption>2) { //lets the user "cheat" by peeking at the first number in the number they are trying to guess

			cout << "Would you like to peek at the first number within the whole the random number? (1 for yes,2 for no): " << endl;
			cin >> intCheatOption;
		}

		if (intCheatOption == 1) {

			intCheatHint = intGuess / intCheatFactor;
			cout << "CHEATER! The number starts with " << intCheatHint << endl;
			intCheatOption = 2; // only want this loop to go once 
		}

		do { //User Input
			cout << "Please enter a number between 1 and " << intLimit << ": ";
			cin >> intCurrentGuess;
		} while (intCurrentGuess < 1 || intCurrentGuess > intLimit);


		if (intCurrentGuess > intGuess) {
			cout << "You guessed to high!" << endl;
			intGuessCounter++;
			cout << "You have only" << intMaxGuess - intGuessCounter << " guesses left!!!" << endl;
		}
		else if (intCurrentGuess < intGuess) {
			cout << "You guessed to low!" << endl;
			intGuessCounter++;
			cout << "You have only" << intMaxGuess - intGuessCounter << " guesses left!!!" << endl;
		}
		else {
			cout << "You guessed wisely! Congrats YOU WIN NOTHING!" << endl;
		}

	} while ((intCurrentGuess != intGuess) && (intGuessCounter < intMaxGuess));

	return 0;
}