#include "Merchant.h"
#include "/home/daniel.pe/ex4/utilities.h"
#include <iostream>
#include <string>

string Merchant::getName() const
{
    return "Merchant";
}

void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    string input = "";
    std::getline (std::cin,input);
     while (!validateInput(input))
     {
        printInvalidInput();
        std::getline (std::cin,input);     
    }
    int requestedProduct = stoi(input);

    switch(requestedProduct)
    {
        case HP_CODE:
            if (player.pay(HP_PRICE))
            {
                player.heal(HP_AMOUNT);
                printMerchantSummary(std::cout, player.getName(), HP_CODE, HP_PRICE);
            } else
            {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getName(), NONE_CODE, NONE_CODE);
            }
            break;
        case FORCE_CODE:
            if (player.pay(FORCE_PRICE))
            {
                player.buff(FORCE_AMOUNT);
                printMerchantSummary(std::cout, player.getName(), FORCE_CODE, FORCE_PRICE);
            } else
            {
               printMerchantInsufficientCoins(std::cout); 
               printMerchantSummary(std::cout, player.getName(), NONE_CODE, NONE_CODE);
            }
            break;
        case NONE_CODE:
            printMerchantSummary(std::cout, player.getName(), NONE_CODE, NONE_CODE);
            break;
    }
}

bool Merchant::validateInput(string input)
{
    int n;
    try
    {
        n = std::stoi(input);
    } catch (...)
    {
        cout << "stoi failed";
        return false;
    }
    if((n != HP_CODE) && (n != FORCE_CODE) && (n != NONE_CODE))
    {
        return false;
    }
    return true;
}