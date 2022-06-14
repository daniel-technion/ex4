#include "Cards/Card.h"
#include "Players/Rouge.h"
#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Cards/Goblin.h"
#include <iostream>

int main()
{
    Rouge rouge("im a Rouge");
    //Fighter fighter("im a fighter");
    Wizard wizard("im a wizard");
    Fighter fighter("ima fighhter");

    //wizard.buff(30);
    Vampire vampire;
    Goblin goblin;
    Dragon dragon;
    cout << wizard << endl;
    vampire.applyEncounter(wizard);
    cout << wizard << endl;
    goblin.applyEncounter(wizard);
    cout << wizard << endl;
    //cout << rouge << endl;
    //cout << fighter << endl;
}

