#include "Mtmchkin.h"
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
#include "utilities.h"

// maybe only card and player are needed



void Mtmchkin::playRound()
{
    if(m_activePlayers.size() == 0))
    {
        return;
    }
    Card* currentCard = m_deck.pop();
    Player* currentPlayer = m_activePlayers.pop();
    currentCard->applyEncounter(*currentPlayer);
    if(currentPlayer->isKnockedOut)
    {
        m_losers.push(currentPlayer);
    }
    else if(currentPlayer->atMaxLevel)// to do: add mimush
    {
        m_winners.push(currentPlayer);
    }
    else
    {
        m_activePlayers.push(currentPlayer);
    }
    deck.push(currentCard);
    m_moveCount++;
}

void Mtmchkin::printLeaderBoard() const
{
    int ranking = 1;
    printLeaderBoardStartMessage;
    for(vector<Player*>::const_iterator it = m_winners.begin(); it<m_winners.end(); ++it)
    {
        printLeaderBoard(ranking, **it);
        ranking++;
    }
    for(unsigned int i=0; i<m_activePlayers.size(); ++i)
    {
        printLeaderBoard(ranking, *m_activePlayers.front());
        m_activePlayers.push(m_activePlayers.pop());
        ranking++;
    }
    unsigned int i = m_losers.size() - 1;
    while(i>=0)
    {
        printLeaderBoard(ranking, *m_losers[i]);
        ranking++;
        i--;
    }

    
}

bool Mtmchkin::isGameOver() const
{
    return m_activePlayers.size();
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_moveCount;
}

