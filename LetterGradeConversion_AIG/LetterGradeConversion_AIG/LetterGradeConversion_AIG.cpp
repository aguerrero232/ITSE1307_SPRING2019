// Ariel Guerrero
// 3/5/2019
//
// Outputs the letter Grade equivalent to the user inputted numerical grade
// 

#include "pch.h"
#include <iostream>

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

	//  variable used to get the case for the switch statement 
	int intSwitchGradeCase = 0;


	// prompt the user fortheir grade value 
	cout << "Input your number Grade: ";
	cin >> dblGrade;

/*
		IN CLASS WORK USING IF LOGIC
	if (dblGrade > 89) {
		cout << "You have an A!" << endl;
	}
	if (dblGrade < 90 && intGrade > 79) {
		cout << "You have an B!" << endl;
	}
	if (dblGrade < 80 && intGrade > 69) {
		cout << "You have an C!" << endl;
	}
	if (dblGrade <= 70 && intGrade > 59) {
		cout << "You have an D!" << endl;
	}
	if (dblGrade < 60) {
		cout << "You have an F!" << endl;
	}
*/
	// calculates the switch case and stores it as an int 
	intSwitchGradeCase = dblGrade / 10;

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
