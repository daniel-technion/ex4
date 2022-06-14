#include "BattleCard.h"

class Dragon : public BattleCard
{
    public:
    Dragon(); 
    string getName() const override;
    void loss(Player& player) const override;

    // values for the constructor to use in the initialization.
    //TODO: should it be here or just use numbers in the constructor
    private:
    const static int ATTACK_FORCE_VALUE = 25;
    const static int LOOT_VALUE = 1000;
};