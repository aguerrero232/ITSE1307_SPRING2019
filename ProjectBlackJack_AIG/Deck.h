#pragma once
#include <vector>
#include <algorithm>
#include "Card.h"

class Deck
{
public:
	Deck();
	Deck(int intpNumberOfDecks);
	Deck(int intpNumberOfDecks, int intpShufflePoint);
	~Deck();
private:
	std::vector<Card> vtrDeck;
	int intShufflePoint = 0;
	int intCurrentCardIndex = 0;
	void init(int intpNumberOfDecks);
public:
	Card getCard();
	void shuffle();
	int size();
	int getShufflePercent();
	int getPercentOfDeckDealt();
	bool shouldShuffle();
	void setShufflePercent(int intpShufflePercent);
};