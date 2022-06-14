#include "Rouge.h"

Rouge::Rouge(const string& name) : Player(name)
{
}

void Rouge::addCoins(int coinsToAdd)
{
    if (coinsToAdd<0)
    {
        return;
    }
    m_coins = m_coins + 2*coinsToAdd;
}

string Rouge::getJob() const
{
    return "Rouge";
}