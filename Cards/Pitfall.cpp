#include "Pitfall.h"
#include "../Players/Rogue.h"
#include "../utilities.h"

using namespace std; 

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
        printPitfallMessage(false);
    } else
    {
        printPitfallMessage(true);
    }
}