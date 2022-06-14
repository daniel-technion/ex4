#ifndef EX4_BATTLE_CARD_H
#define EX4_BATTLE_CARD_H

#include "Card.h"


class BattleCard : public Card
{
    public:
    Card* clone() const override;
    void applyEncounter(Player& player) const override;

    protected:
    BattleCard();

    private:
    const int attackForce;
    const int loot;
    const int hpDamage;
    const int forecDamage;
   
};

#endif