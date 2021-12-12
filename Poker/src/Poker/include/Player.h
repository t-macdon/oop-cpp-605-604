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

/**
 * @brief Abstract base class for a poker player
 * 
 */
class Player {
public:
    /**
     * @brief Construct a new Player object
     * 
     * @param name Name of the player
     * @param money Amount of money the player has
     */
    Player(std::string name, float money);

    /**
     * @brief Add a card to the hand of this player
     * 
     * @param card 
     */
    void addCardToHand(Card &card);

    /**
     * @brief Clear out this player's hand
     */
    void resetHand();

    /**
     * @brief Return a reference to this player's hand
     * 
     * @return const Hand& 
     */
    const Hand& getHand() const { return hand; }

    /**
     * @brief Count the number of cards in this player's hand
     * @return int 
     */
    int handSize() const { return hand.size(); }

    /**
     * @brief Template for the bet method
     * 
     * @param ante Minimum amount to bet
     * @return float Amount bet
     */
    virtual float bet(float ante) = 0;

    /**
     * @brief Return the amount of money this player has left
     * 
     * @return float 
     */
    float getMoney() const {return money;}

    /**
     * @brief Return the player's name
     * 
     * @return std::string 
     */
    std::string getName() const {return name;}

    /**
     * @brief Add money to this player's wallet
     * 
     * @param money 
     */
    void addMoney(float money) { this->money += money; }

    /**
     * @brief Remove money from this player's wallet
     * 
     * @param money 
     */
    void removeMoney(float money) { this->money -= money; }

private:
    Hand hand;
    float money;
    std::string name;
};

#endif // _PLAYER_H_
