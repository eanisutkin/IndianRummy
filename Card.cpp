#include "Card.h"

Card::Card(Rank a, Suit b)
{
  this->value = a;
  this->type = b;
}

Rank Card::GetRank()
{
  return this->value;
}

Suit Card::GetSuit()
{
  return this->type;
}

bool operator <(const Card& a, const Card& b)
{
  if (a.type < b.type)
  {
    return true;
  }
  else if (a.type == b.type)
  {
    if(a.value < b.value)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

bool operator ==(const Card& a, const Card& b)
{
  if (a.value == b.value && a.type == b.type)
  {
    return true;
  }
  else
  {
    return false;
  }
}