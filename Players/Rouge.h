#ifndef EX4_Rouge_H
#define EX4_Rouge_H

#include "Player.h"

class Rouge : public Player
{
    public:
    Rouge(const string& name);
    void addCoins(int coinsToAdd) override;
    string getJob() const;
};

#endif