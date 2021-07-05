#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <ctime>

#include "Card.h"

using namespace std;

class Deck
{

private:
	vector<Card> aDeck;
	Card& WildJocker;

public:
	Deck(bool doubleDeck, size_t numOfJockers);

	Card GetWildJocker();

	// Shuffles the deck
	void ShuffleDeck();
	void SortDeck();
	size_t GetSize();
	vector<Card> GetDeckCopy();
	
	Card& GetCard(size_t place);
	
	void PushFront(Card& card); 
	void PushBack(Card& card);
	Card& PopFront();
	Card& PopBack();
	
	void RemoveFromDeck(size_t place);
	void RemoveCard(Card& card);

	void operator =(const Deck& b);
};

#endif