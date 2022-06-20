#ifndef EX4_Wizard_H
#define EX4_Wizard_H

#include "Player.h"

class Wizard : public Player
{
    public:
    /**
     * @brief Construct a new Wizard object
     * 
     * @param name 
     */
    Wizard(const string& name);

    /**
     * @brief Destroy the Wizard object
     * 
     */
    ~Wizard() = default;

    /**
     * @brief Default Copy Constructor
     * 
     * @param wizard 
     */
    Wizard(const Wizard& wizard) = default;

    /**
     * @brief Default Assigment Operator
     * 
     * @param wizard 
     * @return Wizard& 
     */
    Wizard& operator=(const Wizard& wizard) = default;
    
    void heal(int healBy) override;
    string getJob() const override;
};

#endif