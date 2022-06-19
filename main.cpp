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
#include <vector>
#include "Cards/Gang.h"

int main()
{
    vector<BattleCard*> battleCards;
    battleCards.push_back(new Goblin);
    battleCards.push_back(new Goblin);
    battleCards.push_back(new Goblin);
    Gang gang(battleCards);
    
    Wizard wizard("wizi");
    gang.applyEncounter(wizard);

    cout << wizard << endl;

}

