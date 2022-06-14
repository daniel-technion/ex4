#ifndef EX4_Vampire_H
#define EX4_Vampire_H

#include "BattleCard.h"

class Vampire : public BattleCard
{
    public:
    Vampire();
    void loss(Player& player) const override;
    string getName() const override;

    private:
    const int m_forceDamage;
    int m_hpDamage;

    const static int ATTACK_FORCE_VALUE = 10;
    const static int LOOT_VALUE = 2;
    const static int HP_DAMAGE_VALUE = 10; 
    const static int FORCE_DAMAGE_VALUE = 1;
};

#endif