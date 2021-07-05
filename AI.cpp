#include "AI.h"

void AI::SetState(State a)
{
	this->GameState = a;
}

State AI::GetState()
{
	return this->GameState;
}

void AI::SelectCard(Deck& deck, Deck& discard)
{
	Card& c = discard.GetCard(0); // top card from discard pile, visible

	for (size_t i = 0; i < this->Hand.GetSize() - 1; i++)
	{
		Card& a = this->Hand.GetCard(i);
		Card& b = this->Hand.GetCard(i + 1);

		if (a.GetSuit() == b.GetSuit() && b.GetSuit() == c.GetSuit())
		{
			// If taking open card forms an pure sequence, take it. One of the reqs for winning 
			if (a.GetRank() + 1 == b.GetRank() && b.GetRank() + 1 == c.GetRank())
			{
				this->Hand.PushBack(c);
			}
			else
			{
				continue;
			}
		}
		// If open card forms an impure sequence, also necessary for winninng.
		// sinse there no seqences at all, take the card, necessary for winning
		else if ((a.GetRank() == Jocker || a == deck.GetWildJocker()) && b.GetSuit() == c.GetSuit() && b.GetRank() == c.GetRank() + 1
			|| (b.GetRank() == Jocker || b == deck.GetWildJocker()) && a.GetSuit() == c.GetSuit() && a.GetRank() + 2 == c.GetRank()
			|| (c.GetRank() == Jocker || c == deck.GetWildJocker()) && a.GetSuit() == b.GetSuit() && a.GetRank() + 1 == b.GetRank()
			|| (a.GetRank() == Jocker || a == deck.GetWildJocker()) && (b.GetRank() == Jocker || b == deck.GetWildJocker())
			|| (b.GetRank() == Jocker || b == deck.GetWildJocker()) && (c.GetRank() == Jocker || c == deck.GetWildJocker())
			|| (a.GetRank() == Jocker || a == deck.GetWildJocker()) && (c.GetRank() == Jocker || c == deck.GetWildJocker())
			)
		{
			this->Hand.PushBack(c);
		}
		// If the card doesn't form existing any sequenses, AI should also check wheater a set can be formed
		// since all other cars must be sets, so AI should take it.
		else if( a.GetRank() == b.GetRank() && b.GetRank() == c.GetRank()
			|| ( (b.GetRank() == c.GetRank()) && (a.GetRank() == Jocker || a == deck.GetWildJocker()) )
			|| ( (a.GetRank() == c.GetRank()) && (b.GetRank() == Jocker || b == deck.GetWildJocker()) )
			|| ( (a.GetRank() == b.GetRank()) && (c.GetRank() == Jocker || c == deck.GetWildJocker()) )
			|| ( (a.GetRank() == Jocker || a == deck.GetWildJocker()) && (b.GetRank() == Jocker || b == deck.GetWildJocker()) )
			|| ( (b.GetRank() == Jocker || b == deck.GetWildJocker()) && (c.GetRank() == Jocker || c == deck.GetWildJocker()) )
			|| ( (a.GetRank() == Jocker || a == deck.GetWildJocker()) && (c.GetRank() == Jocker || c == deck.GetWildJocker()) )
			)
		{
			this->Hand.PushBack(c);
		}
		// If open card does'n do any of the following above, then there is no real point in taking it
		// Take from closed deck
		else
		{
			this->Hand.PushBack(deck.PopFront());
		}
	}
}

void AI::MeldCards(Deck& deck)
{
	vector<Card> jockers;
	size_t cardsInSeq = 0;
	switch (this->GameState)
	{
	// No pure seq yet.
	case noMeld:
		cardsInSeq = 0;
		for (size_t i = 0; i < this->Hand.GetSize() - 1; i++)
		{
			Card& a = this->Hand.GetCard(i);
			Card& b = this->Meld.GetCard(i + 1);

			// Strait out add all card in a pure seq till can
			if(a.GetSuit() == b.GetSuit() && a.GetRank() + 1 == b.GetRank())
			{
				this->Meld.PushBack(a);
				this->Meld.PushBack(b);
				continue;
			}
			else
			{
				break;
			}
		}

		// Remove all cards that were addesd to seq.
		for (size_t i = cardsInSeq; i < this->Meld.GetSize(); i++)
		{
			this->Hand.RemoveCard(this->Meld.GetCard(i));
		}

		// All cards grouperd, win
		if (this->Hand.GetSize() == 0)
		{
			this->GameState = win;
			return;
		}

		cardsInSeq = this->Meld.GetSize();
		// There might be a second pure seq.
		for (size_t i = 0; i < this->Hand.GetSize() - 1; i++)
		{
			Card& a = this->Hand.GetCard(i);
			Card& b = this->Meld.GetCard(i + 1);

			// Strait out add all card in a pure seq till can
			if (a.GetSuit() == b.GetSuit() && a.GetRank() + 1 == b.GetRank())
			{
				this->Meld.PushBack(a);
				this->Meld.PushBack(b);
				continue;
			}
			else
			{
				break;
			}
		}



		for (size_t i = 0; i < this->Hand.GetSize() - 1; i++)
		{
			Card& a = this->Hand.GetCard(i);
			Card& b = this->Meld.GetCard(i + 1);

			if ((a.GetSuit() == b.GetSuit() && b.GetSuit() == c.GetSuit() && a.GetRank() + 1 == b.GetRank() && b.GetRank() + 1 == c.GetRank()))
			{
				this->Meld.PushBack(a);
				this->Meld.PushBack(b);
				this->Meld.PushBack(c);
				i = i + 3;
				// Possibility of more cad in seq.
				cardsInSeq = this->Meld.GetSize();
				for (size_t i = cardsInSeq; i < this->Hand.GetSize(); i++)
				{
					Card& a = this->Hand.GetCard(i);
					Card& b = this->Meld.GetDeckCopy()[this->Meld.GetSize() - 1];

					//Another card was found to be added to sequense, at this point cards must form pure seq, check further
					if (a.GetRank() + 1 == b.GetRank() && a.GetSuit() == b.GetSuit())
					{
						this->Meld.PushBack(a);
						continue;
					}
					else
					{
						break;
					}
				}
				break;
			}
			else
			{
				continue;
			}
		}


	case pureSec:
		for (size_t i = 0; i < this->Hand.GetSize()-2; i++)
		{
			Card& a = this->Hand.GetCard(i);
			Card& b = this->Meld.GetCard(i+1);
			Card& c = this->Meld.GetCard(i+2);

			if ((a.GetSuit() == b.GetSuit() && b.GetSuit() == c.GetSuit() && a.GetRank() + 1 == b.GetRank() && b.GetRank() + 1 == c.GetRank()))
			{
				this->Meld.PushBack(a);
				this->Meld.PushBack(b);
				this->Meld.PushBack(c);

				this->GameState = secPureSeq; // We actually found a second pure sequense
				i = i + 3;
				break;
			}
			else if ((a.GetSuit() == b.GetSuit() && a.GetRank() + 2 == b.GetRank())
				|| (a.GetSuit() == c.GetSuit() && a.GetRank() + 2 == c.GetRank())
				|| (b.GetSuit() == c.GetSuit() && b.GetRank() + 2 == c.GetRank())
				)
			{
				this->Meld.PushBack(a);
				this->Meld.PushBack(b);
				this->Meld.PushBack(c);

				this->GameState = impureSec;
				i = i + 3;
				break;
			}
		}

		for (size_t i = cardsInSeq; i < this->Meld.GetSize(); i++)
		{
			this->Hand.RemoveCard(this->Meld.GetCard(i));
		}

		// Distinct possibility of more cards in seq
		cardsInSeq = this->Meld.GetSize();
		for (size_t i = 0; i < this->Hand.GetSize(); i++)
		{
			Card& a = this->Hand.GetCard(i);
			Card& b = this->Meld.GetDeckCopy()[this->Meld.GetSize() - 1];

			//Another card was found to be added to sequense, at this point cards must form pure seq, check further
			if (a.GetRank() + 1 == b.GetRank() && a.GetSuit() == b.GetSuit())
			{
				this->Meld.PushBack(a);
				continue;
			}
			else
			{
				break;
			}
		}
		// By some miracle all the cars are one giant pure seq.
		// It's a win 100%
		if (this->Hand.GetSize() == 0)
		{
			this->GameState = win;
			return;
		}

		// Not all card are pusre seq, must try fing impure one for all cards left.
		// A problem here appears, if by any chance card is jocker or wild jocker it can replace any other card
		// More over, there might be more than one jokers, so the only thing to do is remove all jokers and wilds to seperate deck to
		// Then wi will have an idea of what exactly are we dealing with

		for (size_t i; i < this->Hand.GetSize(); i++)
		{
			Card& a = this->Hand.GetCard(i);
			if (a.GetRank() == Jocker || a == deck.GetWildJocker())
			{
				jockers.push_back(a);
			}
		}

		for (size_t i = 0; i < jockers.size(); i++)
		{
			this->Hand.RemoveCard(jockers[i]);
		}

		// All other cards are jockers exemp ones in Meld - not good at all must get rid of at least one
		if (this->Hand.GetSize() == 0)
		{
			this->GameState = tooManyJockers;
			return;
		}

		cardsInSeq = this->Meld.GetSize();
		// There can't be two jockers in an impure Seq, so our troubles are not that bad
		for (size_t i = 0; i < this->Hand.GetSize() - 2; i++)
		{
			Card& a = this->Hand.GetCard(i);
			Card& b = this->Hand.GetCard(i + 1);
			Card& c = this->Hand.GetCard(i + 2);

			// This is where it gets really bad, we must first check if by some miracle a second pure seq can be formed.
			// Then check for impure seq, but if we have no jockers at all, there is no point in checking. Impure seq can't be done
			if ( (a.GetSuit() == b.GetSuit() && b.GetSuit() == c.GetSuit() && a.GetRank() + 1 == b.GetRank() && b.GetRank() + 1 == c.GetRank()) )
			{
				this->Meld.PushBack(a);
				this->Meld.PushBack(b);
				this->Meld.PushBack(c);

				this->GameState = secPureSeq; // We actually found a second pure sequense
				i = i + 3;
				break;
			}
			else if( (a.GetSuit() == b.GetSuit() && a.GetRank() + 2 == b.GetRank())
				|| (a.GetSuit() == c.GetSuit() && a.GetRank() + 2 == c.GetRank())
				|| (b.GetSuit() == c.GetSuit() && b.GetRank() + 2 == c.GetRank())
				)
			{
				this->Meld.PushBack(a);
				this->Meld.PushBack(b);
				this->Meld.PushBack(c);

				this->GameState = impureSec;
				i = i + 3;
				break;
			}
		}

		// Remove any new seq
		for (size_t i = cardsInSeq; i < this->Meld.GetSize(); i++)
		{
			this->Hand.RemoveCard(this->Meld.GetCard(i));
		}

	// At this point there is either a second pure seq, or an impure seq was found.
	case secPureSeq:
	case impureSec:
		cardsInSeq = this->Meld.GetSize();
		for (size_t i = 0; i < this->Hand.GetSize(); i++)
		{
			Card& a = this->Hand.GetCard(i);
			Card& b = this->Meld.GetDeckCopy()[this->Meld.GetSize() - 1];

			//Another card was found to be added to sequense, at this point cards must form pure seq, check further
			if (a.GetRank() + 1 == b.GetRank() && a.GetSuit() == b.GetSuit())
			{
				this->Meld.PushBack(a);
				continue;
			}
			else
			{
				break;
			}
		}

		for (size_t i = cardsInSeq; i < this->Meld.GetSize(); i++)
		{
			this->Hand.RemoveCard(this->Meld.GetCard(i));
		}
 
		// All cards are grouped. Win
		if (this->Hand.GetSize() == 0)
		{
			this->GameState = win;
			return;
		}

		// There is a possibility of a third sequense.
		cardsInSeq = this->Meld.GetSize();
		for (size_t i = 0; i < this->Hand.GetSize()-2; i++)
		{
			Card& a = this->Hand.GetCard(i);
			Card& b = this->Meld.GetCard(i+1);
			Card& c = this->Meld.GetCard(i+2);

			if ((a.GetSuit() == b.GetSuit() && b.GetSuit() == c.GetSuit() && a.GetRank() + 1 == b.GetRank() && b.GetRank() + 1 == c.GetRank()))
			{
				this->Meld.PushBack(a);
				this->Meld.PushBack(b);
				this->Meld.PushBack(c);

				this->GameState = secPureSeq; // We actually found a second pure sequense
				i = i + 3;
				break;
			}
			else if ((a.GetSuit() == b.GetSuit() && a.GetRank() + 2 == b.GetRank())
				|| (a.GetSuit() == c.GetSuit() && a.GetRank() + 2 == c.GetRank())
				|| (b.GetSuit() == c.GetSuit() && b.GetRank() + 2 == c.GetRank())
				)
			{
				this->Meld.PushBack(a);
				this->Meld.PushBack(b);
				this->Meld.PushBack(c);

				this->GameState = impureSec;
				i = i + 3;
				break;
			}
		}

		for (size_t i = cardsInSeq; i < this->Meld.GetSize(); i++)
		{
			this->Hand.RemoveCard(this->Meld.GetCard(i));
		}

		// Distinct possibility of more cards in seq
		cardsInSeq = this->Meld.GetSize();
		for (size_t i = 0; i < this->Hand.GetSize(); i++)
		{
			Card& a = this->Hand.GetCard(i);
			Card& b = this->Meld.GetDeckCopy()[this->Meld.GetSize() - 1];

			//Another card was found to be added to sequense, at this point cards must form pure seq, check further
			if (a.GetRank() + 1 == b.GetRank() && a.GetSuit() == b.GetSuit())
			{
				this->Meld.PushBack(a);
				continue;
			}
			else
			{
				break;
			}
		}
	}
}

void AI::DiscardCard()
{
	srand(unsigned(time(NULL)));
	if(this->Hand.GetSize() == 0)
	{
		this->Meld.PopBack();
		return;
	}
	size_t i = rand() % (this->Hand.GetSize() - 1);
	this->Hand.RemoveFromDeck(i);
	return;
}

void AI::MakeTurn(Deck& deck, Deck& discard)
{
	this->SelectCard(deck, discard);
	this->MeldCards(deck);
	this->DiscardCard();
}
