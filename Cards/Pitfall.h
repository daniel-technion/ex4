#ifndef EX4_Pitfall_H
#define EX4_Pitfall_H


#include "Card.h"

class Pitfall : Card
{
    public:
    /**
     * @brief Construct a new Pitfall object
     */
    Pitfall() = default;

    /**
     * @brief Destroy the Pitfall object
     */
    ~Pitfall() = default;

    /**
     * @brief Default Assigment Opertor
     * 
     * @param Pitfall 
     */
    Pitfall(const Pitfall& Pitfall) = default;

        /**
     * @brief Default Assigment Operator
     * 
     * @param Pitfall 
     */
    Pitfall& operator=(const Pitfall& Pitfall) = default;

    void applyEncounter(Player& player) const override;

    string getName() const override;

    private:
    /**
     * @brief the amount of healthpoints a player may loose upon encountering Pitfall Card
     * 
     */
    const static int HP_LOSS_VALUE = 10;  
};

#endif