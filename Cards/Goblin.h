#ifndef EX4_Goblin_H
#define EX4_Goblin_H

#include "BattleCard.h"

class Goblin : public BattleCard
{
    public:
    /**
     * @brief Construct a new Goblin object
     */
    Goblin();

    /**
     * @brief Destroy the Goblin object
     */
    //~Goblin() = default ;

    /**
     * @brief Default Copy Constructor
     * @param goblin 
     */
    Goblin(const Goblin& goblin) = default;

    /**
     * @brief default Assigment Opertor
     * 
     * @param goblin 
     * @return Goblin& 
     */
    Goblin& operator=(const Goblin& goblin) = default;

    string getName() const override;
    void loss(Player& player) const;
    std::ostream& print(std::ostream& os) const override;
    unique_ptr<BattleCard> clone() const override;

    private:
    /**
     * @brief the amount of healthpoints the player loses upon being defeated by the monster
     * 
     */
    int m_hpDamage;

    /**
     * @brief the attack force of every Goblin
     */
    const static int ATTACK_FORCE_VALUE = 6;

    /**
     * @brief the coins prize of the player upon defeating every Goblin
     * 
     */
    const static int LOOT_VALUE = 2;

    /**
     * @brief the amount of healthpoints the player loses upon being defeated by every Goblin
     */
    const static int HP_DAMAGE_VALUE = 10; 
};

#endif