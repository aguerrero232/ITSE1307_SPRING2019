// Ariel Guerrero
// 4/9/2019
// print tree - pretty much did the whole thing in class thanks to the help of Professor MacDougald

#include "pch.h"
#include <iostream>

using namespace std;

// takes in an int param from main given by the user and uses that to create a tree given an int height  
void printTree(int intpHeight) {
	//Tree Branches
	int intWidth = 1;
	for (int intRow = 1; intRow < intpHeight; intRow++) {
		for (int intSpaces = 1; intSpaces <= intpHeight - intRow; intSpaces++) {
			cout << " ";
		}
		for (int intColumn = 1; intColumn <= intWidth; intColumn++)
		{
			cout << "*";
		}
		intWidth += 2;
		cout << endl;
	}
	//Tree Trunk
	for (int intSpaces = 1; intSpaces < intpHeight; intSpaces++) {
		cout << " ";
	}
	cout << "*" << endl;
}

// bootstraps the program and gets the program going 
int main()
{

	int intTreeHeight = 0;

	do {
		cout << "Enter the height of the tree you wish to print as an integer value: ";
		cin >> intTreeHeight;

		printTree(intTreeHeight);

	} while (intTreeHeight != 0);

	return 0;
}