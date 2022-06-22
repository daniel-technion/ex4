#ifndef EX4_Rogue_H
#define EX4_Rogue_H

#include "Player.h"

class Rogue : public Player
{
    public:
    /**
     * @brief Construct a new Rogue object
     * 
     * @param name 
     */
    Rogue(const std::string& name);

    /**
     * @brief Default Copy Constructor
     * 
     * @param rogue 
     */
    Rogue(const Rogue& rogue) = default;

    /**
     * @brief Default Assigment Operator
     * 
     * @param rogue 
     * @return Rogue& 
     */
    Rogue& operator=(const Rogue& rogue) = default;
    
    void addCoins(int coinsToAdd) override;
    std::string getJob() const override;
};

#endif