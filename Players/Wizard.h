#ifndef EX4_Wizard_H
#define EX4_Wizard_H

#include "Player.h"

class Wizard : public Player
{
    public:
    Wizard(const string& name);
    void heal(int healBy) override;
    string getJob() const;
};

#endif