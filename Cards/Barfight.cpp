#include "Barfight.h"
#include "/home/daniel.pe/ex4/Players/Fighter.h"
#include "/home/daniel.pe/ex4/utilities.h"

string Barfight::getName() const
{
    return "Barfight";
}

void Barfight::applyEncounter(Player& player) const
{
    Player *ptr = &player;
    const Fighter* fighter = dynamic_cast<const Fighter*>(ptr);
    if (fighter==nullptr)
    {
        player.damage(HP_LOSS_VALUE); 
        printBarfightMessage(false);
    } else
    {
        printBarfightMessage(true);
    }
}
