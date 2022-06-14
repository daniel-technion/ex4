#ifndef EX4_Treasure_H
#define EX4_Treasure_H


#include "Card.h"

class Treasure : public Card
{
    public:
    Treasure() = default;
    void applyEncounter(Player& player) const override;

    private:
    const static int COINS_PRIZE = 10;
};

#endif