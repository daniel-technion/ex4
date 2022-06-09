#include "BattleCard.h"

class Dragon : public BattleCard
{
    public:
    Dragon(); //implement the constructor with the deafult values;

    // values for the constructor to use in the initialization.
    //TODO: should it be here or just use numbers in the constructor
    private:
    const static int ATTACK_FORCE_VALUE = 25;
    const static int LOOT_VALUE = 1000;
    const static int HP_DAMAGE_VALUE = 0; //TODO: change to maxHP
    const static int FORCE_DAMAGE_VALUE = 0;


};