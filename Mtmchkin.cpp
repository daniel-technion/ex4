#include "Mtmchkin.h"

using namespace std;

unique_ptr<BattleCard> Mtmchkin::stringToBattleCard(const string& name, int lineNumber)
{
    if(name == "Goblin")
    {
        unique_ptr<BattleCard> currentCard(new Goblin());
        return currentCard;
    }
    if(name == "Vampire")
    {
        unique_ptr<BattleCard> currentCard(new Vampire());
        return currentCard;
    }
    if (name == "Dragon")
    {
        unique_ptr<BattleCard> currentCard(new Dragon());
        return currentCard;
    }
    throw DeckFileFormatError(lineNumber+1); 
}

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


queue<unique_ptr<Card>> Mtmchkin::stringsToDeck(vector<string> names)
{
    queue<unique_ptr<Card>> deck;
    bool readingGang = false;
    vector<unique_ptr<BattleCard>> monsters;
    for(unsigned int i=0; i<names.size(); i++)
    {
        if(names[i] == "Gang" && !readingGang)
        {
            readingGang = true;
        }
        else if((names[i] == "Gang" && readingGang) || (names[i] == "EndGang" && !readingGang))
        {
            throw DeckFileFormatError(i+1);
        }
        else if(names[i] == "EndGang" && readingGang)
        {
            unique_ptr<Card> gang(new Gang(monsters));
            deck.push(move(gang));
            monsters.clear();
            readingGang = false;
        }
        else if(names[i] != "Gang" && names[i] != "EndGang" && readingGang)
        {
            unique_ptr<BattleCard> newCard = stringToBattleCard(names[i], i);
            monsters.push_back(move(stringToBattleCard(names[i], i)));
        }
        else if(names[i] != "Gang" && names[i] != "EndGang" && !readingGang)
        {
            if(stringToCard(names[i]) == nullptr)
            {
                throw DeckFileFormatError(i+1);
            }
            deck.push(move(stringToCard(names[i])));
        }
    }
    if (readingGang)
    {
        throw DeckFileFormatError(names.size()+1); 
    }
    if(deck.size() < MIN_DECK_SIZE) 
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
    if(n > MAX_TEAM_SIZE || n < MIN_TEAM_SIZE)
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
    if (input.length() <= MAX_NAME_LENGTH)
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

