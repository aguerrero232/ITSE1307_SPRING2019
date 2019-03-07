
#include "pch.h"

#include <iostream>
#include <cmath>

using namespace std;



	// things we are given by the user 
	

	double getcalcSideH(double, double);
	double getcalcArea(double,double);
	double getcalcPerimeter(double,double,double);

	int main() {


		double dblSideA = 0.0;
		double dblSideB = 0.0;

		double sideH = 0.0;
		double Area = 0.0;
		double Perimeter = 0.0;
		// prompt the user for the data and be clear about what we want 
		cout << "To find the value of all the sides of a triangle, its Area, and its Perimiter you must first input side A and side B (the non-hypotnuse sides!): " << endl;

		// take in the users input 
		cout << "SIDE A: ";             // you should also check to see if it the correct input if this is for a 
		cin >> dblSideA;				// test or project .... i.e: dont let the user input chars,strings, negative numbers etc... 
										// but I will because im lazy
		cout << "SIDE B: ";
		cin >> dblSideB;

		// calculate side H value
		sideH = getcalcSideH(dblSideA, dblSideB);

		// calculate perimeter now that we have H
		Perimeter = getcalcPerimeter(dblSideA, dblSideB, sideH);

		// calculate Area 
		Area = getcalcArea(dblSideA, dblSideB);

		cout << "Length of the side A: " << dblSideA << endl;
		cout << "Length of the side B: " << dblSideB << endl;
		cout << "Length of the side H: " << sideH << endl;
		cout << "PERIMETER: " << Perimeter << endl;
		cout << "AREA: " << Area << endl;


	}


	double getcalcSideH(double sidea, double sideb) {
		return sqrt((sidea*sidea) + (sideb*sideb));
	}

	double getcalcArea(double sidea, double sideb) {
		return (.5)*(sidea)*(sideb);
	}
	double getcalcPerimeter(double sidea, double sideb, double sideh) {
		return (sidea + sideb + sideh);
	}
	