#ifndef EX4_Fighter_H
#define EX4_Fighter_H

#include "Player.h"

class Fighter : public Player
{
    public:
    /**
     * @brief Construct a new Fighter object
     * 
     * @param name 
     */
    Fighter(const string& name);

    /**
     * @brief Destroy the Fighter object
     */
    ~Fighter() = default;

    /**
     * @brief Default Copy Constructor
     * 
     * @param fighter 
     */
    Fighter(const Fighter& fighter) = default;

    /**
     * @brief Default Assigment Opertor
     * 
     * @param fighter 
     * @return Fighter& 
     */
    Fighter& operator=(const Fighter& fighter) = default;

    int getAttackStrength() const override;
    string getJob() const override;
};

#endif