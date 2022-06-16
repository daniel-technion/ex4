#include "Fairy.h"
#include "/home/daniel.pe/ex4/utilities.h"

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