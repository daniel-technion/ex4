#include "Goblin.h"
#include "../utilities.h"

 Goblin::Goblin() : BattleCard(ATTACK_FORCE_VALUE, LOOT_VALUE), m_hpDamage(HP_DAMAGE_VALUE)
 {}

 unique_ptr<BattleCard> Goblin::clone() const
{
    unique_ptr<BattleCard> res (new Goblin(*this));
    return res;
}

std::string Goblin::getName() const
{
    return "Goblin";
}

void Goblin::loss(Player& player) const
{
    player.damage(m_hpDamage);
}

std::ostream& Goblin::print(std::ostream& os) const
{
    printCardDetails(os, getName());
    printMonsterDetails(os, m_attackForce, m_hpDamage, m_loot, false);
    printEndOfCardDetails(os);
    return os;
}
