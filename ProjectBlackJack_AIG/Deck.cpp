#include "pch.h"
#include "Deck.h"

Deck::Deck()
{
	init(1);
	setShufflePercent(75);
}

Deck::Deck(int intpNumberOfDecks)
{
	init(intpNumberOfDecks);
	setShufflePercent(75);
}

Deck::Deck(int intpNumberOfDecks, int intpShufflePoint)
{
	init(intpNumberOfDecks);
	setShufflePercent(intpShufflePoint);
}


Deck::~Deck()
{
	intShufflePoint = 0;
	intCurrentCardIndex = 0;
	vtrDeck.clear();
}


void Deck::init(int intpNumberOfDecks)
{
	vtrDeck.clear();
	intCurrentCardIndex = 0;
	for (int intDeckCount = 1; intDeckCount <= intpNumberOfDecks; intDeckCount++) {
		for (int intCard = 1; intCard <= 52; intCard++) {
			vtrDeck.push_back(Card(intCard));
		}
	}
}


Card Deck::getCard()
{
	Card objCard = vtrDeck.at(intCurrentCardIndex);
	intCurrentCardIndex++;
	if (intCurrentCardIndex >= size()) {
		intCurrentCardIndex = size() - 1;
	}
	return objCard;
}


void Deck::shuffle()
{
	intCurrentCardIndex = 0;
	std::random_shuffle(this->vtrDeck.begin(), this->vtrDeck.end());
}


int Deck::size()
{
	return (int)vtrDeck.size();
}


int Deck::getShufflePercent()
{
	return intShufflePoint;
}


int Deck::getPercentOfDeckDealt()
{
	return (this->intCurrentCardIndex * 100) / (int)this->vtrDeck.size();
}


bool Deck::shouldShuffle()
{
	if (getPercentOfDeckDealt() >= getShufflePercent()) {
		return true;
	}
	return false;
}


void Deck::setShufflePercent(int intpShufflePercent)
{
	if (intpShufflePercent > 100) {
		intpShufflePercent = 100;
	}
	else if (intpShufflePercent < 1) {
		intpShufflePercent = 5;
	}
	intShufflePoint = intpShufflePercent;
}