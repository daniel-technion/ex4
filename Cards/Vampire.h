#include "BattleCard.h"

class Vampire : public BattleCard
{
    public:
    Vampire();

    private:
    const static int ATTACK_FORCE_VALUE = 10;
    const static int LOOT_VALUE = 2;
    const static int HP_DAMAGE_VALUE = 10; 
    const static int FORCE_DAMAGE_VALUE = 1;
};