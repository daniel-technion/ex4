#ifndef EX4_Merchant_H
#define EX4_Merchant_H


#include "Card.h"

class Merchant : public Card
{
    public:
    Merchant()= default;
    void applyEncounter(Player& player) const override;

    private:
    const static int hpPrice = 5;
    const static int hpSup = 1;
    const static int hpCode = 1;
    const static int forcePrice = 10;
    const static int forceSup = 1;
    const static int forceCode = 2;
    const static int noneCode = 0;
};

#endif