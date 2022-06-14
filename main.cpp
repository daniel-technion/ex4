#include "Cards/Card.h"
#include "Players/Rouge.h"
#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include <iostream>

int main()
{
    Player newPlayer("Daniel");
    Rouge rouge("im a Rouge");
    //Fighter fighter("im a fighter");
    Wizard wizard("im a wizard");
    
    cout << wizard << endl;
    cout << newPlayer << endl;
    newPlayer.damage(70);
    wizard.damage(70);
    cout << wizard << endl;
    cout << newPlayer << endl;
    newPlayer.heal(25);
    wizard.heal(25);
    cout << wizard << endl;
    cout << newPlayer << endl;
    
}

