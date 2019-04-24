#include "pch.h"
#include "RomanNumeral.h"
#include <string>
#include <vector>

RomanNumeral::RomanNumeral()
{
	std::string strRomanString = "";
	double dblUserValue = 0.0;
}

RomanNumeral::~RomanNumeral()
{	this->dblUserValue = 0.0;
	this->strRomanString = "";
}

bool RomanNumeral::isValid(double dblUsrVal)
{
	// TODO: Add your implementation code here.
	if (dblUsrVal > 0) {
		return true;
	}
	return false;
}

double RomanNumeral::setValue(double pusrValue)
{
	// TODO: Add your implementation code here.
	dblUserValue = pusrValue;
	return this->dblUserValue;
}
std::string RomanNumeral::setString(std::string pstrromannum)
{
	// TODO: Add your implementation code here.
	strRomanString = pstrromannum;
	return this->strRomanString;
}

double RomanNumeral::getValue()
{
	// TODO: Add your implementation code here.
	return dblUserValue;
}


std::string RomanNumeral::getString()
{
	// TODO: Add your implementation code here.
	return this->strRomanString;
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
		if (intcurrentval>intpreviousval) {
			dblRomanDecVal += (intcurrentval)-(2 * intpreviousval);
		}
		else {
			dblRomanDecVal += intcurrentval;
		}
		intpreviousval = intcurrentval;
	}
	return dblRomanDecVal;
}

std::string RomanNumeral::convertToRoman()
{
	// TODO: Add your implementation code here.	
	double dblValueHolder = getValue();
	double dblDigitIndexHolder = 0;
	//double dblPlaceValue = 0.0;
	std::string strRomanNum = "";
	std::vector<double> decimals = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 }; //base values
	std::vector<std::string> symbol = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };  //roman symbols

	if (!isValid(dblValueHolder)){
		dblValueHolder = 1;
	}
	
	while (dblValueHolder) { //repeat process until num is not 0
			//dblPlaceValue = dblValueHolder / decimals[dblDigitIndexHolder];
		while ((dblValueHolder) / (decimals[dblDigitIndexHolder])>1) {  //first base value that divides num is largest base value
				strRomanNum += symbol[dblDigitIndexHolder];
				dblValueHolder -= decimals[dblDigitIndexHolder];  //subtract largest base value from num
		}
		dblDigitIndexHolder++;    //move to next base value to divide num
	}

	return strRomanNum;
}

std::string RomanNumeral::ToString()
{
	std::string strUsrStrHolder = getString();
	std::string toString = "";
	double dblUsrValHolder = getValue();
	toString += "Value: ";
	toString += dblUsrValHolder;
	toString += " ";
	toString += "Numerals: ";
	toString += strUsrStrHolder;
 	return toString;
}
