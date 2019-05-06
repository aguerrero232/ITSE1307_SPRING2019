#include "pch.h"
#include "Card.h"

Card::Card()
{
	setRandom();
}

Card::Card(int intpCard)
{
	init(intpCard);
}


Card::~Card()
{
	intCard = 0;
}


int Card::getValue()
{
	return intCard;
}

void Card::init(int intpCard)
{
	if (intpCard > 52) {
		std::cerr << "Card::init: Warning set to max of 52." << std::endl;
		intpCard = 52;
	}
	else if (intpCard < 1) {
		std::cerr << "Card::init: Warning set to min of 1." << std::endl;
		intpCard = 1;
	}
	intCard = intpCard;
}

void Card::setRandom()
{
	init(rand() % 52 + 1);
}

int Card::getFaceValue()
{
	return ((getValue() - 1) % 13) + 1;
}


int Card::getSuiteValue()
{
	return ((getValue() - 1) / 13) + 1;
}


std::string Card::getSuiteString()
{
	std::string strSuite = "";
	switch (getSuiteValue()) {
	case 1:
		strSuite = "Clubs";
		break;
	case 2:
		strSuite = "Diamonds";
		break;
	case 3:
		strSuite = "Hearts";
		break;
	case 4:
		strSuite = "Spades";
		break;
	default:
		std::cerr << "[Error: " << getValue() << ", " << getSuiteValue() << "]";
		strSuite = "ERROR";
	}
	return strSuite;
}


std::string Card::getFaceString()
{
	std::string strFace = "";
	switch (getFaceValue()) {
	case 1:
		strFace = "Ace";
		break;
	case 11:
		strFace = "Jack";
		break;
	case 12:
		strFace = "Queen";
		break;
	case 13:
		strFace = "King";
		break;
	default:
		strFace = std::to_string(getFaceValue());
	}
	return strFace;
}


std::string Card::toString()
{
	std::string strCard = getFaceString();
	strCard += " of ";
	strCard += getSuiteString();
	return strCard;
}