#ifndef EX4_Vampire_H
#define EX4_Vampire_H

#include "BattleCard.h"

class Vampire : public BattleCard
{
    public:
    /**
     * @brief Construct a new Vampire object
     */
    Vampire();

    /**
     * @brief Destroy the Vampire object
     * 
     */
    ~Vampire() = default;

    /**
     * @brief Construct a new Vampire object
     * 
     * @param vampire 
     */
    Vampire(const Vampire& vampire) = default;

    /**
     * @brief Default Assigment Opertor
     * 
     * @param vampire 
     * @return Vampire& 
     */
    Vampire& operator=(const Vampire& vampire) = default;

    void loss(Player& player) const override;

    string getName() const override;

    std::ostream& print(std::ostream& os) const override;

    unique_ptr<BattleCard> clone() const override;

    private:
    /**
     * @brief the amount of force points a player my lose upon being defeated by the monster
     */
    const int m_forceDamage;

    /**
     * @brief the amount of healthpoints a player my lose upon being defeated by the monster
     */
    int m_hpDamage;

    /**
     * @brief the attack force of every Vampire
     */
    const static int ATTACK_FORCE_VALUE = 10;

    /**
     * @brief the amount of coins a player receives upon defeating every Vampire
     * 
     */
    const static int LOOT_VALUE = 2;

    /**
     * @brief the amount of healthpoints a player loses upon being defeated by a Vampire
     * 
     */
    const static int HP_DAMAGE_VALUE = 10; 

    /**
     * @brief the amount of force points a player loses upon being defeated by a Vampire
     * 
     */
    const static int FORCE_DAMAGE_VALUE = 1;
};

#endif