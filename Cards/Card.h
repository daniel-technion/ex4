#ifndef EX4_CARD_H
#define EX4_CARD_H

#include "../Players/Player.h"

class Card
{
    public:
    /**
     * @brief Construct a new Card object
     */
    Card() = default;

    /**
     * @brief Destroy the Card object
     */
    ~Card() = default;

    /**
     * @brief Default Copy Constructor
     * @param card 
     */
    Card(const Card& card) = default; 

    /**
     * @brief Default Assigment Opertor
     * @param card 
     * @return Card& 
     */
    Card& operator=(const Card& card) = default;
    
    /**
     * @brief Apply on the player the consequenstes of encountering the card
     * 
     * @param player 
     */
    virtual void applyEncounter(Player& player) const = 0;

    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    virtual string getName() const = 0;

    /**
     * @brief print the details of the card
     * 
     * @param os 
     * @param card 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    /**
     * @brief helper function for operator<< - used to be overriden to print diffrentky 
     * different types of card
     * 
     * @param os 
     * @return std::ostream& 
     */
    virtual std::ostream& print(std::ostream& os) const;

};


#endif