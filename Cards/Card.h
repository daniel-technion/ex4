#ifndef EX4_CARD_H
#define EX4_CARD_H


class Card
{
    public:
    Card() = default;
    ~Card() = default;
    Card(const Card& card) = default; 
    Card& operator=(const Card& card) = default;
    virtual Card* clone() const = 0;

    virtual void applyEncounter() const = 0;
};


#endif