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

    unique_ptr<Player> player1(new Fighter("israel"));
    unique_ptr<Player> player2(new Rogue("usa"));
    m_activePlayers.push_back(move(player1));
    m_activePlayers.push_back(move(player2));
}

void Mtmchkin::playRound()
{
    if(m_activePlayers.size() == 0)
    {
        return;
    }
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
    m_moveCount++;
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
    for(vector<unique_ptr<Player>>::const_reverse_iterator it = m_losers.crbegin(); it != m_winners.crend(); ++it)
    {
        printPlayerLeaderBoard(ranking, **it);
        ranking++;
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

void Mtmchkin::playersInitialization()
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

bool Mtmchkin::validatePlayerNameInput(string input)
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

