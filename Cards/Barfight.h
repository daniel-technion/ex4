#ifndef EX4_Barfight_H
#define EX4_Barfight_H

#include "Card.h"

class Barfight : public Card
{
    public:
    /**
     * @brief Construct a new Barfight object
     */
    Barfight() = default;

    /**
     * @brief Default Copy Constructor
     * @param barfight 
     */
    Barfight(const Barfight& barfight) = default;

    /**
     * @brief Default Assigment Opertaor
     * 
     * @param barfight 
     * @return Barfight& 
     */
    Barfight& operator=(const Barfight& barfight)= default;

    void applyEncounter(Player& player) const override;
    std::string getName() const override;

    private:
    /**
     * @brief the amount of healthpoint a player may lose upon encountering Barfight card
     */
    static const int HP_LOSS_VALUE = 10;
};

#endif 