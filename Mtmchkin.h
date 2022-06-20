#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <fstream>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <memory>
#include <iostream> // temp

#include "Cards/Card.h"
#include "Players/Player.h"
#include "Cards/Fairy.h"
#include "Players/Rogue.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Cards/Goblin.h"
#include "Cards/Pitfall.h"
#include "Cards/Barfight.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
#include "Cards/Gang.h"
#include "Exception.h"
#include "utilities.h"

using std::cout; // temp
using std::endl;  // temp
using std::string;
using std::ifstream; 
using std::queue;
using std::deque;
using std::vector;

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
   
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;


    private:
    deque<unique_ptr<Player>> m_activePlayers;
    vector<unique_ptr<Player>> m_winners;
    vector<unique_ptr<Player>> m_losers;
    queue<unique_ptr<Card>> m_deck;
    int m_moveCount = 0;

    static  deque<unique_ptr<Player>> playersInitialization();
    static bool validateTeamSizeInput(string input);
    static bool validatePlayerNameInput(string input);
    static bool validatePlayerTypeInput(string input);
    static unique_ptr<Player> stringToPlayer(string playerType, string playerName);
};

#endif /* MTMCHKIN_H_ */
