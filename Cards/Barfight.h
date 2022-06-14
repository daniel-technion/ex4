#ifndef EX4_Barfight_H
#define EX4_Barfight_H


#include "Card.h"

class Barfight : public Card
{
    public:
    Barfight() = default;
    void applyEncounter(Player& player) const override;

    private:
    static const int HP_LOSS_VALUE = 10;
};

#endif 