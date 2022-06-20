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
#include "utilities.h"
#include <limits>

bool validatePlayerNameInput(string input)
{
    bool isOnlyLetters = true;
    for(unsigned int i = 0; i < input.size(); i++)
    {
        if (!isalpha(input[i]))
        {
            isOnlyLetters = false;
        }
    }
    bool isLengthValid = false;
    if (input.length() <= 15)
    {
        isLengthValid = true;
    }
    if(isOnlyLetters && isLengthValid)
    {
        return true;
    }
    return false;
}

bool validatePlayerTypeInput(string input)
{
    if((input != "Rogue") && (input != "Wizard") && (input != "Fighter"))
    {
        return false;
    }
    return true;
}

bool validateTeamSizeInput(string input)
{
    int n;
    try
    {
        n = std::stoi(input);
    }
    catch(const std::exception& e)
    {
        return false;
    }  
    if(n>6 || n<2)
    {
        return false;
    }
    return true;
}

void doSomething()
{
    printStartGameMessage();
    printEnterTeamSizeMessage();
    string input = "";
    std::getline (std::cin,input);
     while (!validateTeamSizeInput(input))
     {
        printInvalidTeamSize();
        std::getline (std::cin,input);     
    }
    int numberOfPlayers=stoi(input);

    for (int i=0; i<numberOfPlayers; i++)
    {
        string playerName = "";
        string playerType = "";
        printInsertPlayerMessage();
        cin >> playerName;
        while (!validatePlayerNameInput(playerName))
        {
            printInvalidName();
            cin >> playerName;
        }
        cin >> playerType;
        while (!validatePlayerTypeInput(playerType))
        {
            printInvalidClass();
            cin >> playerType;
        }
        //TODO: CREATE NEW PLAYER HERE
    }
}



int main()
{
    /*
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
    */

   doSomething();
   //cout << validatePlayerTypeInput("daniel5") <<endl ;
   //cout << validatePlayerNameInput("daniel") <<endl ;

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
    while(game.isGameOver()==False)
    {
        try
        {
            playRound();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    */
}

