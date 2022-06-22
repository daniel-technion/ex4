#include "Gang.h"

Gang::Gang(vector<unique_ptr<BattleCard>> battleCards) : m_battleCards(move(battleCards))
{
    /*
    m_battleCards.reserve(battleCards.size());
    vector<unique_ptr<BattleCard>>::const_iterator it = battleCards.begin();
    for(; it != battleCards.end() ; it++)
    {
        m_battleCards.push_back((*it)->clone());
    }
    */
}

/*
Gang::Gang(const Gang& gang)
{
    m_battleCards.reserve(gang.m_battleCards.size());
    vector<unique_ptr<BattleCard>>::const_iterator it = gang.m_battleCards.begin();
    for(; it != gang.m_battleCards.end() ; it++)
    {
        m_battleCards.push_back((*it)->clone());
    }
}

Gang& Gang::operator=(const Gang& gang)
{
    m_battleCards.clear();
    m_battleCards.reserve(gang.m_battleCards.size());
    vector<unique_ptr<BattleCard>>::const_iterator it = gang.m_battleCards.begin();
    for(; it != gang.m_battleCards.end() ; it++)
    {
        m_battleCards.push_back((*it)->clone());
    }
    return *this;
}
*/
string Gang::getName() const
{
    return "Gang";
}

void Gang::applyEncounter(Player& player) const
{
    vector<unique_ptr<BattleCard>>::const_iterator it = m_battleCards.begin();
    vector<unique_ptr<BattleCard>>::const_iterator end = m_battleCards.end();

    while((it != end) && ((*it)->getAttackForce()<=player.getAttackStrength()))
    {
        (*it)->win(player,true);
        it++;
    }
    if(it == end)
    {
        player.levelUp();
        printWinBattle(player.getName(), getName());
    }
    while(it != end)
    {
        (*it)->loss(player);
        printLossBattle(player.getName(), (*it)->getName());
        it++;
    }
}