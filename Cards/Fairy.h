#ifndef EX4_Fairy_H
#define EX4_Fairy_H

#include "Card.h"
#include "../Players/Wizard.h"

class Fairy : public Card
{
    public:
    /**
     * @brief Construct a new Fairy object
     */
    Fairy() = default;

    /**
     * @brief Default Copy Constructor
     * @param fairy 
     */
    Fairy(const Fairy& fairy) = default;

    /**
     * @brief Default Assigment Opertor
     * 
     * @param fairy 
     * @return Fairy& 
     */
    Fairy& operator=(const Fairy& fairy) = default;

    void applyEncounter(Player& player) const override;
    
    string getName() const override;

    private:
    const static int HP_PRIZE = 10;
};

#endif