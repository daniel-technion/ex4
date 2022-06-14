#include "BattleCard.h"
#include "/home/daniel.pe/ex4/Players/Player.h"

Card* BattleCard::clone() const
{
    return new BattleCard(*this);
}

void BattleCard::applyEncounter(Player& player) const
{
    
}
