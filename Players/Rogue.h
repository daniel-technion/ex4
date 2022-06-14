#ifndef EX4_Rogue_H
#define EX4_Rogue_H

#include "Player.h"

class Rogue : public Player
{
    public:
    Rogue(const string& name);
    void addCoins(int coinsToAdd) override;
    string getJob() const;
};

#endif