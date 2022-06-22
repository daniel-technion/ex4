#include "Treasure.h"
#include "../utilities.h"

using namespace std;

string Treasure::getName() const
{
    return "Treasure";
}


void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(COINS_PRIZE);
    printTreasureMessage();
}