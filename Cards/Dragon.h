#include "BattleCard.h"
#include "../utilities.h"
#include <memory>


class Dragon : public BattleCard
{
    public:
    Dragon(); 
    Dragon(const Dragon& dragon) = default;
    string getName() const override;
    void loss(Player& player) const override;
    std::ostream& print(std::ostream& os) const override;
    unique_ptr<BattleCard> clone() const override;

    // values for the constructor to use in the initialization.
    //TODO: should it be here or just use numbers in the constructor
    private:
    const static int ATTACK_FORCE_VALUE = 25;
    const static int LOOT_VALUE = 1000;
};