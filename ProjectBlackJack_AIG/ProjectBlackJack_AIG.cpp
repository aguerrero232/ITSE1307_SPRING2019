//Ariel Guerrero
// 99% of work done by Professor MacDougald
// Black Jack 2player game + dealer
// ProjectBlackJack_AIG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// how can I make the process of determining the winner more streamlined?
//

#include "pch.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <windows.h>   //For Beep & Sleep functions
#include<stdlib.h>  //For System Pause
#pragma comment(lib, "Winmm.lib")


using namespace std;

// pretty much just sets the number of decks they use 4 being easy and 1 being extreme
int gameDifficulty() {

	int difficulty = 0;
	char chrUsrOpt = ' ';
	  
	cout << '\a' << endl;
	cout << "PLEASE SELECT YOUR DIFFICULTY" << endl;
	cout << "=============================" << endl;
	cout << "           (E)asy     " << endl;
	cout << "           (M)edium   " << endl;
	cout << "           (H)ard     " << endl;
	cout << "          E(X)treme   " << endl << endl;
	cin >> chrUsrOpt;
	chrUsrOpt = tolower(chrUsrOpt);

	switch (chrUsrOpt) {
	case'e':
		difficulty = 4;
		break;
	case'm':

		difficulty = 3;
		break;
	case'h':

		difficulty = 2;
		break;
	case'x':

		difficulty = 1;
		break;
	default:
		cout << "ENTER A VALID OPTION!" << endl;
		difficulty = gameDifficulty();
	}
	return difficulty;
}

void printMenuOptions() {
	cout << '\a' << endl;
	cout << "              OPTIONS       " << endl;
	cout << "====================================" << endl;
	cout << "       Place a (B)et" << endl;
	cout << "               (N)ew Game" << endl;
	cout << "               (S)elect Difficulty" << endl;
	cout << "               (Q)uit" << endl << endl;
}

bool diffchangeWarning() {
	char usrOption = ' ';

	cout << "Resseting the Difficulty will resart your game is that OK?(Y/N): ";
	cin >> usrOption;
	usrOption = tolower(usrOption);

	if (usrOption == 'y') {
		return true;
	}
	return false;
}

void playIntroSong() {

	Beep(330, 100); Sleep(100);
	Beep(330, 100); Sleep(300);
	Beep(330, 100); Sleep(300);
	Beep(262, 100); Sleep(100);
	Beep(330, 100); Sleep(300);
	Beep(392, 100); Sleep(700);
	Beep(196, 100); Sleep(700);

}

void playIntroSong2() {
	Beep(300, 500);
	Sleep(50);
	Beep(300, 500);
	Sleep(50);
	Beep(300, 500);
	Sleep(50);

	Beep(250, 500);
	Sleep(50);

	Beep(350, 250);
	Beep(300, 500);
	Sleep(50);

	Beep(250, 500);
	Sleep(50);

	Beep(350, 250);
	Beep(300, 500);
	Sleep(50);
}


void playMetallica() {
	Beep(329, 300); //E
	Beep(493, 300); //B
	Beep(698, 300); //F^
	Beep(659, 600); //E^

	Beep(783, 300); //G^
	Beep(698, 300); //F^
	Beep(659, 600); //E^

	Beep(329, 100);
	Beep(493, 300);
	Beep(698, 300);
	Beep(659, 600);

	Beep(392, 250);
	Beep(440, 200);
	Beep(587, 300);

	Beep(349, 250);
	Beep(587, 500);

	Beep(329, 300);
	Beep(493, 300);
	Beep(698, 300);
	Beep(659, 600);
/*
	Beep(783, 300);
	Beep(698, 300);
	Beep(659, 600);

	Beep(329, 100);
	Beep(493, 300);
	Beep(698, 300);
	Beep(659, 600);

	Beep(392, 250);
	Beep(440, 200);
	Beep(587, 300);

	Beep(349, 250);
	Beep(587, 400);
*/
}
bool hitMe(int handValue,int money,string playersName) {

	if (handValue > 21) {
		cout << endl <<"Sorry " <<playersName <<" you busted! Better luck next time!" << endl;
		return false;
	}
	if (handValue == 21) {
		cout << endl << "CONGRATS " << playersName << " THATS 21!" << endl;
		return false;
	}

	cout << endl;
	char usrOption = ' ';
	cout << playersName << "'s"<<" Current Hand Value: " << handValue << endl;
	cout << "Would "<< playersName << " like to draw another card?(Y/N)" << endl;
	cin >> usrOption;
	usrOption = tolower(usrOption);
	cout << endl << endl;

	if (usrOption == 'y') {
		return true;
	}
	return false;
}

double dealerBetPercentage(int difficulty) {
	switch(difficulty){
	case 1:
		return .20;
		break;
	case 2:
		return .30;
		break;
	case 3:
		return .50;
		break;
	case 4:
		return .75;
		break;
	default:
		return .75;
	}
}

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
	//-------------------------------------------------------------------
	vector<Player*> objPlayers;
	Deck objDeck;
	srand((int)time(NULL));
	
	string strPlayersName = "";
	char chrMenuChoice = ' ';

	int intGameDiffMultiplier = 4;
	int intRoundCounter = 1;
	int intDealerBustMarker = 0;
	int intPlayer1BustMarker = 0;
	int intPlayer2BustMarker = 0;
	int intPlayer1VSPlayer2Marker = 0;
	int NumOfPlayers = 0;
	
	double dblDealerBetPcntg = .75;
	cout << "Welcome to Black Jack" << endl;
	cout << "=====================" << endl;
				//playIntroSong2();
	playMetallica();

	//-----------------------------------------------------------------
	// creates the initial 2 players and 1 dealer
	objPlayers.push_back(new Player());
	objPlayers.at(0)->setPlayerName("Dealer");
	for (int nameIndex = 1; nameIndex < 3; nameIndex++) {
		cout << "INPUT YOUR NAME PLAYER " << nameIndex << ": ";
		objPlayers.emplace_back(new Player());
		cin >> strPlayersName;
		objPlayers.at(nameIndex)->setPlayerName(strPlayersName);
		cout << endl;
	}

	// sets the games diff depending on the number of decks and money to start with 
	intGameDiffMultiplier = gameDifficulty();
	objDeck = Deck(intGameDiffMultiplier);
	objDeck.shuffle();
	for (int i = 0; i < objPlayers.size(); i++) {
		objPlayers.at(i)->setMoney(1000 * intGameDiffMultiplier);
	}
	dblDealerBetPcntg = dealerBetPercentage(intGameDiffMultiplier);
 
	do {
	
		printMenuOptions();
		cin >> chrMenuChoice;
		chrMenuChoice = tolower(chrMenuChoice);

		switch (chrMenuChoice) {
		case 'b':
			
			// clears the players old hand
			for (int totalPlayerIndex = 0; totalPlayerIndex < objPlayers.size(); totalPlayerIndex++) {
				objPlayers.at(totalPlayerIndex)->clearHand();
			}

			break;
			// new gane
		case 'n':

			system("CLS");
			cout << "Welcome to Black Jack" << endl;
			cout << "=====================" << endl;
			playIntroSong();

			intRoundCounter = 1;
			objPlayers.clear();
		
			// creates a new player and dealer. players must re name themselves 
			objPlayers.push_back(new Player());
			objPlayers.at(0)->setPlayerName("Dealer");
			for (int nameIndex = 1; nameIndex < 3; nameIndex++) {
				cout << "INPUT YOUR NAME PLAYER " << nameIndex << ": ";
				objPlayers.emplace_back(new Player());
				cin >> strPlayersName;
				objPlayers.at(nameIndex)->setPlayerName(strPlayersName);
				cout << endl;
			}
			// new deck and diff
			intGameDiffMultiplier = gameDifficulty();
			objDeck = Deck(intGameDiffMultiplier);
			objDeck.shuffle();
			for (int i = 0; i < objPlayers.size(); i++) {
				objPlayers.at(i)->setMoney(1000 * intGameDiffMultiplier);
			}
			dblDealerBetPcntg = dealerBetPercentage(intGameDiffMultiplier);

			break;
			//sets the difficulty 
		case 's':
			intRoundCounter = 1;
			if (diffchangeWarning()) {
				// clears the players old hand
				for (int totalPlayerIndex = 0; totalPlayerIndex < objPlayers.size(); totalPlayerIndex++) {
					objPlayers.at(totalPlayerIndex)->clearHand();
				}
				// new deck and diff
				intGameDiffMultiplier = gameDifficulty();
				objDeck = Deck(intGameDiffMultiplier);
				objDeck.shuffle();
				for (int i = 0; i < objPlayers.size(); i++) {
					objPlayers.at(i)->setMoney(1000 * intGameDiffMultiplier);
				}
				dblDealerBetPcntg = dealerBetPercentage(intGameDiffMultiplier);

			}
			break;
		case 'q':
			cout << "GAME OVER EXITING GAME NOW" << endl;
			cout << "\a";
			break;
		default:
			break;
		}
		if (chrMenuChoice != 'q') {
			
			cout << "ROUND #" << intRoundCounter << " START!" << endl;
			
			//places the bets 			
			for (int playersIndex = 1; playersIndex < objPlayers.size(); playersIndex++) {
				strPlayersName = objPlayers.at(playersIndex)->getPlayerName();
				objPlayers.at(playersIndex)->inputPlayerBet();
				cout << endl;
			}

			//draws the players first two cards of their new hand from a new deck
			for (int totalplayersIndex = 0; totalplayersIndex < objPlayers.size(); totalplayersIndex++) {
				for (int intFirstTwoCards = 1; intFirstTwoCards <= 2; intFirstTwoCards++) {
					objPlayers.at(totalplayersIndex)->addCard(objDeck.getCard());
				}
			}
			
			// dealer always bets a % of the players bet multiplied by the difficulty  unless he doesnt have enough then he bets it all
			if (objPlayers.at(0)->getMoney() > dblDealerBetPcntg*(objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet())) {
				objPlayers.at(0)->setBet(dblDealerBetPcntg*(objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet()));
			}
			else {
				objPlayers.at(0)->setBet(objPlayers.at(0)->getMoney());
			}
			
			//Should add some logic to prevent adding more cards that needed
			while (objPlayers.at(0)->getHandPointValue() <= 16 && objPlayers.at(0)->getNumberCards() <= 5) {
				objPlayers.at(0)->addCard(objDeck.getCard());
			}
			// print before drawing new cards
			for (int numofPlayers = 0; numofPlayers < objPlayers.size(); numofPlayers++) {
				cout << objPlayers.at(numofPlayers)->toString() << endl;
			}	
			for (int playersIndex = 1; playersIndex < objPlayers.size(); playersIndex++) {
				while (hitMe(objPlayers.at(playersIndex)->getHandPointValue(),objPlayers.at(playersIndex)->getMoney(), objPlayers.at(playersIndex)->getPlayerName())) {
					objPlayers.at(playersIndex)->addCard(objDeck.getCard());
					cout << objPlayers.at(playersIndex)->toString() << endl;
				}
			}
			
			// print with finished values
			for (int numofPlayers = 0; numofPlayers < objPlayers.size(); numofPlayers++) {
				cout << objPlayers.at(numofPlayers)->toString() << endl;
			}
			if (objDeck.shouldShuffle()) {
				objDeck.shuffle();
			}
			cout << endl << endl;
			// marks the players and dealer if they busted
			if (objPlayers.at(0)->getHandPointValue() > 21) {
				intDealerBustMarker = 1;
			}
			if (objPlayers.at(1)->getHandPointValue() > 21) {
				intPlayer1BustMarker = 1;
			}
			if (objPlayers.at(2)->getHandPointValue() > 21) {
				intPlayer2BustMarker = 1;
			}
			// checks to see which player has a higher hand as long as they did not bust
			if (intPlayer1BustMarker == 0 && intPlayer2BustMarker == 0) {
				if (objPlayers.at(1)->getHandPointValue() > objPlayers.at(2)->getHandPointValue()) {
					intPlayer1VSPlayer2Marker = 1;
				}
				else if (objPlayers.at(1)->getHandPointValue() < objPlayers.at(2)->getHandPointValue()) {
					intPlayer1VSPlayer2Marker = 2;
				}
				else {
					intPlayer1VSPlayer2Marker = 3;
				}
			}
			if (intDealerBustMarker == 0 && intPlayer1BustMarker == 0 && intPlayer2BustMarker == 0) {
				// no one busted
				if (intPlayer1VSPlayer2Marker == 1)
				{	// player one has a bigger hand value than player 2
					if (objPlayers.at(0)->getHandPointValue() > objPlayers.at(1)->getHandPointValue())
					{
						// TODO: Add logic for game win conditions.
						cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));
					}
					else if ((objPlayers.at(0)->getHandPointValue() < objPlayers.at(1)->getHandPointValue()))
					{
						//player 1 wins
						if (objPlayers.at(1)->getHandPointValue() == 21){
							cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(1)->getBet()) << endl;
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (1.5*objPlayers.at(1)->getBet()));
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
						}
						else{
							cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << objPlayers.at(1)->getBet() << endl;
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (objPlayers.at(1)->getBet()));
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());

						}
					}
					else if ((objPlayers.at(0)->getHandPointValue() == objPlayers.at(1)->getHandPointValue())){
						cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));

					}
				}
				else if (intPlayer1VSPlayer2Marker == 2) {
					// player two has a bigger hand value than player 1
					if (objPlayers.at(0)->getHandPointValue() > objPlayers.at(2)->getHandPointValue()) {
						// TODO: Add logic for game win conditions.
						cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));
					}
					else if ((objPlayers.at(0)->getHandPointValue() < objPlayers.at(2)->getHandPointValue())) {
						//p2 win
						if (objPlayers.at(2)->getHandPointValue() == 21){
							cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(2)->getBet()) << endl;
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (1.5*objPlayers.at(2)->getBet()));
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());

						}
						else{
							cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << objPlayers.at(2)->getBet() << endl;
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (objPlayers.at(2)->getBet()));
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());

						}
					}
					else if ((objPlayers.at(0)->getHandPointValue() == objPlayers.at(2)->getHandPointValue())){
						cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));
					}
				}
				else {
					// player one and two tied
					if (objPlayers.at(0)->getHandPointValue() > objPlayers.at(1)->getHandPointValue()){
						// TODO: Add logic for game win conditions.
						cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));
					}
					else {
						cout << " THIS ROUND WAS A DRAW PLAYER WITH THE LEAST AMOUNT OF CARDS WINS " << endl;
						if (objPlayers.at(1)->getNumberCards() < objPlayers.at(2)->getNumberCards()) {
							//player 1 wins
							if (objPlayers.at(1)->getHandPointValue() == 21){
								cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(1)->getBet()) << endl;
								objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (1.5*objPlayers.at(1)->getBet()));
								objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
								objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());

							}
							else{
								cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << objPlayers.at(1)->getBet() << endl;
								objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (objPlayers.at(1)->getBet()));
								objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
								objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
							}
						}
						else {
							//p2 win
							if (objPlayers.at(2)->getHandPointValue() == 21){
								cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(2)->getBet()) << endl;
								objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (1.5*objPlayers.at(2)->getBet()));
								objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
								objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
							}
							else{
								cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << objPlayers.at(2)->getBet() << endl;
								objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (objPlayers.at(2)->getBet()));
								objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
								objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
							}
						}
					}
				}
			}
			else {
				// someone busted
					// everyone busted house wins i think
				if (intDealerBustMarker + intPlayer1BustMarker + intPlayer2BustMarker == 3) {
					cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
					objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
					objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
					objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));
					break;
				}
				// dealer and player 1 busted
				else if (intDealerBustMarker + intPlayer1BustMarker == 2) {
					//p2 win
					if (objPlayers.at(2)->getHandPointValue() == 21){
						cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(2)->getBet()) << endl;
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (1.5*objPlayers.at(2)->getBet()));
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
					}
					else{
						cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << objPlayers.at(2)->getBet() << endl;
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (objPlayers.at(2)->getBet()));
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
					}
				}
				// dealer and player 2 busted
				else if (intDealerBustMarker + intPlayer2BustMarker == 2) {
					//player 1 wins
					if (objPlayers.at(1)->getHandPointValue() == 21){
						cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(1)->getBet()) << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (1.5*objPlayers.at(1)->getBet()));
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
					}
					else{
						cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << objPlayers.at(1)->getBet() << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (objPlayers.at(1)->getBet()));
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
					}
				}
				// player one and two busted
				else if (intPlayer2BustMarker + intPlayer1BustMarker == 2) {
					cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
					objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
					objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
					objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));
				}
				//just dealer busted
				else if(intDealerBustMarker > 0) {
					if (intPlayer1VSPlayer2Marker == 1) {
						//p1 win
						if (objPlayers.at(1)->getHandPointValue() == 21){
							cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(1)->getBet()) << endl;
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (1.5*objPlayers.at(1)->getBet()));
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
						}
						else{
							cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << objPlayers.at(1)->getBet() << endl;
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (objPlayers.at(1)->getBet()));
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
						}
					}
					else if (intPlayer1VSPlayer2Marker == 2) {
						//p2 win
						if (objPlayers.at(2)->getHandPointValue() == 21){
							cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(2)->getBet()) << endl;
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (1.5*objPlayers.at(2)->getBet()));
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
						}
						else{
							cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << objPlayers.at(2)->getBet() << endl;
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (objPlayers.at(2)->getBet()));
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
						}
					}
					else {
						//tie
						cout << " THIS ROUND WAS A DRAW PLAYER WITH THE LEAST AMOUNT OF CARDS WINS " << endl;

						if (objPlayers.at(1)->getNumberCards() < objPlayers.at(2)->getNumberCards()) {
							//player 1 wins
							if (objPlayers.at(1)->getHandPointValue() == 21){
								cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(1)->getBet()) << endl;
								objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (1.5*objPlayers.at(1)->getBet()));
								objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
								objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
							}
							else{
								cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << objPlayers.at(1)->getBet() << endl;
								objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (objPlayers.at(1)->getBet()));
								objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
								objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
							}
						}
						else {
							//p2 win
							if (objPlayers.at(2)->getHandPointValue() == 21){
								cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(2)->getBet()) << endl;
								objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (1.5*objPlayers.at(2)->getBet()));
								objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
								objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
							}
							else{
								cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << objPlayers.at(2)->getBet() << endl;
								objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (objPlayers.at(2)->getBet()));
								objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
								objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
							}
						}
					}
				}
				//just player one busted
				else if (intPlayer1BustMarker > 0) {
					if (objPlayers.at(0)->getHandPointValue() > objPlayers.at(2)->getHandPointValue()) {
						cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));
					}
					else if (objPlayers.at(0)->getHandPointValue() < objPlayers.at(2)->getHandPointValue()) {
						//p2 win
						if (objPlayers.at(2)->getHandPointValue() == 21){
							cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(2)->getBet()) << endl;
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (1.5*objPlayers.at(2)->getBet()));
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
						}
						else{
							cout << objPlayers.at(2)->getPlayerName() << " WINS " << "$" << objPlayers.at(2)->getBet() << endl;
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() + (objPlayers.at(2)->getBet()));
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - (objPlayers.at(1)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
						}
					}
					else {
						cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));
					}
				}
				// just player two busted
				else if (intPlayer2BustMarker > 0) {
					if (objPlayers.at(0)->getHandPointValue() > objPlayers.at(1)->getHandPointValue()) {
						cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));
					}
					else if (objPlayers.at(0)->getHandPointValue() < objPlayers.at(1)->getHandPointValue()) {
						//p1 win
						if (objPlayers.at(1)->getHandPointValue() == 21){
							cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << ((1.5)*objPlayers.at(1)->getBet()) << endl;
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (1.5*objPlayers.at(1)->getBet()));
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
						}
						else{
							cout << objPlayers.at(1)->getPlayerName() << " WINS " << "$" << objPlayers.at(1)->getBet() << endl;
							objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() + (objPlayers.at(1)->getBet()));
							objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - (objPlayers.at(2)->getBet()));
							objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() - objPlayers.at(0)->getBet());
						}
					}
					else {
						cout << "HOUSE WINS " << "$" << objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet() << endl;
						objPlayers.at(1)->setMoney(objPlayers.at(1)->getMoney() - objPlayers.at(1)->getBet());
						objPlayers.at(2)->setMoney(objPlayers.at(2)->getMoney() - objPlayers.at(2)->getBet());
						objPlayers.at(0)->setMoney(objPlayers.at(0)->getMoney() + (objPlayers.at(0)->getBet()));
					}
				}
				
				NumOfPlayers = objPlayers.size() - 1;
				
				if (objPlayers.at(0)->getMoney() <= 0) {

					cout << endl << "DEALER IS OUT OF MONEY!" << endl;

					if(objPlayers.at(1)->getMoney() == objPlayers.at(2)->getMoney()){
							
						cout << endl << "==========================" << endl;
						cout <<"        ITS A TIE" << endl;
						playIntroSong();

					}
					else if(objPlayers.at(1)->getMoney()> objPlayers.at(2)->getMoney()) {

						cout << endl << "==========================" << endl; 
						cout << "     " << objPlayers.at(1)->getPlayerName() <<" WINS!!!!!" << endl;
						playIntroSong2();
					}
					else {
						cout << endl << "==========================" << endl;
						cout <<"     "<< objPlayers.at(2)->getPlayerName() << " WINS!!!!!" << endl;
						playIntroSong2();
					}
					cout << endl << "GAME OVER EXITING GAME NOW" << endl;
					cout << "\a";
					chrMenuChoice = 'q';
				}
				if (chrMenuChoice != 'q') {
					// dealer is at 0 players start at index 1
					for (int i = 1; i < objPlayers.size(); i++) {
						if (objPlayers.at(i)->getMoney() <= 0) {
							cout << endl << objPlayers.at(i)->getPlayerName() << " is out of money." << endl;
							NumOfPlayers--;
						}
						if (NumOfPlayers <= 0) {
							cout << endl << "==========================" << endl;
							cout << endl << "        HOUSE WINS" << endl;
							cout << endl << "GAME OVER EXITING GAME NOW" << endl;
							cout << "\a";
							chrMenuChoice = 'q';
							playIntroSong2();
						}
					}
				}
			}

			cout << "ROUND #" << intRoundCounter << " OVER!" << endl;
			// reset all the markers for the next round 
			intDealerBustMarker = 0;
			intPlayer1BustMarker = 0;
			intPlayer2BustMarker = 0;
			intPlayer1VSPlayer2Marker = 0;
			intRoundCounter++;
		}
	} while (chrMenuChoice != 'q');
	cout << "\a";
	return 0;
}