#include "BattleCard.h"

Card* BattleCard::clone() const
{
    return new BattleCard(*this);
}

void BattleCard::applyEncounter() const
{

}
