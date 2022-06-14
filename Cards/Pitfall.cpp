#include "Pitfall.h"
#include "/home/daniel.pe/ex4/Players/Rogue.h"

string Pitfall::getName() const
{
    return "Pitfall";
}

void Pitfall::applyEncounter(Player& player) const
{
    Player* ptr = &player;
    const Rogue* rogue = dynamic_cast<const Rogue*>(ptr);
    if (rogue == nullptr)
    {
        player.damage(HP_LOSS_VALUE); 
    }
}