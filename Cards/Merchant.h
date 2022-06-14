#ifndef EX4_Merchant_H
#define EX4_Merchant_H


#include "Card.h"

class Merchant : public Card
{
    public:
    Merchant()= default;
    void applyEncounter(Player& player) const override;
    string getName() const override;

    private:
    const static int HP_PRICE = 5;
    const static int HP_AMOUNT = 1;
    const static int HP_CODE = 1;
    const static int FORCE_PRICE = 10;
    const static int FORCE_AMOUNT = 1;
    const static int FORCE_CODE = 2;
    const static int NONE_CODE = 0;

    static bool validateInput(string input);
};

#endif