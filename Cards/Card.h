#ifndef EX4_CARD_H
#define EX4_CARD_H

#include "/home/daniel.pe/ex4/Players/Player.h"

class Card
{
    public:
    Card() = default;
    ~Card() = default;
    Card(const Card& card) = default; 
    Card& operator=(const Card& card) = default;
    //virtual Card* clone() const = 0;

    virtual void applyEncounter(Player& player) const = 0;
    virtual string getName() const = 0;

};


#endif