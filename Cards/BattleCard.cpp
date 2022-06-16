#include "BattleCard.h"
#include "/home/daniel.pe/ex4/Players/Player.h"
#include "/home/daniel.pe/ex4/utilities.h"

/*
Card* BattleCard::clone() const
{
    return new BattleCard(*this);
}
*/

BattleCard::BattleCard(int attackForce, int loot) : m_attackForce(attackForce), m_loot(loot)
{
}

void BattleCard::applyEncounter(Player& player) const
{
    int playerStrength = player.getAttackStrength();
    if (playerStrength>=m_attackForce)
    {
        win(player);
        printWinBattle(player.getName(), getName());
    } else
    {
        loss(player);
        printLossBattle(player.getName(), getName());
    }
}

void BattleCard::win(Player& player) const
{
    player.levelUp();
    player.addCoins(m_loot);
}