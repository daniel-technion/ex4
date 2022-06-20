#include "Mtmchkin.h"

static vector<string> linesToVector(string filename)
{
    vector<string> lines;
    string line;

    ifstream input_file(filename);

    while (getline(input_file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

static unique_ptr<Card> stringToCard(string name)
{
    if(name == "Fairy")
    {
        unique_ptr<Card> card(new Fairy());
        return card;
    }
    if(name == "Pitfall")   
    {
        unique_ptr<Card> card(new Pitfall());
        return card;
    }
    if(name == "Barfight")  
    {
        unique_ptr<Card> card(new Barfight());
        return card;
    }  
    if(name == "Treasure")   
    {
        unique_ptr<Card> card(new Treasure());
        return card;
    } 
    if(name == "Merchant")  
    {
        unique_ptr<Card> card(new Merchant());
        return card;
    }
    if(name == "Goblin")  
    {
        unique_ptr<Card> card(new Goblin());
        return card;
    }  
    if(name == "Vampire")   
    {
        unique_ptr<Card> card(new Vampire());
        return card;
    }
    if(name == "Dragon")  
    {
        unique_ptr<Card> card(new Dragon());
        return card;
    }  
        unique_ptr<Card> card(nullptr);
        return card;
}


static queue<unique_ptr<Card>> stringsToDeck(vector<string> names)
{
    queue<unique_ptr<Card>> deck;
    bool readingGang = false;
    vector<unique_ptr<BattleCard>> monsters;
    for(unsigned int i=0; i<names.size(); i++)
    {
        string current_str = names[i];
        if(current_str == "Gang" && !readingGang)
        {
            readingGang = true;
        }

        if(current_str == "Gang" && readingGang)
        {
            throw DeckFileFormatError(i);
        }

        if(current_str == "EndGang" && readingGang)
        {
            unique_ptr<Card> gang(new Gang(monsters));
            deck.push(move(gang));
            monsters.clear();
            readingGang = false;
        }

        if(current_str == "EndGang" && !readingGang)
        {
            throw DeckFileFormatError(i);
        }

        if(current_str != "Gang" && current_str != "EndGang" && readingGang)
        {
            if(names[i] != "Goblin" && names[i] != "Vampire" && names[i] != "Dragon")
                throw DeckFileFormatError(i);
            if(names[i] == "Goblin")
            {
                unique_ptr<BattleCard> currentCard(new Goblin());
                monsters.push_back(move(currentCard));
            }
        }

        if(current_str!= "Gang" && current_str != "EndGang" && !readingGang)
        {
            if(stringToCard(current_str) == nullptr)
                throw DeckFileFormatError(i);
            deck.push(move(stringToCard(current_str)));

        }
    }
    if (readingGang)
    {
        throw DeckFileFormatError(names.size());
    }
    return deck;
}

Mtmchkin::Mtmchkin(const std::string fileName) : m_deck(stringsToDeck(linesToVector(fileName)))
{
    //vector<string> lines = linesToVector(fileName);
    //queue<unique_ptr<Card>> deck = stringsToDeck(lines);
    //cout <<*(deck.front()) <<endl;




}

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

