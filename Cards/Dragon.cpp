#include "Dragon.h"


Dragon::Dragon() : BattleCard(ATTACK_FORCE_VALUE, LOOT_VALUE)
{}

unique_ptr<BattleCard> Dragon::clone() const
{
    unique_ptr<BattleCard> res (new Dragon(*this));
    return res;
}

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