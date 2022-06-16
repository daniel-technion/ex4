#ifndef EX4_Goblin_H
#define EX4_Goblin_H

#include "BattleCard.h"

class Goblin : public BattleCard
{
    public:
    Goblin();
    string getName() const override;
    void loss(Player& player) const;
    std::ostream& print(std::ostream& os) const override;

    private:
    int m_hpDamage;

    const static int ATTACK_FORCE_VALUE = 6;
    const static int LOOT_VALUE = 2;
    const static int HP_DAMAGE_VALUE = 10; 
};

#endif