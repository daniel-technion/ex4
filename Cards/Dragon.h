#ifndef EX4_Dragon_H
#define EX4_Dragon_H


#include "BattleCard.h"
#include "../utilities.h"
#include <memory>


class Dragon : public BattleCard
{
    public:
    /**
     * @brief Construct a new Dragon object
     */
    Dragon(); 

    /**
     * @brief Destroy the Dragon object
     */
    ~Dragon() = default;

    /**
     * @brief Default Copt Constructor
     * @param dragon 
     */
    Dragon(const Dragon& dragon) = default;

    /**
     * @brief Default Assigment Opertor
     * 
     * @param dragon 
     * @return Dragon& 
     */
    Dragon& operator=(const Dragon& dragon) = default;

    string getName() const override;
    void loss(Player& player) const override;
    std::ostream& print(std::ostream& os) const override;
    unique_ptr<BattleCard> clone() const override;

    // values for the constructor to use in the initialization.
    //TODO: should it be here or just use numbers in the constructor
    private:
    /**
     * @brief the attack force of every Dragon card
     */
    const static int ATTACK_FORCE_VALUE = 25;

    /**
     * @brief the coins prize upon defeating every Dragon card
     * 
     */
    const static int LOOT_VALUE = 1000;
};

#endif
