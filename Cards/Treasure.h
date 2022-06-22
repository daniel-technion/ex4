#ifndef EX4_Treasure_H
#define EX4_Treasure_H

#include "Card.h"

class Treasure : public Card
{
    public:
    /**
     * @brief Construct a new Treasure object
     */
    Treasure() = default;

    /**
     * @brief Default Copy Constructor
     * 
     * @param treasure 
     */
    Treasure(const Treasure& treasure) = default;

    /**
     * @brief Default Assigment Opertor
     * 
     * @param tresure 
     * @return Treasure& 
     */
    Treasure& operator=(const Treasure& tresure) = default;

    void applyEncounter(Player& player) const override;

    std::string getName() const override;

    private:
    /**
     * @brief the amount of coins a player may receive upon encountering the Treasure Card
     * 
     */
    const static int COINS_PRIZE = 10;
};

#endif