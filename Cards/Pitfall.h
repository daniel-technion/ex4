#ifndef EX4_Pitfall_H
#define EX4_Pitfall_H


#include "Card.h"

class Pitfall : Card
{
    public:
    Pitfall() = default;
    void applyEncounter(Player& player) const override;
    string getName() const override;

    private:
    const static int HP_LOSS_VALUE = 10;  
};

#endif