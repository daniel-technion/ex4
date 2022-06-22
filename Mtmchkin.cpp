#include "Mtmchkin.h"

static vector<string> linesToVector(string filename)
{
    printStartGameMessage();
    vector<string> lines;
    string line;
    ifstream input_file(filename);
    if (!input_file)
    {
        throw DeckFileNotFound();
    }
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
        else if(current_str == "Gang" && readingGang)
        {
            throw DeckFileFormatError(i+1);
        }

        else if(current_str == "EndGang" && readingGang)
        {
            unique_ptr<Card> gang(new Gang(move(monsters)));
            deck.push(move(gang));
            monsters.clear();
            readingGang = false;
        }

        else if(current_str == "EndGang" && !readingGang)
        {
            throw DeckFileFormatError(i+1);
        }

        else if(current_str != "Gang" && current_str != "EndGang" && readingGang)
        {
            if(names[i] != "Goblin" && names[i] != "Vampire" && names[i] != "Dragon")
            {
                throw DeckFileFormatError(i+1);
            }
            if(names[i] == "Goblin")
            {
                unique_ptr<BattleCard> currentCard(new Goblin());
                monsters.push_back(move(currentCard));
            }
            if(names[i] == "Vampire")
            {
                unique_ptr<BattleCard> currentCard(new Vampire());
                monsters.push_back(move(currentCard));
            }
            if(names[i] == "Dragon")
            {
                unique_ptr<BattleCard> currentCard(new Dragon());
                monsters.push_back(move(currentCard));
            }
        }

        else if(current_str!= "Gang" && current_str != "EndGang" && !readingGang)
        {
            if(stringToCard(current_str) == nullptr)
            {
                throw DeckFileFormatError(i+1);
            }
            deck.push(move(stringToCard(current_str)));
        }
    }
    if (readingGang)
    {
        throw DeckFileFormatError(names.size()); //TODO: +1???????
    }
    if(deck.size() < 5) //TODO: CHANGE TO STATIC
    {
        throw DeckFileInvalidSize();
    }
    return deck;
}

Mtmchkin::Mtmchkin(const std::string fileName) : m_deck(stringsToDeck(linesToVector(fileName))),
                                                 m_activePlayers(playersInitialization())
                                                                                         
{}

void Mtmchkin::playRound()
{
    m_roundSize = m_activePlayers.size();
    printRoundStartMessage(++m_roundCount);
    while(m_roundSize != 0)
    {
        printTurnStartMessage(m_activePlayers.front()->getName());
        unique_ptr<Card> currentCard(move(m_deck.front()));
        m_deck.pop();
        unique_ptr<Player> currentPlayer(move(m_activePlayers.front()));
        m_activePlayers.pop_front();
        currentCard->applyEncounter(*currentPlayer);
        if(currentPlayer->isKnockedOut())
        {
            m_losers.push_back(move(currentPlayer));
        }
        else if(currentPlayer->isWinner())
        {
            m_winners.push_back(move(currentPlayer));
        }
        else
        {
            m_activePlayers.push_back(move(currentPlayer));
        }
        m_deck.push(move(currentCard));
        m_roundSize--;
    }
    m_moveCount++;
    if (isGameOver())
    {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    int ranking = 1;
    printLeaderBoardStartMessage();
    for(vector<unique_ptr<Player>>::const_iterator it = m_winners.cbegin(); it != m_winners.cend(); ++it)
    {
        printPlayerLeaderBoard(ranking, **it);
        ranking++;
    }
    for(deque<unique_ptr<Player>>::const_iterator it = m_activePlayers.cbegin(); it != m_activePlayers.cend(); ++it)
    {
        printPlayerLeaderBoard(ranking, **it);
        ranking++;
    }
    for(vector<unique_ptr<Player>>::const_reverse_iterator it = m_losers.crbegin(); it != m_losers.crend(); ++it)
    {
        printPlayerLeaderBoard(ranking, **it);
        ranking++;
    }     
} 

bool Mtmchkin::isGameOver() const
{
    if(m_activePlayers.size()>0)
    {
        return false;
    }
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_moveCount;
}

deque<unique_ptr<Player>> Mtmchkin::playersInitialization()
{
    deque<unique_ptr<Player>> players;
    printEnterTeamSizeMessage();
    string input;
    std::getline (std::cin,input);
    while (!validateTeamSizeInput(input))
    {
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        std::getline (std::cin,input);     
    }
    
    int numberOfPlayers=stoi(input);
    for (int i=0; i<numberOfPlayers; i++)
    {
        printInsertPlayerMessage();
        std::getline (std::cin,input);
        int pos = input.find(" ");
        string playerName = input.substr(0 , pos); 
        string playerType = input.substr(pos + 1);
        while (!validateNameInput(playerName) || !validatePlayerTypeInput(playerType))
        {
            if(!validateNameInput(playerName))
            {
                printInvalidName();
            } else 
            {
                printInvalidClass();
            }
            std::getline (std::cin,input);
            int pos = input.find(" ");
            playerName = input.substr(0 , pos); 
            playerType = input.substr(pos + 1);
        }
        players.push_back(move(stringToPlayer(playerType, playerName)));
    }
    return players;
}

bool Mtmchkin::validateTeamSizeInput(string input)
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

bool Mtmchkin::validateNameInput(string input)
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

bool Mtmchkin::validatePlayerTypeInput(string input)
{
    if((input != "Rogue") && (input != "Wizard") && (input != "Fighter"))
    {
        return false;
    }
    return true;
}

unique_ptr<Player> Mtmchkin::stringToPlayer(string playerType, string playerName)
{
    if(playerType == "Wizard")
    {
        unique_ptr<Player> player(new Wizard(playerName));
        return player;
    }
     if(playerType == "Rogue")
    {
        unique_ptr<Player> player(new Rogue(playerName));
        return player;
    }
     if(playerType == "Fighter")
    {
        unique_ptr<Player> player(new Fighter(playerName));
        return player;
    }
    return unique_ptr<Player>(nullptr);
}

