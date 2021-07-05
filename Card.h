#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

enum Rank
{
  Jocker = 0,
  Two = 2,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace,
  NumOfRanks
};

enum Suit
{
  J,
  D,
  H,
  S,
  C,
  NumOfSuits
};

class Card
{
private:
  Rank value;
  Suit type;
public:
  Card(Rank a, Suit b);
  Rank GetRank();
  Suit GetSuit();

  friend bool operator <(const Card& a, const Card& b);
  friend bool operator ==(const Card& a, const Card& b);
};

#endif