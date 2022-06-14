#include "Player.h"
#include "/home/daniel.pe/ex4/utilities.h"
#include <typeinfo>
#include <iostream>

Player::Player(const string& name) : m_name(name), m_force(DEFAULT_FORCE),  m_level(INITIALIZE_LEVEL),
                                      m_coins(INITIALIZE_COINS),m_HP(DEFAULT_MAX_HP), m_maxHP(DEFAULT_MAX_HP)
{
}

void Player::levelUp()
{
    if (m_level<MAX_LEVEL)
    {
        m_level = m_level+1;
    }
}

void Player::buff(int buffBy)
{
    if (buffBy<0)
    {
        return;
    }
    m_force = m_force + buffBy;
}

void Player::heal(int healBy)
{
    if (healBy<0)
    {
        return;
    }
    m_HP = m_HP + healBy;
    if(m_HP > m_maxHP)
    {
        m_HP = m_maxHP;
    } 
}

void Player::damage(int damageBy)
{
   if (damageBy<0)
    {
        return;
    }
    m_HP-=damageBy;
    if (m_HP < 0)
    {
        m_HP =0;
    }
}

bool Player::isKnockedOut() const 
{
    if (m_HP==MIN_HP)
    {
        return true;
    } 
    return false;
}

void Player::addCoins(int coinsToAdd)
{
    if (coinsToAdd<0)
    {
        return;
    }
    m_coins = m_coins + coinsToAdd;
}

bool Player::pay(int price)
{
    if (price<=0)
    {
        return true;
    }

    if (m_coins-price<0)
    {
        return false;
    }
    m_coins = m_coins-price;
    return true;
}

int Player::getAttackStrength() const
{
    return m_force + m_level;
}


std::ostream& operator<<(std::ostream& os, const Player& player)
{
    printPlayerDetails(os, player.m_name, player.getJob(), player.m_level,
                         player.m_force, player.getHP(), player.m_coins); //TODO: change to getHP TODO: how to get the name of the class?

    return os;                   
} 

int Player::getHP() const
{
    return m_HP;
}

