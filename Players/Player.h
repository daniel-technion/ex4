#ifndef EX4_Player_H
#define EX4_Player_H

#include <string>

using namespace std; //TODO: is there a problem with using 'using'? 


class Player {
    public:

    /**
     * @brief Construct a new Player object 
     * 
     * @param name name of the player 
     */
    Player(const string& name); 

    /*
    the following are default because we are leaning on the string class d'tor + copy c'tor + assigment operator 
    to take care of the allocations and deletings.
     */
    ~Player() = default;
    Player(const Player& player) = default;
    Player& operator=(const Player& player) = default;

    /**
     * @brief raise the level of the player by one.
     *  if the player has already reached MAX_LEVEL, nothing will happen
     */
    void levelUp();

    /**
     * @brief raise the force of the player by the given argument 
     * 
     * @param buffBy - the number to raise the force by. must be a non-negative integer.
     */
    void buff(int buffBy);

    /**
     * @brief raise the Health Points (HP) of the player by the number given as an argument and
     *  not beyond it's maxHP
     * 
     * @param healBy - the number of point to add to HP. must be a non-negative integer.
     */
    virtual void heal(int healBy);

    /**
     * @brief decrease the HP of the player by the number given as an argument, not beyond 0
     * 
     * @param damageBy the number to substract from HP
     */
    void damage(int damageBy);

    /**
     * @brief check if the player's HP amount has reached 0
     * 
     * @return true if current Hp level is minimum
     * @return false else
     */
    bool isKnockedOut() const;

    /**
     * @brief check if the player has reached max level
     * 
     * @return true if player is in max level
     * @return false if not
     */
    bool isWinner() const;
    
    /**
     * @brief raise the player's coins amount by the number given as an argument
     * 
     * @param coinsToAdd the number of coins to add to the player
     */
    virtual void addCoins(int coinsToAdd);

    /**
     * @brief check if the player has enough coins to pay the price given as an argument
     * and if he does, reduce it's coins value by the price
     * 
     * @param price the price the player needs to pay
     * 
     * @return true if the payment succseed (the player had enough coins or if price<=0)
     * @return false if the payment failed (the player don't have enough coins and nothing happened)
     */
    bool pay(int price);

    /**
     * @brief Get the Attack Strength of the player (equals to it's level+force)
     * 
     * @return int - player's attack strength
     */
    virtual int getAttackStrength() const;

    /**
     * @brief get the current HP level of the player
     * 
     * @return int 
     */
    int getHP() const;

    /**
     * @brief print player's details
     * 
     * @param os 
     * @param healthPoints 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    /**
     * @brief return a string with tha name of the class of the object
     * 
     * @return string 
     */
    virtual string getJob() const = 0;

    /**
     * @brief damage the force of the player by the given amount
     * 
     * @param weakenBy 
     */
    void weaken(int weakenBy);

    /**
     * @brief lower the hp of the player to minimum
     * 
     */
    void knockOut();

    /**
     * @brief Get the Name of the player
     * 
     * @return string 
     */
    string getName();

    /**
     * @brief Get the amount of coins of the player
     * 
     * @return int 
     */
    int getCoins();

    const static int MAX_LEVEL = 10;

    protected:
    string m_name;
    int m_force; //initialized default = 5 
    int m_level; //initialized always = 1
    int m_coins; //initialized default = 10
    int m_HP;
    int m_maxHP;

    const static int DEFAULT_FORCE = 5;
    const static int INITIALIZE_LEVEL = 1;
    const static int INITIALIZE_COINS = 10;
    const static int DEFAULT_MAX_HP=100; 
    const static int MIN_HP=0;

};


#endif //EX2_Player_H