#include "Goblin.h"

 Goblin::Goblin() : BattleCard(ATTACK_FORCE_VALUE, LOOT_VALUE), m_hpDamage(HP_DAMAGE_VALUE)
 {}

string Goblin::getName() const
{
    return "Goblin";
}

void Goblin::loss(Player& player) const
{
    player.damage(m_hpDamage);
}