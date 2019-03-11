// Ariel Guerrero
// 3/5/2019
//
// Outputs the letter Grade equivalent to the user inputted numerical grade
// UPDATED 3/11/2019 checks to round the students grade 
// 

#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

/*
	Name: Main
	Parameters:
	Description: takes a number value and calculated your letter grade given a value between 0-100
*/
int main()
{

	// varible used to hold the users grade
	double dblGrade = 0.0;
	double dblRoundCheck = 0.0;

	//  variable used to get the case for the switch statement 
	int intSwitchGradeCase = 0;
	int intGradeHolder = 0;

	// prompt the user fortheir grade value 
	cout << "Input your number Grade: ";
	cin >> dblGrade;

	// calculates the switch case and stores it as an int 
	intGradeHolder = dblGrade;
	intSwitchGradeCase = dblGrade / 10;
	dblRoundCheck = intGradeHolder % 10;

	//cout << fixed << setprecision(2) << "CHECK intGrade%10: " << dblRoundCheck << endl;
	//cout << fixed << setprecision(2) << "CHECK int: " << intSwitchGradeCase << endl;
	//cout << fixed << setprecision(2) << "CHECK math: " << intSwitchGradeCase << endl;

	if (dblRoundCheck >= 9) {
		intSwitchGradeCase++;
		cout << fixed << setprecision(2) << "LUCKY YOU!!!" << endl;
	}

	// switch statement to print the users certain letter grade
	switch (intSwitchGradeCase) {

	case 10:
		cout << "You have an A!" << endl;
		break;
	case 9:
		cout << "You have an A!" << endl;
		break;
	case 8:
		cout << "You have an B!" << endl;
		break;
	case 7:
		cout << "You have an C!" << endl;
		break;
	case 6:
		cout << "You have an D!" << endl;
		break;
	default:
		cout << "YOU GOT AN F!" << endl;
	}
}