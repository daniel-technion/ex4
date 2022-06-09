#include "Card.h"

class Pitfall : Card
{
    public:
    Pitfall() = default;
    void applyEncounter() const override;

    private:
    const static int HP_LOSS_VALUE = 10;  
};