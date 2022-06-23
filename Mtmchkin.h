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

    ~Mtmchkin() = default;
    Mtmchkin(const Mtmchkin& mtmchkin) = delete;
    Mtmchkin& operator=(const Mtmchkin& mtmchkin) = default;
   
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
    std::queue<std::unique_ptr<Card>> m_deck;
    std::deque<std::unique_ptr<Player>> m_activePlayers;
    std::vector<std::unique_ptr<Player>> m_winners;
    std::vector<std::unique_ptr<Player>> m_losers;
    int m_moveCount = 0;
    int m_roundCount = 0;
    int m_roundSize = 0;

    static const int MIN_DECK_SIZE = 5;
    static const int MIN_TEAM_SIZE = 2;
    static const int MAX_TEAM_SIZE = 6;
    static const int MAX_NAME_LENGTH = 15;
    static std::queue<std::unique_ptr<Card>> stringsToDeck(std::vector<std::string> names);
    static std::deque<std::unique_ptr<Player>> playersInitialization();
    static bool validateTeamSizeInput(std::string input);
    static bool validateNameInput(std::string input);
    static bool validatePlayerTypeInput(std::string input);
    static std::unique_ptr<Player> stringToPlayer(std::string playerType, std::string playerName);
    static std::unique_ptr<BattleCard> stringToBattleCard(const std::string& name, int lineNumber);
};

#endif /* MTMCHKIN_H_ */
