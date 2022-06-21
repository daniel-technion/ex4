
#include "Mtmchkin.h"

int main()
{
   try
   {
       Mtmchkin game("deck.txt");
       while(game.isGameOver()== false)
       {
           game.playRound();
       }
   }
   catch(const std::exception& e)
   {
       std::cout << e.what() << '\n';
   }
    
}



