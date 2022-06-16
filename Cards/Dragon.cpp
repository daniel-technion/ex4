#include "Dragon.h"
#include "/home/daniel.pe/ex4/utilities.h"

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

std::ostream& Dragon::print(std::ostream& os) const
{
    printCardDetails(os, getName());
    printMonsterDetails(os, m_attackForce, 0, m_loot, true);
    printEndOfCardDetails(os);
    return os;
}