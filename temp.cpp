#include <fstream>
#include <string>
#include <queue>
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


queue<string> linesToQueue(string filename)
{
    queue<string> lines;
    string line;

    ifstream input_file(filename);

    while (getline(input_file, line))
    {
        lines.push(line);
    }
    return lines;
}

Card* stringToCard(string name)
{
    if(name == "Fairy")       return new Fairy();
    if(name == "Pitfall")     return new Pitfall();
    if(name == "Barfight")    return new Barfight();
    if(name == "Treasure")    return new Treasure();
    if(name == "Merchant")    return new Merchant();
    if(name == "Goblin")      return new Goblin();
    if(name == "Vampire")     return new Vampire();
    if(name == "Dragon")      return new Dragon();
    // default:            // TODO: throw not card
}

queue<Card*> stringsToDeck(queue<string> names)
{
    queue<Card*> deck;
    bool readingGang = false;
    vector<Card*> monsters;
    while(names.size() > 0)
    {
        string current_str = names.pop();
        if(current_str == "Gang" && !readingGang)
        {
            readingGang = true;
        }

        if(current_str == "Gang" && readingGang)
        {
            deck.push(new Gang(monsters));
            ~monsters;
            vector<Card*> monsters;
            readingGang = false;
        }

        if(current_str != "Gang" && readingGang)
        {
            monsters.push(stringToCard(current_str));
        }

        if(current_str!= "Gang" && !readingGang)
        {
            deck.push(stringToCard(current_str));
        }
    }
    if (readingGang)
    {
        // TODO: throww
    }
    return deck;
}



int main()
{
    queue<string> lines = linesToQueue("deck.txt");
    queue<Card*> deck = stringsToDeck());
    cout <<*(deck.front()) <<endl;
    return 0;
}
