#include "Vampire.h"

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
