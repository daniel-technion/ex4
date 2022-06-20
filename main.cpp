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
#include "Mtmchkin.h"


int main()
{
    //TODO: delete
    vector<unique_ptr<BattleCard>> battleCards;
    battleCards.push_back(unique_ptr<BattleCard> (new Goblin));
    battleCards.push_back(unique_ptr<BattleCard> (new Goblin));
    battleCards.push_back(unique_ptr<BattleCard> (new Dragon));
    Gang gang(battleCards);
    Gang newGang(battleCards);
    newGang = gang;

    
    Wizard wizard("wizi");
    gang.applyEncounter(wizard);

    cout << wizard << endl;
    

   /*
   try
   {
       Mtmchkin game("deck.txt");
   }
   catch(const std::exception& e)
   {
       std::cout << e.what() << '\n';
   }
    
   // operate game

   */
}

