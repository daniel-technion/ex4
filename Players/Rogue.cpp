#include "Rogue.h"

Rogue::Rogue(const string& name) : Player(name)
{
}

void Rogue::addCoins(int coinsToAdd)
{
    if (coinsToAdd<0)
    {
        return;
    }
    m_coins = m_coins + 2*coinsToAdd;
}

string Rogue::getJob() const
{
    return "Rogue";
}