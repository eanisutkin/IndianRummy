#ifndef AI_H
#define AI_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Player.h"

using namespace std;

enum State
{
	tooManyJockers,
	noMeld,
	pureSec,
	secPureSeq,
	impureSec,
	thidSeq,
	someSets,
	win
};

// Sub-class of Player class
class AI : public Player
{
private:
	State GameState;
public:
	// Init-constructor calls base class
	AI(string name, int score) : Player(name, score)
	{
		this->Name = name;
		this->Score = score;
	}
	void SetState(State a);
	State GetState();
	void SelectCard(Deck& deck, Deck& discard);
	// AI orders cards based on existing rules
	void MeldCards(Deck& deck);
	void DiscardCard();

	void AI::MakeTurn(Deck& deck, Deck& discard);

};

#endif