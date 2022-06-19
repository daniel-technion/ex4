#ifndef EX4_BATTLE_CARD_H
#define EX4_BATTLE_CARD_H

#include "Card.h"
#include <memory>

class BattleCard : public Card
{
    public:
    BattleCard(int attackForce, int loot);
    virtual unique_ptr<BattleCard> clone() const = 0;

    
    void applyEncounter(Player& player) const override;
    virtual void loss(Player& player) const = 0;
    void win(Player& player, bool isGangBattle) const;
    virtual string getName() const override = 0;
    virtual std::ostream& print(std::ostream& os) const override = 0;
    int getAttackForce() const;

    protected:
    const int m_attackForce;
    const int m_loot;
};

#endif