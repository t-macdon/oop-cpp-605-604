/**
 * @file Dealer.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation for the Dealer class
 * @version 0.1
 * @date 2021-12-02
 */

#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits>
#include <algorithm>

#include "Dealer.h"
#include "HumanPlayer.h"
#include "CPUPlayer.h"
#include "Player.h"

using namespace std;

Dealer::Dealer(float ante) : ante{ante}
{
    // Set up cout format as we'd like for money
    cout << fixed << setprecision(2);
}

bool Dealer::isHuman(Player *player)
{
    return (nullptr != dynamic_cast<HumanPlayer *>(player));
}

void Dealer::clearScreen()
{
    cout << string(25, '\n');
}

void Dealer::waitForInput()
{
    cout << "Press Enter key to continue" << endl;
    fflush(stdin);
    cin.sync();
    if (cin.gcount())
    {
        cin >> ws;
    }
    string tmp;
    getline(cin, tmp);
    // getch();
}

void Dealer::checkPockets()
{
    players.erase(
        remove_if(players.begin(), players.end(),
                  [this](const PlayerAndBet &p)
                  {
                      if (p.player->getMoney() < ante)
                      {
                          cout << p.player->getName()
                               << " doesn't have enough money."
                               << " Removing them from the table"
                               << endl;
                          return true;
                      }
                      return false;
                  }),
        players.end());
}

void Dealer::promptForPlayers()
{
    int numPlayers = 0;
    while (numPlayers < 2 || numPlayers > 7)
    {
        cout << "How many players will be joining? (2 - 7): ";
        cin >> numPlayers;
    }
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "PLAYER " << i + 1 << endl;
        char sel = '\0';
        while (tolower(sel) != 'n' && tolower(sel) != 'y')
        {
            cout << "\tIs player " << i + 1 << " a computer? (Y/N): ";
            cin >> sel;
        }

        string name;
        float money = -1;
        cout << "\tEnter player " << i + 1 << "'s name: ";
        cin >> name;

        while (money <= 0)
        {
            cout << "\tEnter player " << i + 1 << "'s money: ";
            cin >> money;

            // Round off to nearest penny
            money = ceil(money * 100.0) / 100.0;
        }

        // Load a CPU or Human player with these attributes
        loadPlayer(name, money, sel == 'y');
        cout << endl;
    }
}

void Dealer::loadPlayer(string name, float money, bool cpu)
{
    if (cpu)
    {
        players.push_back({new CPUPlayer{name, money}, 0.00});
    }
    else
    {
        players.push_back({new HumanPlayer{name, money}, 0.00});
    }
}

void Dealer::openAndShuffleANewDeck(int shuffleSeed)
{
    deck = Deck();
    // If shuffleSeed is non-zero, use that value
    if (shuffleSeed != 0)
    {
        deck.shuffle(shuffleSeed);
    }
    // Otherwise, let shuffle give us a random seed
    else
    {
        deck.shuffle();
    }
}

void Dealer::dealCardsToPlayers()
{
    // Deal 5 cards to each player
    for (int i = 0; i < 5; i++)
    {
        for (auto &p : players)
        {
            Card c = deck.draw();
            p.player->addCardToHand(c);
        }
    }
}

void Dealer::promptForBets()
{
    clearScreen();
    for (auto &p : players)
    {
        // Show the human players their hand before they place a bet
        if (isHuman(p.player))
        {
            Hand hand = p.player->getHand();
            clearScreen();
            cout << p.player->getName() << "'s Turn!" << endl;
            waitForInput();
            cout << hand << ": " << hand.categoryAsString() << endl;
        }
        auto bet = p.player->bet(ante);

        // If someone entered a 0 we have a runtime error
        // They either don't have enough money or otherwise
        // broke our logic checks somewhere.
        // Either way, game over.
        if (bet == 0)
        {
            throw runtime_error("Someone's out of cash!");
        }
        p.bet = bet;
    }
}

bool Dealer::readyToPlay()
{
    bool ready = true;

    // Make sure the players each have enough money
    checkPockets();

    // Make sure we have the right number of players
    ready &= (players.size() >= 2 && players.size() <= 7);

    return ready;
}

void Dealer::showdown()
{
    clearScreen();
    cout << "Showdown!" << endl;
    waitForInput();
    for (const auto &p : players)
    {
        Hand hand = p.player->getHand();
        cout << p.player->getName() << endl;
        cout << '\t' << hand << ": " << hand.categoryAsString() << endl;
        cout << '\t' << "Bet: $" << p.bet
             << ", Remaining: $" << p.player->getMoney()
             << endl;
    }
}

void Dealer::determineWinner()
{
    clearScreen();
    cout << endl
         << "And the winner is..." << endl;
    waitForInput();

    // Find the winner's hand
    Player *winner = players.front().player;
    for (const auto &p : players)
    {
        if (p.player->getHand() > winner->getHand())
        {
            winner = p.player;
        }
    }

    cout << "Winner: " << winner->getName() << "!" << endl;
    cout << '\t' << winner->getHand()
         << ": " << winner->getHand().categoryAsString()
         << endl;

    // Dump pot in to the winner's pockets
    float pot = 0;
    for (const auto &p : players)
    {
        pot += p.bet;
    }

    winner->addMoney(pot);
}

void Dealer::showPlayers()
{
    clearScreen();
    for (const auto &p : players)
    {
        cout << p.player->getName() << " : "
             << "$" << p.player->getMoney()
             << endl;
    }
    waitForInput();
}

void Dealer::playARound()
{
    showPlayers();
    openAndShuffleANewDeck();
    dealCardsToPlayers();
    promptForBets();
    showdown();
    determineWinner();
}