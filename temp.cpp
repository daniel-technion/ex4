#include <fstream>
#include <queue>
#include <iostream> // temp

#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Cards/Goblin.h"
#include "Cards/Pitfall.h"
#include "Cards/Barfight.h"
#include "Cards/Fairy.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"


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

queue<card> stringToCard(queue<string> names)
{
    queue<card> deck;
    //for(int i=0; i<names.size)
    return deck
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
    queue<card> deck = stringToCard(lines);
    return 0;



}