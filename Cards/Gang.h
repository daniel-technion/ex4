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
    /**
     * @brief Construct a new Gang object
     * 
     * @param battleCards the monsters of the gang
     */
    Gang(vector<unique_ptr<BattleCard>>& battleCards);

    /**
     * @brief Copy Constructor
     * 
     * @param gang 
     */
    Gang (const Gang& gang);

    /**
     * @brief Assigment Operator
     * 
     * @param gang 
     * @return Gang& 
     */
    Gang& operator=(const Gang& gang);
    
    void applyEncounter(Player& player) const override;
    std::string getName() const override;

    private:
    /**
     * @brief the monsters of the gang
     */
    vector<unique_ptr<BattleCard>> m_battleCards;

};

#endif