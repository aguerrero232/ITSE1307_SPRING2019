#include "RomanNumeral.h"
#include "pch.h"
#include <string>
#include <vector>



RomanNumeral::RomanNumeral(int pusernum)
{
	intRomanValue = pusernum;

	intValtoRoman(intRomanValue);


}


RomanNumeral::~RomanNumeral()
{
}

// Converts users number and prints the Roman Numeral equivalent
std::string RomanNumeral::intValtoRoman(int intRomanValue)
{
	int intValueHolder = intRomanValue;
	int intDigitIndexHolder = 0;

	std::string strRomanNum = "";
	std::vector<int> decimals = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 }; //base values
	std::vector<std::string> symbol = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };  //roman symbols
	// TODO: Add your implementation code here.
	
	
	if (intValueHolder <= 0) {
		strRomanNum = "Invalid Number";
	}
	else {
		while (intValueHolder) { //repeat process until num is not 0
			while (intValueHolder / decimals[intDigitIndexHolder]) {  //first base value that divides num is largest base value
				strRomanNum += symbol[intDigitIndexHolder];
				intValueHolder -= decimals[intDigitIndexHolder];  //subtract largest base value from num
			}
			intDigitIndexHolder++;    //move to next base value to divide num
		}
	}
	return strRomanNum;

}

std::string RomanNumeral::toString()
{
	// TODO: Add your implementation code here.
	std::string toString = "";

	toString += ("Value: " + intRomanValue);

	toString += (" String: " + intRomanValue);

	return toString;
}
