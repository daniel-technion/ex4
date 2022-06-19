#ifndef EX4_CARD_H
#define EX4_CARD_H

#include "../Players/Player.h"

class Card
{
    public:
    Card() = default;
    ~Card() = default;
    Card(const Card& card) = default; 
    Card& operator=(const Card& card) = default;
    
    virtual void applyEncounter(Player& player) const = 0;
    virtual string getName() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    virtual std::ostream& print(std::ostream& os) const;

};


#endif