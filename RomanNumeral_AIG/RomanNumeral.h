#pragma once
#include <string>
#include <vector>

class RomanNumeral
{
public:
	RomanNumeral();
	RomanNumeral(double);

	~RomanNumeral();
private:
	double dblUserValue;
	std::string strRomanString;
public:
	bool isValid(double dblUsrVal);
	double convertToDecimal();
	std::string convertToRoman();
	std::string ToString();
	double getValue();
	std::string getString();
	void setValue(double pusrval);
	void setString(std::string pusrrmnnum);


};
