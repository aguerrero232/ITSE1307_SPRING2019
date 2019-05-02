#pragma once
#include <string>
#include <iostream>
#include <time.h>

class Card
{
public:
	Card();
	Card(int intpCard);
	~Card();
private:
	int intCard;
	int getValue();
public:
	void init(int intpCard);
	void setRandom();
	int getFaceValue();
	int getSuiteValue();
	std::string getSuiteString();
	std::string getFaceString();
	std::string toString();

};