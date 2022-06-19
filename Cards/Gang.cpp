#include "Gang.h"

Gang::Gang(vector<BattleCard*>& battleCards) : m_battleCards(battleCards)
{
}

string Gang::getName() const
{
    return "Gang";
}

void Gang::applyEncounter(Player& player) const
{
    vector<BattleCard*>::const_iterator it = m_battleCards.begin();
    vector<BattleCard*>::const_iterator end = m_battleCards.end();

    while((it != end) && ((*it)->getAttackForce()<=player.getAttackStrength()))
    {
        (*it)->win(player,true);
        printWinBattle(player.getName(), (*it)->getName());
        it++;
    }
    if(it == end)
    {
        player.levelUp();
    }
    while(it != end)
    {
        (*it)->loss(player);
        printLossBattle(player.getName(), (*it)->getName());
        it++;
    }
}