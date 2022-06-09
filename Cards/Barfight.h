#include "Card.h"

class Barfight : public Card
{
    public:
    Barfight() = default;
    void applyEncounter() const override;

    private:
    static const int HP_LOSS_VALUE = 10;
};