#include "Fairy.h"
#include "../utilities.h"

using namespace std;

string Fairy::getName() const
{
    return "Fairy";
}


void Fairy::applyEncounter(Player& player) const
{
    Player* ptr = &player;
    const Wizard* wizard = dynamic_cast<const Wizard*>(ptr);
    if (wizard != nullptr)
    {
        player.heal(HP_PRIZE); 
        printFairyMessage(true);
    } else
    {
        printFairyMessage(false);
    }
}