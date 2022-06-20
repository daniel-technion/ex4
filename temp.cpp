#include <fstream>
#include <string>
#include <queue>
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

using std::cout; // temp
using std::endl;  // temp
using std::string;
using std::ifstream; 
using std::queue;


vector<string> linesToVector(string filename)
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

unique_ptr<Card> stringToCard(string name)
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

queue<unique_ptr<Card>> stringsToDeck(vector<string> names)
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
            deck.push(gang);
            monsters.clear();
            readingGang = false;
        }

        if(current_str == "EndGang" && !readingGang)
        {
            throw DeckFileFormatError(i);
        }

        if(current_str != "Gang" && current_str != "EndGang" && readingGang)
        {
            Card currentCard = stringToCard(current_str);
            const BattleCard* battleCard = dynamic_cast<const BattleCard*>(currentCard);
            if(battleCard == nullptr)
                throw DeckFileFormatError(i);
            BattleCard monster = static_cast<BattleCard>(stringToCard(names[i]));
            unique_ptr<BattleCard> monster_ptr(monster);
            monsters.push_back(monster_ptr);
        }

        if(current_str!= "Gang" && current_str != "EndGang" && !readingGang)
        {
            if(stringToCard(current_str) == nullptr)
                throw DeckFileFormatError(i);
            deck.push(stringToCard(current_str));

        }
    }
    if (readingGang)
    {
        throw DeckFileFormatError(names.size());
    }
    return deck;
}



int main()
{
    vector<string> lines = linesToVector("deck.txt");
    queue<unique_ptr<Card>> deck = stringsToDeck(lines);
    cout <<*(deck.front()) <<endl;
    return 0;
}
