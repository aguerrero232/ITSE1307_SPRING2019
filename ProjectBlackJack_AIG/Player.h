#pragma once
#include <string>
#include <vector>
#include "Card.h"

class Player
{
public:
	Player();
	~Player();
private:
	int intPlayerNumber;
	int intMoney;
	int intBet;
	std::string strName;
	std::vector<Card> vtrPlayerHand;
	void setPlayerNumber();
public:
	std::string inputPlayerName();
	void setPlayerName(std::string strpName);
	int getHandPointValue();
	void printHand();
	std::string toString();
	std::string getHandString();
	std::string getPlayerName();
	bool addCard(Card objpCard);
	int getNumberCards();
	void clearHand();

	void setMoney(int intpMoney);
	int getMoney();
	void setBet(int intpBet);
	int getBet();
	int inputPlayerBet();

	void clearBet();
};