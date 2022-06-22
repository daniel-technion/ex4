#include "BattleCard.h"
#include "../Players/Player.h"
#include "../utilities.h"

using namespace std;

BattleCard::BattleCard(int attackForce, int loot) : m_attackForce(attackForce), m_loot(loot)
{
}

void BattleCard::applyEncounter(Player& player) const
{
    int playerStrength = player.getAttackStrength();
    if (playerStrength>=m_attackForce)
    {
        win(player, false);
        printWinBattle(player.getName(), getName());
    } else
    {
        loss(player);
        printLossBattle(player.getName(), getName());
    }
}

void BattleCard::win(Player& player, bool isGangBattle) const
{
    if (isGangBattle == false)
    {
        player.levelUp();
    }
    player.addCoins(m_loot);
}

int BattleCard::getAttackForce() const
{
    return m_attackForce;
}