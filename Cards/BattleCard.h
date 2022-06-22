#ifndef EX4_BATTLE_CARD_H
#define EX4_BATTLE_CARD_H

#include "Card.h"
#include <memory>

class BattleCard : public Card
{
    public:
    /**
     * @brief Construct a new Battle Card object
     * 
     * @param attackForce 
     * @param loot 
     */
    BattleCard(int attackForce, int loot);

    /**
     * @brief Destroy the Battle Card object
     */
    virtual ~BattleCard() = default;

    /**
     * @brief Deafult Copy Constructor
     * @param battleCard 
     */
    BattleCard(const BattleCard& battleCard) = default;

    /**
     * @brief Default Asiggment Operator
     * 
     * @param battleCard 
     * @return BattleCard& 
     */
    BattleCard& operator=(const BattleCard& battleCard) = default;

    /**
     * @brief create new BattleCard object
     * 
     * @return unique_ptr<BattleCard> 
     */
    virtual unique_ptr<BattleCard> clone() const = 0;

    void applyEncounter(Player& player) const override;

    /**
     * @brief apply lossing consequenses on the player upon being defeated by the monster
     * 
     * @param player 
     */
    virtual void loss(Player& player) const = 0;

    /**
     * @brief apply winning consequenses on the player upon defeating the monster
     * 
     * @param player 
     * @param isGangBattle 
     */
    void win(Player& player, bool isGangBattle) const;

    virtual string getName() const override = 0;

    virtual std::ostream& print(std::ostream& os) const override = 0;

    /**
     * @brief Get the Attack Force object
     * 
     * @return int 
     */
    int getAttackForce() const;

    protected:
    /**
     * @brief the attack force of the monster
     * 
     */
    const int m_attackForce;

    /**
     * @brief the coins prize upon defeating the monster
     * 
     */
    const int m_loot;
};

#endif