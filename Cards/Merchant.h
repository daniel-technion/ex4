#ifndef EX4_Merchant_H
#define EX4_Merchant_H


#include "Card.h"

class Merchant : public Card
{
    public:
    /**
     * @brief Construct a new Merchant object
     */
    Merchant()= default;

    /**
     * @brief Default Copy Constructor
     * 
     * @param merchant 
     */
    Merchant(const Merchant& merchant) = default;

    /**
     * @brief Default Assigment Opertor
     * 
     * @param merchant 
     * @return Merchant& 
     */
    Merchant& operator=(const Merchant& merchant) = default;

    void applyEncounter(Player& player) const override;
    string getName() const override;

    private:
    /**
     * @brief the price of each product
     */
    const static int HP_PRICE = 5;
    const static int FORCE_PRICE = 10;

    /**
     * @brief the amount of the prodect given in exchange
     * 
     */
    const static int HP_AMOUNT = 1;
    const static int FORCE_AMOUNT = 1;

    /**
     * @brief the input related to each requested product
     * 
     */
    const static int HP_CODE = 1;
    const static int FORCE_CODE = 2;
    const static int NONE_CODE = 0;

    /**
     * @brief valudate the input from the user while interracting with the merchant
     * 
     * @param input 
     * @return true 
     * @return false 
     */
    static bool validateInput(string input);
};

#endif