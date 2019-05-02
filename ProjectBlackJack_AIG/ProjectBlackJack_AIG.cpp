//Ariel Guerrero
// 99% of work done by Professor MacDougald
// Black Jack 2player game + dealer
// ProjectBlackJack_AIG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;
/*
spliting pairs 
doubling down 
buying insurance
*/

/*
this is where we get all the different classes to interact with each other and make the game of blackjack go 
*/
int main()
{
	srand((int)time(NULL));

	Player objDealer;
	Player objPlayer1;
	Player objPlayer2;
	
	int intDealerBustMarker = 0;
	int intPlayer1BustMarker = 0;
	int intPlayer2BustMarker = 0;
	int intPlayer1VSPlayer2Marker = 0;

	Deck objDeck = Deck(4);

	objDealer.setPlayerName("Dealer");
	objPlayer1.setPlayerName("Player 1");
	objPlayer2.setPlayerName("Player 2");

	cout << objDealer.toString() << endl;
	cout << objPlayer1.toString() << endl;
	cout << objPlayer2.toString() << endl;
	
	cout << "INPUT YOUR BET PLAYER ONE!" << endl;
	objPlayer1.inputPlayerBet();
	cout << "INPUT YOUR BET PLAYER TWO!" << endl;
	objPlayer2.inputPlayerBet();
	
	objDeck.shuffle();

	for (int intFirstTwoCards = 1; intFirstTwoCards <= 2; intFirstTwoCards++) {
		objDealer.addCard(objDeck.getCard());
		objPlayer1.addCard(objDeck.getCard());
		objPlayer2.addCard(objDeck.getCard());
	}

	//Should add some logic to prevent adding more cards that needed
	while (objDealer.getHandPointValue() <= 16 && objDealer.getNumberCards() <=5) {
		objDealer.addCard(objDeck.getCard());
	}

	cout << objDealer.toString() << endl;
	cout << objPlayer1.toString() << endl;
	cout << objPlayer2.toString() << endl;



	if (objDeck.shouldShuffle()) {
		objDeck.shuffle();
	}

	cout << endl << endl;


	// marks the players and dealer if they busted
	if (objDealer.getHandPointValue() > 21) {

		intDealerBustMarker = 1;
	}
	if (objPlayer1.getHandPointValue()>21) {
		
		intPlayer1BustMarker = 1;
	}
	if (objPlayer2.getHandPointValue() > 21) {

		intPlayer2BustMarker = 1;
	}

	// checks to see which player has a higher hand as long as they did not bust 
	if (intPlayer1BustMarker == 0 && intPlayer2BustMarker == 0 ) {

		if (objPlayer1.getHandPointValue() > objPlayer2.getHandPointValue()) {
			intPlayer1VSPlayer2Marker = 1;
		}
		else if(objPlayer1.getHandPointValue() < objPlayer2.getHandPointValue()) {
			intPlayer1VSPlayer2Marker = 2;
		}
		else {
			intPlayer1VSPlayer2Marker = 3;
		}
	}

	if (intDealerBustMarker == 0 && intPlayer1BustMarker == 0 && intPlayer2BustMarker == 0){
		// no one busted

		if (intPlayer1VSPlayer2Marker == 1) 
		{
			// player one has a bigger hand value than player 2

			if (objDealer.getHandPointValue() > objPlayer1.getHandPointValue()) 
			{
				// TODO: Add logic for game win conditions.
				cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;
			}
			else if ((objDealer.getHandPointValue() < objPlayer1.getHandPointValue())) 
			{
				if (objPlayer1.getHandPointValue() == 21) 
				{
					cout << "PLAYER 1 WINS " << "$" << objPlayer1.getBet() + ((1.5)*objPlayer1.getBet()) << endl;
				}
				else 
				{
					cout << "PLAYER 1 WINS " << "$" << objPlayer1.getBet() + objPlayer1.getBet() << endl;
				}
			}
			else if ((objDealer.getHandPointValue() == objPlayer1.getHandPointValue())) 
			{
				cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;
			}

		}
		else if (intPlayer1VSPlayer2Marker == 2) {
			// player two has a bigger hand value than player 1

			if (objDealer.getHandPointValue() > objPlayer2.getHandPointValue()) {
				// TODO: Add logic for game win conditions.
				cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;
			}
			else if ((objDealer.getHandPointValue() < objPlayer2.getHandPointValue())) {
				if (objPlayer2.getHandPointValue() == 21) 
				{
					cout << "PLAYER 2 WINS " << "$" << objPlayer2.getBet() + ((1.5)*objPlayer2.getBet()) << endl;
				}
				else 
				{
					cout << "PLAYER 2 WINS " << "$" << objPlayer2.getBet() + objPlayer2.getBet() << endl;
				}
			}
			else if ((objDealer.getHandPointValue() == objPlayer2.getHandPointValue())) 
			{
				cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;
			}
		}
		else {
			// player one and two tied
			if (objDealer.getHandPointValue() > objPlayer1.getHandPointValue())
			{
				// TODO: Add logic for game win conditions.
				cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;
			}
			else {
				cout << " FILL IN  " << endl;

			}
		}
	}	
	else {
	// someone busted 
		
		// everyone busted house wins i think
		if (intDealerBustMarker+intPlayer1BustMarker+intPlayer2BustMarker ==3) {
			cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;
		}
		// dealer and player 1 busted
		else if (intDealerBustMarker + intPlayer1BustMarker == 2) {
			if (objPlayer2.getHandPointValue() == 21)
			{
				cout << "PLAYER 2 WINS " << "$" << objPlayer2.getBet() + ((1.5)*objPlayer2.getBet()) << endl;
			}
			else
			{
				cout << "PLAYER 2 WINS " << "$" << objPlayer2.getBet() + objPlayer2.getBet() << endl;
			}
		}
		// dealer and player 2 busted 
		else if (intDealerBustMarker + intPlayer2BustMarker == 2) {
			if (objPlayer1.getHandPointValue() == 21)
			{
				cout << "PLAYER 1 WINS " << "$" << objPlayer1.getBet() + ((1.5)*objPlayer1.getBet()) << endl;
			}
			else
			{
				cout << "PLAYER 1 WINS " << "$" << objPlayer1.getBet() + objPlayer1.getBet() << endl;
			}
		}
		// player one and two busted
		else if (intPlayer2BustMarker + intPlayer1BustMarker == 2) {

			cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;
		}
		//just dealer busted
		if (intDealerBustMarker > 0) {

			if (intPlayer1VSPlayer2Marker == 1) {
				//p1 win
				if (objPlayer1.getHandPointValue() == 21)
				{
					cout << "PLAYER 1 WINS " << "$" << objPlayer1.getBet() + ((1.5)*objPlayer1.getBet()) << endl;
				}
				else
				{
					cout << "PLAYER 1 WINS " << "$" << objPlayer1.getBet() + objPlayer1.getBet() << endl;
				}
			}
			else if (intPlayer1VSPlayer2Marker == 2) {
				//p2 win
				if (objPlayer2.getHandPointValue() == 21)
				{
					cout << "PLAYER 2 WINS " << "$" << objPlayer2.getBet() + ((1.5)*objPlayer2.getBet()) << endl;
				}
				else
				{
					cout << "PLAYER 2 WINS " << "$" << objPlayer2.getBet() + objPlayer2.getBet() << endl;
				}
			}
			else {
				//tie
				cout << "ITS A TIE" << endl;
			}

		}
		//just player one busted 
		else if (intPlayer1BustMarker > 0) {
			if (objDealer.getHandPointValue() > objPlayer2.getHandPointValue()) {
				cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;
			}
			else if (objDealer.getHandPointValue() < objPlayer2.getHandPointValue()) {
				//p2 win
				if (objPlayer2.getHandPointValue() == 21)
				{
					cout << "PLAYER 2 WINS " << "$" << objPlayer2.getBet() + ((1.5)*objPlayer2.getBet()) << endl;
				}
				else
				{
					cout << "PLAYER 2 WINS " << "$" << objPlayer2.getBet() + objPlayer2.getBet() << endl;
				}

			}
			else {
				cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;
			}
		}
		// just player two busted 
		else if (intPlayer2BustMarker > 0) {
			
			if (objDealer.getHandPointValue() > objPlayer1.getHandPointValue()) {
				cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;

			}
			else if (objDealer.getHandPointValue() < objPlayer1.getHandPointValue()) {
				//p1 win
				if (objPlayer1.getHandPointValue() == 21)
				{
					cout << "PLAYER 1 WINS " << "$" << objPlayer1.getBet() + ((1.5)*objPlayer1.getBet()) << endl;
				}
				else
				{
					cout << "PLAYER 1 WINS " << "$" << objPlayer1.getBet() + objPlayer1.getBet() << endl;
				}
			}
			else {
				cout << "HOUSE WINS " << "$" << objPlayer1.getBet() + objPlayer2.getBet() << endl;
			}
		}
	}

	return 0;
}