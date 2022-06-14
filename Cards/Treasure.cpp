#include "Treasure.h"

string Treasure::getName() const
{
    return "Treasure";
}


void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(COINS_PRIZE);
}