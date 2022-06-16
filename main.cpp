#include "Cards/Card.h"
#include "Players/Rogue.h"
#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Cards/Goblin.h"
#include <iostream>
#include "Cards/Pitfall.h"
#include "Cards/Barfight.h"
#include "Cards/Fairy.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"

int main()
{
    //Fighter fighter("im a fighter");
    Wizard wizard("im a wizard");
    Fighter fighter("ima fighter");
    Rogue rogue("im a rogue");

    //wizard.buff(30);
    Pitfall pitfall;
    Barfight barfight;
    Fairy fairy;
    Treasure treasure;
    Merchant merchant;
    Dragon dragon;
    Vampire vampire;
    Goblin goblin;
    //wizard.damage(100);
    //fighter.damage(100);
    treasure.applyEncounter(rogue);
    //pitfall.applyEncounter(fighter);
    //fairy.applyEncounter(fighter);
    //cout << wizard << endl;
    //cout << fighter << endl;
    //cout << fighter << endl;
    //cout << merchant;
    //cout << dragon;
    //cout << goblin;
    //cout << vampire;
}

