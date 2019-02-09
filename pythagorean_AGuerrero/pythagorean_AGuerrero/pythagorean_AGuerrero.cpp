/ Ariel guerrero
// pythagorean_AGuerrero.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;

	double c = 0;

	cout << "Enter side A and side B to get side C of the triangle using the Pythagorean Theorm." << endl;

	cout << "Side A: ";
	cin >> a;

	cout << "Side B: ";
	cin >> b;

	c = sqrt((a*a) + (b*b));
	cout << "Side C: " << c << endl;
	cout << "Equation: " << a << "^2 + " << b << "^2 = " << c << "^2" << endl;

}