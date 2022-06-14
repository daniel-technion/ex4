#include "Cards/Card.h"
#include "Players/Rouge.h"
#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include <iostream>

int main()
{
    Rouge rouge("im a Rouge");
    //Fighter fighter("im a fighter");
    Wizard wizard("im a wizard");
    Fighter fighter("ima fighhter");
    
    cout << wizard << endl;
    cout << rouge << endl;
    cout << fighter << endl;
}

