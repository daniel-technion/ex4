#include "Fighter.h"

Fighter::Fighter(const string& name) : Player(name)
{
}

int Fighter::getAttackStrength() const
{
    return m_force*2 + m_level;
}

string Fighter::getJob() const
{
    return "Fighter";
}