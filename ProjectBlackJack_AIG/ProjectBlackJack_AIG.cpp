//Ariel Guerrero
// 99% of work done by Professor MacDougald
// Black Jack 2player game + dealer
// ProjectBlackJack_AIG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// how can I make the process of determining the winner more streamlined?
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

void playIntroSong() {
	// mario 
	Beep(330, 100); Sleep(100);
	Beep(330, 100); Sleep(300);
	Beep(330, 100); Sleep(300);
	Beep(262, 100); Sleep(100);
	Beep(330, 100); Sleep(300);
	Beep(392, 100); Sleep(700);
	Beep(196, 100); Sleep(700);
}

void playIntroSong2() {
	// Imperial March
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
	// Metallica - Harvester of Sorrows
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
}

// pretty much just sets the number of decks they use 4 being easy and 1 being extreme
int gameDifficulty() {
	int difficulty = 0;
	char chrUsrOpt = ' ';
	Beep(783, 300); //G^
	cout << "=================================" << endl;
	cout << "$ PLEASE SELECT YOUR DIFFICULTY $" << endl;
	cout << "=================================" << endl;
	cout << "           (E)asy     " << endl;
	cout << "           (M)edium   " << endl;
	cout << "           (H)ard     " << endl;
	cout << "          E(X)treme   " << endl;
	cin >> chrUsrOpt;
	system("CLS");
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

// "welcome screen"
void printWelcome() {
	cout << "=================================" << endl;
	cout << "$$$$  Welcome to Black Jack  $$$$" << endl;
	cout << "=================================" << endl;
}

void printMenuOptions() {
	Beep(659, 600);
	cout << "=================================" << endl;
	cout << "$$$$         OPTIONS         $$$$" << endl;
	cout << "=================================" << endl;
	cout << "     Place a (B)et               " << endl;
	cout << "             (N)ew Game          " << endl;
	cout << "             (S)elect Difficulty " << endl;
	cout << "             (Q)uit              " << endl;
}

void printPlayerInfo(vector<Player*> players) {
	Beep(783, 300); //G^
	cout << "=========================================" << endl;
	cout << "--------------PLAYER INFO----------------" << endl;
	cout << "=========================================" << endl;
	for (int numofPlayers = 0; numofPlayers < players.size(); numofPlayers++) {
		cout << players.at(numofPlayers)->toString() << endl;
	}
	cout << "=========================================" << endl;
}

// creates the 2 players and 1 dealer
vector<Player*> createPlayers() {
	vector<Player*> players;
	string strPlayersName = "";
	string strDealersName = "Dealer";

	players.push_back(new Player());
	players.at(0)->setPlayerName(strDealersName);
	for (int nameIndex = 1; nameIndex < 3; nameIndex++) {
		cout << "INPUT YOUR NAME PLAYER " << nameIndex << ": ";
		players.emplace_back(new Player());
		cin >> strPlayersName;
		players.at(nameIndex)->setPlayerName(strPlayersName);
		cout << endl;
	}
	system("CLS");
	return players;
}

bool diffchangeWarning() {
	char usrOption = ' ';
	cout << endl << "================================================================="<<endl;
	cout << "Resetting the Difficulty will resart your game is that OK?(Y/N)" << endl;;
	cout << "=================================================================" << endl;
	Beep(783, 300); //G^
	cout << ">>";
	cin >> usrOption;
	usrOption = tolower(usrOption);
	system("CLS");
	if (usrOption == 'y') {
		return true;
	}
	return false;
}

bool hitMe(int handValue, int money, string playersName, int difficulty) {
	cout << endl;
	if (handValue > 21) {
		Beep(659, 600);
		cout << endl << "Sorry " << playersName << " you busted! Better luck next time!" << endl;
		return false;
	}
	if (handValue == 21) {
		cout << endl << "CONGRATS " << playersName << " THATS 21!" << endl;
		return false;
	}
	cout << endl;
	char usrOption = ' ';
	cout << "===================================================" << endl;
	cout << "   "<< playersName << "'s" << " Current Hand Value: " << handValue << endl;
	cout << "   " << "Would " << playersName << " like to draw another card?(Y/N)" << endl;
	cout << "===================================================" << endl;
	
	cout << ">>"; 
	cin >> usrOption;
	usrOption = tolower(usrOption);

	// helps the user just incase
	if (usrOption == 'y' && (difficulty>2) && handValue >= 17) {
		usrOption = ' ';
		cout << "Are you sure?(Y/N)" << endl;
		cout << ">>";
		cin >> usrOption;
		usrOption = tolower(usrOption);
		if (usrOption != 'y') {
			return hitMe(handValue, money, playersName, difficulty);
		}
		}
	cout << endl;
	if (usrOption == 'y') {
		return true;
	}
	return false;
}

// sets the amount the dealer will bet depending on the difficulty
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
// sets the money after the hands are evaluated
vector<Player*> whoWinsTheRound(vector<Player*> players) {
	cout << players.at(0)->getPlayerName() << " WINS " << "$" << players.at(0)->getBet() << endl;
	players.at(0)->setMoney(players.at(0)->getMoney() + players.at(0)->getBet());
	players.at(1)->setMoney(players.at(1)->getMoney() - players.at(1)->getBet());
	players.at(2)->setMoney(players.at(2)->getMoney() - players.at(2)->getBet()); 
	return players;
}

vector<Player*> sortPlayersHandPoint(vector<Player*> players) {
	vector<int> playersHandPointValue;
	int intHolder;
	Player* objPlayerHolder;
	// fills in the vector of the players hand order in order of dealer player 1 and player 2 
	for (int intnumberOfPlayers = 0; intnumberOfPlayers < players.size(); intnumberOfPlayers++) {
		playersHandPointValue.emplace_back(players.at(intnumberOfPlayers)->getHandPointValue());
	}
	// sort the int array starting at 1 for the if check inside and sorts greatest to least
	for (int intnumberOfPlayers = 1; intnumberOfPlayers < players.size(); intnumberOfPlayers++) {
		if (playersHandPointValue.at(intnumberOfPlayers) > playersHandPointValue.at(intnumberOfPlayers - 1)) {
			// store the value of the playes we are about to overwrite
			intHolder = playersHandPointValue.at(intnumberOfPlayers - 1);
			objPlayerHolder = players.at(intnumberOfPlayers - 1);
			// sort the hand point values
			playersHandPointValue.at(intnumberOfPlayers - 1) = playersHandPointValue.at(intnumberOfPlayers);
			playersHandPointValue.at(intnumberOfPlayers) = intHolder;
			// sort the players
			players.at(intnumberOfPlayers - 1) = players.at(intnumberOfPlayers);
			players.at(intnumberOfPlayers) = objPlayerHolder;
		}
	}
	//if greater than 21 then get placed in the back
	for (int intPlayerNumber = 0; intPlayerNumber < players.size(); intPlayerNumber++) {
		if (playersHandPointValue.at(intPlayerNumber) > 21) {
			intHolder = playersHandPointValue.at(intPlayerNumber);
			objPlayerHolder = players.at(intPlayerNumber);
			playersHandPointValue.erase(playersHandPointValue.begin() + intPlayerNumber);
			players.erase(players.begin() + intPlayerNumber);
			//puts the data at the end
			playersHandPointValue.push_back(intHolder);
			players.push_back(objPlayerHolder);
		}
	}
	// tie
	if (players.at(0)->getHandPointValue() == players.at(1)->getHandPointValue()) {
		//player tied with the dealer so house wins
		if (players.at(0)->getPlayerName() == ("Dealer") || players.at(1)->getPlayerName() == ("Dealer")) {
			if(players.at(0)->getPlayerName()==("Dealer")){
			// dealer is in the front
			}
			else{
				// dealer is in the midd an needs to get moved to the front
				objPlayerHolder = players.at(0);
				players.at(0) = players.at(1);
				players.at(1) = objPlayerHolder;
			}
		}
		// player tied with another player 
		else {
			cout << " THIS ROUND WAS A DRAW PLAYER WITH THE LEAST AMOUNT OF CARDS WINS " << endl;
			if (players.at(0)->getNumberCards() < players.at(1)->getNumberCards()) {
				// player with the least amount of cards is up fron so do nothing
			}
			else {
				//player with least cards needs to move up 
				objPlayerHolder = players.at(0);
				players.at(0) = players.at(1);
				players.at(1) = objPlayerHolder;
			}
		}
	}
	if (players.at(0)->getHandPointValue() > 21) {
		// if the lead has over 21 move to the back
		objPlayerHolder = players.at(0);
		players.at(0) = players.at(1);
		players.at(1) = objPlayerHolder;
	}
	// everyone is at 21 forcing the dealer to spot 0 cause house wins
	if (players.at(0)->getHandPointValue() > 21) {
		for (int i = 0; i < players.size(); i++) {
			if (players.at(i)->getPlayerName() == "Dealer") {
				objPlayerHolder = players.at(0);
				players.at(0) = players.at(i);
				players.at(i) = objPlayerHolder;
			}
		}
	}
	return players;
}

void whoWinsTheGame(vector<Player*> players, int intDealerOrPlayerWin) {
	Player* player;
	// players won
	if(intDealerOrPlayerWin == 0){
		// erases the dealer from the vector so should only have 2 things in the vector
		for (int playersIndex = 0; playersIndex < players.size(); playersIndex++){
			if (players.at(playersIndex)->getPlayerName() == ("Dealer")) {
				players.erase(players.begin() + playersIndex);
			}
		}	
		if (players.at(0)->getMoney() > players.at(1)->getMoney()){
			cout << "=================================" << endl;
			cout << "     " << players.at(0)->getPlayerName() << " WINS!!!!!" << endl;
			playIntroSong2();
		}
		else if(players.at(1)->getMoney() > players.at(0)->getMoney()){
			cout << "=================================" << endl;
			cout << "     " << players.at(1)->getPlayerName() << " WINS!!!!!" << endl;
			playIntroSong2();
		}
		// tie between the players 
		else {
		cout << "=================================" << endl;
		cout << "============== TIE ==============" << endl;
		cout << "=================================" << endl;
		cout << players.at(0)->getPlayerName() <<" & " << players.at(1)->getPlayerName() << " WIN!!!!!" << endl;
		playIntroSong();
		}
	}
	//dealer won
	else {
		cout << "=================================" << endl; 
		cout << "            HOUSE WINS           " << endl;
		cout << "    GAME OVER EXITING GAME NOW   " << endl;
		playIntroSong();
	}
}

bool gameOver(vector<Player*> players){
	int intPlayersOutOfMoney = players.size()-1;
	for (int playerNumber = 0; playerNumber < players.size(); playerNumber++){
		// if the dealer do all this 
		if (players.at(playerNumber)->getPlayerName() == ("Dealer")) {
			// if the dealers money is <=0 then they lose
			if (players.at(playerNumber)->getMoney() <= 0) {
				cout << "GAME OVER" << endl;
				whoWinsTheGame(players, 0);
				return true;
			}
		}
		// if players do this 
		else {
			if (players.at(playerNumber)->getMoney() <= 0) {
				intPlayersOutOfMoney--;
			}
		}
	}
	//players loose if this
	if(intPlayersOutOfMoney<=0){
		cout << "GAME OVER" << endl;
		whoWinsTheGame(players, 1);
		return true;
	}
	return false;
}

int getPlayersTotalBet(vector<Player*> players) {
	// pretty much just gets to multiply by the dealer bet percentage to get the amount the dealer should bet
	int totalPlayersBet = 0;
	for (int i = 0; i < players.size(); i++) {
		if (players.at(i)->getPlayerName() != ("Dealer")) {
			totalPlayersBet += players.at(i)->getBet();
		}
	}
	return totalPlayersBet;
}

/*
this is where we get all the different classes to interact with each other and make the game of blackjack go
*/
int main()
{
	vector<Player*> objPlayers;
	Deck objDeck;
	srand((int)time(NULL));
	char chrMenuChoice = ' ';
	int intGameDiffMultiplier = 4;
	int intRoundCounter = 1;
	double dblDealerBetPcntg = .75;
	// Tells the player what kind of game it is and plays music 
	printWelcome();
	playMetallica();
	objPlayers = createPlayers();
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

			// clears the players  last bet
			for (int totalPlayerIndex = 0; totalPlayerIndex < objPlayers.size(); totalPlayerIndex++) {
				objPlayers.at(totalPlayerIndex)->clearBet();
			}

			// clears the players old hand
			for (int totalPlayerIndex = 0; totalPlayerIndex < objPlayers.size(); totalPlayerIndex++) {
				objPlayers.at(totalPlayerIndex)->clearHand();
			}
			break;
		case 'n':
			// new gane
			system("CLS");
			printWelcome();
			playIntroSong();
			intRoundCounter = 1;
			objPlayers.clear();
			// creates a new player and dealer. players must re name themselves 
			objPlayers = createPlayers();
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
				
				// clears the players old bet 
				for (int totalPlayerIndex = 0; totalPlayerIndex < objPlayers.size(); totalPlayerIndex++) {
					objPlayers.at(totalPlayerIndex)->clearBet();
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
			system("CLS");
			cout << "ROUND #" << intRoundCounter << " START!" << endl;
			//places the bets 			
			for (int playersIndex = 0; playersIndex < objPlayers.size(); playersIndex++) {
				if (objPlayers.at(playersIndex)->getPlayerName() != ("Dealer")&& objPlayers.at(playersIndex)->getMoney()>0) {
					objPlayers.at(playersIndex)->inputPlayerBet();
					cout << endl;
				}
			}
			//draws the players first two cards of their new hand from a new deck
			for (int totalplayersIndex = 0; totalplayersIndex < objPlayers.size(); totalplayersIndex++) {
				for (int intFirstTwoCards = 1; intFirstTwoCards <= 2; intFirstTwoCards++) {
					objPlayers.at(totalplayersIndex)->addCard(objDeck.getCard());
				}
			}
			// sets the dealers bet
			for (int playersIndex = 0; playersIndex < objPlayers.size(); playersIndex++) {
				if (objPlayers.at(playersIndex)->getPlayerName() == ("Dealer")) {
					// dealer always bets a % of the players bet multiplied by the difficulty  unless he doesnt have enough then he bets it all
					if (objPlayers.at(playersIndex)->getMoney() > dblDealerBetPcntg*(objPlayers.at(1)->getBet() + objPlayers.at(2)->getBet())) {
						objPlayers.at(playersIndex)->setBet(dblDealerBetPcntg*getPlayersTotalBet(objPlayers));
					}
					else {
						objPlayers.at(playersIndex)->setBet(objPlayers.at(playersIndex)->getMoney());
					}
				}
			}
			//draws dealers cards as long as HPV <= 16 and cards in hand is <= 5
			for (int playersIndex = 0; playersIndex < objPlayers.size(); playersIndex++) {
				if (objPlayers.at(playersIndex)->getPlayerName() == ("Dealer")) {
					// Should add some logic to prevent adding more cards than needed
					while (objPlayers.at(playersIndex)->getHandPointValue() <= 16 && objPlayers.at(playersIndex)->getNumberCards() <= 5) {
						objPlayers.at(playersIndex)->addCard(objDeck.getCard());
					}
				}
			}		
			system("CLS");
			// print before drawing new cards
			printPlayerInfo(objPlayers);
			// where the players hit or stay 
			for (int playersIndex = 0; playersIndex < objPlayers.size(); playersIndex++) {
				if (objPlayers.at(playersIndex)->getPlayerName() != ("Dealer")) {
					while (hitMe(objPlayers.at(playersIndex)->getHandPointValue(), objPlayers.at(playersIndex)->getMoney(), objPlayers.at(playersIndex)->getPlayerName(), intGameDiffMultiplier)) {
						objPlayers.at(playersIndex)->addCard(objDeck.getCard());
						cout << objPlayers.at(playersIndex)->toString() << endl;
					}
				}
			}

			objPlayers = sortPlayersHandPoint(objPlayers);
			objPlayers = whoWinsTheRound(objPlayers);
			system("CLS");
			// print with finished values
			cout << endl << "//////////////////WINNER//////////////////" << endl;
			cout << "    PLAYER: " << objPlayers.at(0)->getPlayerName() << ", WINNINGS: $" << objPlayers.at(0)->getBet() << endl;
			cout << "///////////////////////////////////////////" << endl;
			printPlayerInfo(objPlayers);
			if (objDeck.shouldShuffle()) {
				objDeck.shuffle();
			}
			cout << endl;
		}
		cout << "ROUND #" << intRoundCounter << " OVER!" << endl;
		if (gameOver(objPlayers)) {
			chrMenuChoice = 'q';
		}
		intRoundCounter++;	
	} while (chrMenuChoice != 'q');
	cout << "\a";
	return 0;
}//fin
















//






















//




























































//




























































//












































































































































































//start