#ifndef EX4_Fairy_H
#define EX4_Fairy_H

#include "Card.h"
#include "..Players/Wizard.h"

class Fairy : public Card
{
    public:
    Fairy() = default;
    void applyEncounter(Player& player) const override;
    string getName() const override;

    private:
    const static int HP_PRIZE = 10;
};

#endif