// Roman Numeral class
// This is what characteristics and properties I gave my roman numerals
#include "pch.h"
#include "RomanNumeral.h"
#include <string>
#include <vector>

// constructor
RomanNumeral::RomanNumeral()
{
	std::string strRomanString = "";
	double dblUserValue = 0.0;
}
// overloaded for no reason might be of use later
RomanNumeral::RomanNumeral(double dbluservalue)
{
	double dblUserValue = dbluservalue;
	std::string strRomanString = "";


}
// deconstructor
RomanNumeral::~RomanNumeral()
{
	dblUserValue = 0.0;
	strRomanString = "";
}
// checks to see if the parameters are valid 
// need to make a check for the string too but im already late
bool RomanNumeral::isValid(double dblUsrVal)
{
	// TODO: Add your implementation code here.
	if (dblUsrVal > 0) {
		return true;
	}
	return false;
}

void RomanNumeral::setValue(double pusrValue)
{
	// TODO: Add your implementation code here.
	this->dblUserValue = pusrValue;
}
void RomanNumeral::setString(std::string pstrromannum)
{
	// TODO: Add your implementation code here.
	this->strRomanString = pstrromannum;
}

double RomanNumeral::getValue()
{
	// TODO: Add your implementation code here.
   
	return dblUserValue;
}

std::string RomanNumeral::getString()
{

	// TODO: Add your implementation code here.
	
	return strRomanString;
}

double RomanNumeral::convertToDecimal()
{
	std::string strUsrStrHolder = getString();

	// TODO: Add your implementation code here.
	double dblRomanDecVal = 0.0;
	int intcurrentval = 0;
	int intpreviousval = 0;

	for (unsigned int characterIndex = 0; characterIndex < strUsrStrHolder.size(); characterIndex++) {

		switch (strUsrStrHolder.at(characterIndex)) {
			//cases for each value 
		case 'M':
			intcurrentval = 1000;
			break;
		case 'D':
			intcurrentval = 500;
			break;
		case 'C':
			intcurrentval = 100;
			break;
		case 'L':
			intcurrentval = 50;
			break;
		case 'X':
			intcurrentval = 10;
			break;
		case'V':
			intcurrentval = 5;
			break;
		case'I':
			intcurrentval = 1;
			break;
		}
		if (intcurrentval > intpreviousval) {
			dblRomanDecVal +=(intcurrentval)-(2 * intpreviousval);
		}
		else {
			dblRomanDecVal += intcurrentval;
		}
		intpreviousval = intcurrentval;
	}
	setValue(dblRomanDecVal);
	return dblRomanDecVal;
}

std::string RomanNumeral::convertToRoman()
{
	// TODO: Add your implementation code here.	
	double dblValueHolder = getValue();
	double dblDigitIndexHolder = 0;
	//double dblPlaceValue = 0.0;
	std::string strRomanNum = "";
	std::vector<double> vdbRomanValues = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 }; //base values
	std::vector<std::string> vstrRomanSymbols = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };  //roman symbols

	if (!isValid(dblValueHolder)) {
		dblValueHolder = 1;
	}

	while (dblValueHolder > 0 && dblDigitIndexHolder < 13) { //repeat process until num is not 0
			//dblPlaceValue = dblValueHolder / decimals[dblDigitIndexHolder];
		while ((dblValueHolder) / (vdbRomanValues[dblDigitIndexHolder]) > 1 != false) {  //first base value that divides num is largest base value
			strRomanNum += vstrRomanSymbols[dblDigitIndexHolder];
			dblValueHolder -= vdbRomanValues[dblDigitIndexHolder];  //subtract largest base value from num
		}
		dblDigitIndexHolder++;    //move to next base value to divide num
	}
	setString(strRomanNum);
	return strRomanNum;
}

std::string RomanNumeral::ToString()
{
	std::string strUsrStrHolder = getString();
	double dblUsrValHolder = getValue();

	std::string toString = "";

	toString += "Value: ";
	toString += dblUsrValHolder;
	toString += " ";
	toString += "Numerals: ";
	toString += strUsrStrHolder;
	return toString;
}

