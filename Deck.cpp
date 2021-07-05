#include "Deck.h"

Deck::Deck(bool doubleDeck, size_t numOfJockers)
{
	if (doubleDeck)
	{
		for (size_t i = Rank::Two; i < (Rank::NumOfRanks - Rank::Two); i++)
		{
			for (size_t j = Suit::D; j < (Suit::NumOfSuits - Suit::D); j++)
			{
				Card* a = new Card(Rank(i), Suit(j));
				this->aDeck.push_back(*a);
			}
		}

		for (size_t i = Rank::Two; i < (Rank::NumOfRanks - Rank::Two); i++)
		{
			for (size_t j = Suit::D; j < (Suit::NumOfSuits - Suit::D); j++)
			{
				Card* a = new Card(Rank(i), Suit(j));
				this->aDeck.push_back(*a);
			}
		}
	}
	else
	{
		for (size_t i = Rank::Two; i < (Rank::NumOfRanks - Rank::Two); i++)
		{
			for (size_t j = Suit::D; j < (Suit::NumOfSuits - Suit::D); j++)
			{
				Card* a = new Card(Rank(i), Suit(j));
				this->aDeck.push_back(*a);
			}
		}
	}

	srand(unsigned(time(NULL)));
	this->WildJocker = this->aDeck[rand() % (this->aDeck.size())];

	if (numOfJockers > 4)
	{
		numOfJockers = 4;
	}

	for (size_t i = 0; i < numOfJockers; i++)
	{
		Card* a = new Card(Rank(0), Suit(0));
		this->aDeck.push_back(*a);
	}
}

Card Deck::GetWildJocker()
{
	return this->WildJocker;
}

void Deck::ShuffleDeck()
{
	srand(unsigned(time(NULL)));
	random_shuffle(aDeck.begin(), aDeck.end());
}

void Deck::SortDeck()
{
	sort(this->aDeck.begin(), this->aDeck.end(), [](const Card& a, const Card& b) { return a < b; });
}

size_t Deck::GetSize()
{
	return this->aDeck.size();
}

vector<Card> Deck::GetDeckCopy()
{
	return this->aDeck;
}

Card& Deck::GetCard(size_t place)
{
	return this->aDeck[place];
}

void Deck::PushFront(Card& card)
{
	this->aDeck.insert(this->aDeck.begin(), 0, card);
}

void Deck::PushBack(Card& card)
{
	this->aDeck.push_back(card);
}

Card& Deck::PopFront()
{
	assert(!(this->aDeck.empty()));
	Card& temp = this->aDeck[0];
	this->aDeck.erase(this->aDeck.begin());
	this->aDeck.shrink_to_fit();
	return temp;
}

Card& Deck::PopBack()
{
	Card& temp = this->aDeck[this->aDeck.size() - 1];
	aDeck.pop_back();
	return temp;
}

void Deck::RemoveFromDeck(size_t place)
{
	if (place > (this->GetSize() - 1))
	{
		cout << "Can't remove the card, index out of bounds. Last card will be removed" << endl;
		this->aDeck.pop_back();
	}
	else
	{
		this->aDeck.erase(aDeck.begin()+place);
	}

	this->aDeck.shrink_to_fit();
}

void Deck::RemoveCard(Card& card)
{
	for (size_t i; i < this->aDeck.size(); i++)
	{
		if (this->aDeck[i] == card)
		{
			this->aDeck.erase(this->aDeck.begin()+i);
			this->aDeck.shrink_to_fit();
		}
	}
}

void Deck::operator=(const Deck& b)
{
	this->aDeck = b.aDeck;
	this->WildJocker = b.WildJocker;
}