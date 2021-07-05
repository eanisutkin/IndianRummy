#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"

using namespace std;

class Player
{

protected:
	string Name;
	int Score;
	Deck Hand;
	Deck Meld;

public:
	// Init-constructor, gets the player name and 
	Player(string name, int score);

	// Returns the player's name
	string GetName();

	// Returns the player's Score
	int GetScore();

	// Meld cards at a specified places
	void MeldCards(vector<size_t> places);

	Deck& GetMeld();

	Card& DiscardCard(size_t place);

	void MakeTurn(Deck& deck, Deck& discard);

};

#endif