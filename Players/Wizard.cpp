#include "Wizard.h"

Wizard::Wizard(const string& name) : Player(name)
{
}

void Wizard::heal(int healBy)
{
    if (healBy<0)
    {
        return;
    }
    m_HP = m_HP + 2*healBy;
    if(m_HP > m_maxHP)
    {
        m_HP = m_maxHP;
    } 
}

string Wizard::getJob() const
{
    return "Wizard";
}