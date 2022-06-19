#include <fstream>
#include <queue>
#include <iostream> // temp

#include "Cards/Card.h"
#include "Players/Rogue.h"
#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Cards/Goblin.h"
#include "Cards/Pitfall.h"
#include "Cards/Barfight.h"
#include "Cards/Fairy.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
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

queue<Card*> stringToCard(queue<string> names)
{
    queue<Card*> deck;
    for(unsigned int i=0; i<names.size(); ++i)
    {
        deck.push(new Fairy());
    }
    return deck;
}

int main()
{
    queue<string> lines = linesToQueue("deck.txt");
    /*
    int i = 0;
    while(0 < lines.size())
    {
        lines.pop();
        cout << i << endl;
        i++;
    }
    */
    queue<Card*> deck = stringToCard(lines);
    return 0;



}