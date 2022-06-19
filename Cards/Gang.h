#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Card.h"
#include "BattleCard.h"
#include "../utilities.h"
#include <vector>

class Gang : public Card
{
    public:
    Gang(vector<BattleCard*>& battleCards);
    void applyEncounter(Player& player) const override;
    string getName() const override;

    private:
    vector<BattleCard*> m_battleCards;

};

#endif