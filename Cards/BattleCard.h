#ifndef EX4_BATTLE_CARD_H
#define EX4_BATTLE_CARD_H

#include "Card.h"

class BattleCard : public Card
{
    public:
    BattleCard();
    BattleCard(int attackForce, int loot);
    //Card* clone() const override;
    
    void applyEncounter(Player& player) const override;
    virtual void loss(Player& player) const = 0;
    void win(Player& player) const;
    virtual string getName() const override = 0;
    virtual std::ostream& print(std::ostream& os) const override = 0;

    protected:
    const int m_attackForce;
    const int m_loot;
};

#endif