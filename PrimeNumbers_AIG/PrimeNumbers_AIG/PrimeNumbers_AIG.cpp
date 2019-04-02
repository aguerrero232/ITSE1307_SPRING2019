
#include "pch.h"
#include <iostream>
using namespace std;

// passes in a number and logically finds if it is divisible by another number to check if it is prime!
bool IsPrime(int intNum) {
	// pretty much did this in class 
	
	int intPrimeDivisionCount = 0;
	if (intNum ==0) {
		// 0 is always not prime
		return false;
	}
	else{
		// 1 is always prime so start at 2
		for (unsigned int intCount = 2; intCount < intNum; intCount++) {
			
			// if the remainder is = to 0 then the number is divisible by a number 
			// which also makes it a multiple so that means its not a prime number 
			if (intNum % intCount == 0) {
				intPrimeDivisionCount++;
			}
		}
	
	}
	if (intPrimeDivisionCount > 0) {
		return false;
	}
	return true;
}
// main portion of the code that bootstraps it all together and gets it running 
int main(){
	for (int intNum = 0; intNum < 10000; intNum++) {
		if (IsPrime(intNum)) {
			cout << intNum << " is Prime!" << endl;
		}
	 }
}

