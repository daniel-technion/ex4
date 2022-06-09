#include "Card.h"

class Treasure : public Card
{
    public:
    Treasure() = default;
    void applyEncounter() const override;

    private:
    const static int COINS_PRIZE = 10;
};