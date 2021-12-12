/**
 * @file Player.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Interface file for the Player class
 * @version 0.1
 * @date 2021-12-10
 * @copyright Copyright (c) 2021
 */

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include "Card.h"
#include "Hand.h"

class Player {
public:

    /**
     * @brief Construct a new Player object
     * 
     * @param name The text name of the player
     * @param money The amount of money to start with
     */
    Player(std::string name, float money);

    /**
     * @brief Puts the card into the Player's hand
     * 
     * @param card Card from Deck to put in Hand
     */
    void addCardToHand(Card &card);

    /**
     * @brief Clears this players hand
     * 
     */
    void resetHand();

    /**
     * @brief Get the Hand object
     * 
     * @return const Hand& This Player's Hand
     */
    const Hand &getHand() const { return hand; }

    /**
     * @brief 
     * 
     * @return int The size of the hand
     */
    int handSize() const { return hand.size(); }

    /**
     * @brief Places the specified amount of money in the pool
     * 
     * @param ante The minimum bet
     * @return float The total bet made
     */
    virtual float bet(float ante) = 0;

    /**
     * @brief Getter for money
     * 
     * @return float The amount of money this player has
     */
    float getMoney() const {return money;}

    /**
     * @brief Get the Name
     * 
     * @return std::string The text name of this Player 
     */
    std::string getName() const {return name;}

    /**
     * @brief Puts more money into this Player's total
     * 
     * @param money Amount of money to add
     */
    void addMoney(float money) { this->money += money; }

    /**
     * @brief Takes money from this Player's total
     * 
     * @param money Amount of money to subtract
     */
    void removeMoney(float money) { this->money -= money; }

private:

    /**
     * @brief This Player's hand
     * 
     */
    Hand hand;

    /**
     * @brief This Player's money
     * 
     */
    float money;

    /**
     * @brief This Player's name
     * 
     */
    std::string name;
};

#endif // _PLAYER_H_
