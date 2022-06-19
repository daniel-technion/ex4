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
#include "Exception.h"

int main()
{

    Wizard wizard("wizi");
    for (int i=0; i<8; i++)
    {
        wizard.levelUp();
    }
    cout << wizard << endl;
    cout << wizard.isWinner() << endl;

}

