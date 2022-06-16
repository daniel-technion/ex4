#include "Treasure.h"
#include "/home/daniel.pe/ex4/utilities.h"

string Treasure::getName() const
{
    return "Treasure";
}


void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(COINS_PRIZE);
    printTreasureMessage();
}