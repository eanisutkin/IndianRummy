#include <iostream>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "Deck.h"
#include "AI.h"

using namespace std;

constexpr auto WINNING_SCORE = 500;

//// Intro which includes rules for the game
//void outputIntro();
//
//// Outputs winner and ending
//void outputEnding(Player &player, AI &comp);
//
//// Deals the deck
//// Inserts a card into players hand, pops card off of the deck
//// then inserts a card into computer's hand and pops a card off
//// the deck. Continues till each player has a full hand
//void dealDeck(Player& player, AI& comp, Deck& deck, int count);

bool checkPlayerScores(vector<Player>& Players);

void main()
{
	// Outputs the rules for the game
	//outputIntro();

	string name;

	// Retrieve user's name and initialize the Player
	cout << "\nEnter numebr of players: ";
	getline(cin, name);
	size_t numberOfPlayers = atoi(name.c_str());
	if (numberOfPlayers < 2)
	{
		numberOfPlayers = 2;
	}
	else if (numberOfPlayers > 6)
	{
		numberOfPlayers = 6;
	}

	vector<Player> Players;
	for (size_t i = 0; i < numberOfPlayers - 1; i++)
	{

		// Retrieve user's name and initialize the Player
		cout << "\nEnter " << i + 1 << "'th players name: ";
		getline(cin, name);

		Players.push_back(Player(name, 0));
	}

	// Retrieve a name for the computer and initialize the computer
	cout << "\nEnter a name for the computer: ";
	getline(cin, name);
	Players.push_back(AI(name, 0));

	// initialize and shuffle up the deck
	Deck* deck = new Deck(true, 2);
	deck->ShuffleDeck();

	size_t roundCount = 0;

	//// Game continues as long as neither player has over WINNING_SCORE points
	while (!checkPlayerScores(Players))
	{


		deck.

		//	deck.dealCards(Player a, AI b;)

		//	// Deal the deck
		//	dealDeck(user, comp, deck, roundCount);

		//	// Reset count back to roundCount --> alternate who goes first
		//	unsigned int count = roundCount;

		//	// Commence the game, game continues as long as both players have cards
		//	while ((user.GetHandSize() > 0) && (comp.GetHandSize() > 0) && (deck.GetDeckSize() > 0))
		//	{
		//		// Must call gameplay every play through the hand

		//		if (count % 2 == 0)	// Player is up
		//			user.GamePlay(deck, comp.ReturnVectorOfMyMeldedCards(), comp.GetName());
		//		else						// Computer is up
		//			comp.GamePlay(deck);

		//		count++;
		//	}
		//	// Round is over, must increment the round count
		//	roundCount++;
		//}
		//// Someone has won by now
		//outputEnding(user, comp);

		//return;
	// }

	//void outputIntro()
	//{
	//	cout << "Welcome to Rummy 500!\n";
	//	cout << "Written by Austin Heimark\n\n";
	//
	//	// List the rules
	//	cout << "RULES OF THE GAME:\n" <<
	//		"It is you versus the computer.\n" <<
	//		"First player to " << WINNING_SCORE << " points wins.\n" <<
	//		"Each player is dealt " << CARDS_DEALT << " cards of a standard \n" <<
	//		DECK_SIZE << " card deck each hand.\n" <<
	//		"User (you) goes first; this alternates each hand.\n" <<
	//		"Players earn points by melding \ncards from their hand into the meld area.\n" <<
	//		"Players may meld a set of \ncards once they have at least 3 of a kind\n" <<
	//		"(ex: 3 " << Rank(5) << "s) or 3 in a row \nof the same suit (ex: 4,5,6 of spades).\n" <<
	//		"Each turns starts with picking \nup a card, and ends by discarding a card.\n" <<
	//		"The hand continues until \none player has used all of their cards.\n" <<
	//		"Points are tallied at the end of each hand.\n" <<
	//		"Point per card are as follows:\n" <<
	//		Rank(0) + RANK_OFFSET << " ... " << Rank(8) + RANK_OFFSET << " --> " << TWO_THROUGH_NINE_POINTS << " points\n" <<
	//		Rank(9) + RANK_OFFSET << " ... " << Rank(11) + RANK_OFFSET << " --> " << TEN_THROUGH_KING_POINTS << " points\n" <<
	//		Rank(12) + RANK_OFFSET << " --> " << ACE_POINTS << " points. " <<
	//		"New hands keep being dealt \nuntil a player has over " << WINNING_SCORE << " points.\n" <<
	//		"If both players end with over " << WINNING_SCORE << "\npoints, player with more points wins.\n" <<
	//		"When you are prompted for card \n" <<
	//		"locations, it is zero based. That is\n" <<
	//		"if you want the first card from your hand\n" <<
	//		"you would enter '" << EMPTY << "'. If choosing multiple cards\n" <<
	//		"use one space between numbers.\n" <<
	//		"The first letter or number is the rank\n" <<
	//		"and after the dash is the suit of the card\n" <<
	//		"H = Hearts, S = Spades, D = Diamonds, C = Clubs.\n" <<
	//		"Please not that the face cards will not be sorted in your hand,\n" <<
	//		"However, the non face cards will be sorted!\n" <<
	//		"You must meld at least one card when you pick\nit up from the pick up pile\n" <<
	//		YES << " means 'Yes' when asked yes/no questions.\nAnything else will be interpreted as a no.\n" <<
	//		"When melding cards, always tell which cards you \nwant to meld from your hand in decreasing location order.\n" <<
	//		"And when telling the computer these meld spots, \nterminate your entries with a " << TERMINATE_NUMBER << ".\n";
	//}
	//
	//void outputEnding(Player& player, Computer& comp)
	//{
	//	cout << "Final Score:\n" << player.GetName() << ": " << player.GetScore() << "\n" << comp.GetName() << ": " << comp.GetScore() << "\n\n";
	//
	//	// Whichever player has the higher score wins
	//	if (player.GetScore() >= comp.GetScore())
	//		cout << "Congratulations, " << player.GetName() << "! You beat the computer in Rummy 500!";
	//	else
	//		cout << "Sorry, " << comp.GetName() << " defeated you!";
	//
	//	// Thanks to the players
	//	cout << "\n\nI hope you enjoyed my game!" <<
	//		"\nFeedback please to: ach5306@psu.edu\n\n";
	//}
	//
	//void dealDeck(Player& user, Computer& comp, Cards& deck, int count)
	//{
	//	if (count % EVEN_ODD == EMPTY)	// Deal to user first
	//	{
	//		unsigned int i = EMPTY;
	//		while (i < EVEN_ODD * CARDS_DEALT)
	//		{
	//			user.InsertIntoHand(deck.TopDeckCard());
	//			deck.PopOffCard();
	//			i++;
	//			comp.InsertIntoHand(deck.TopDeckCard());
	//			deck.PopOffCard();
	//			i++;
	//		}
	//		deck.AdjustPickPile();
	//	}
	//	else						// Deal to computer first
	//	{
	//		unsigned int j = EMPTY;
	//		while (j < EVEN_ODD * CARDS_DEALT)
	//		{
	//			comp.InsertIntoHand(deck.TopDeckCard());
	//			deck.PopOffCard();
	//			j++;
	//			user.InsertIntoHand(deck.TopDeckCard());
	//			deck.PopOffCard();
	//			j++;
	//		}
	//		deck.AdjustPickPile();
	//	}
	//}
	//
	//void ScoreOutput(Player& user, Computer& comp, int roundCount)
	//{
	//	cout << "After " << roundCount << " rounds:\n" <<
	//		"Your current score: " << user.GetScore() << "\n" <<
	//		comp.GetName() << "'s current score: " << comp.GetScore() << "\n" <<
	//		"And the game continues...\n\n";
	//}
	}
}

bool checkPlayerScores(vector<Player>& Players)
{
	for (size_t i = 0; i < Players.size(); i++)
	{
		if (Players[i].GetScore() > WINNING_SCORE)
		{
			return true;
		}
	}

	return false;
}
