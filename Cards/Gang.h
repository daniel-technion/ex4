#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Card.h"
#include "BattleCard.h"
#include "../utilities.h"
#include <vector>
#include <memory>

class Gang : public Card
{
    public:
    Gang(vector<unique_ptr<BattleCard>>& battleCards);
    Gang (const Gang& gang);
    Gang& operator=(const Gang& gang);
    ~Gang() = default;
    void applyEncounter(Player& player) const override;
    string getName() const override;

    private:
    vector<unique_ptr<BattleCard>> m_battleCards;

};

#endif