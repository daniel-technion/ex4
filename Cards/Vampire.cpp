#include "Vampire.h"
#include "../utilities.h"

Vampire::Vampire() : BattleCard(ATTACK_FORCE_VALUE, LOOT_VALUE), m_forceDamage(FORCE_DAMAGE_VALUE), m_hpDamage(HP_DAMAGE_VALUE)
{}

void Vampire::loss(Player& player) const
{
    player.damage(m_hpDamage);
    player.weaken(m_forceDamage);
}

string Vampire::getName() const
{
    return "Vampire";
}

std::ostream& Vampire::print(std::ostream& os) const
{
    printCardDetails(os, getName());
    printMonsterDetails(os, m_attackForce, m_hpDamage, m_loot, false);
    printEndOfCardDetails(os);
    return os;
}