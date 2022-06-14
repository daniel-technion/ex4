#ifndef EX4_Fighter_H
#define EX4_Fighter_H

#include "Player.h"

class Fighter : public Player
{
    public:
    Fighter(const string& name);
    int getAttackStrength() const override;
    string getJob() const;
};

#endif