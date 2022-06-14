#include "Dragon.h"

Dragon::Dragon() : BattleCard(ATTACK_FORCE_VALUE, LOOT_VALUE)
{}

string Dragon::getName() const
{
    return "Dragon";
}

void Dragon::loss(Player& player) const
{
    player.knockOut();
}