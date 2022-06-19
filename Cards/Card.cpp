#include "Card.h"
#include "../utilities.h"

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.print(os);
    return os;
}

std::ostream& Card::print(std::ostream& os) const
{
    printCardDetails(os, getName());
    printEndOfCardDetails(os);
    return os;
}