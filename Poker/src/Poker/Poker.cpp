#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#include "Player.h"
#include "CPUPlayer.h"
#include "HumanPlayer.h"
#include "Card.h"
#include "Deck.h"

using namespace std;

void clearScreen() {
    cout << string(25, '\n');
}

// TODO: This needs to actually work in all cases, not just some
void pressAnyKeyToContinue() {
    cout << "Press any key to continue" << endl;
    getchar();
}

bool isHuman(Player* player) {
    return (nullptr != dynamic_cast<HumanPlayer*>(player));
}

vector<Player*> promptForPlayers() {
    int numPlayers = 0;
    vector<Player*> players;
    while (numPlayers < 2 || numPlayers > 7) {
        cout << "How many players will be joining? (2 - 7): ";
        cin >> numPlayers;
    }
    for(int i = 0; i < numPlayers; i++) {
        char sel = '\0';
        while (tolower(sel) != 'n' && tolower(sel) != 'y') {
            cout << "Is player " << i+1 << " a computer? (Y/N): ";
            cin >> sel;
        }

        string name;
        float money = -1;
        cout << "Enter player " << i+1 << "'s name: ";
        cin >> name;

        while (money <= 0) {
            cout << "Enter player " << i+1 << "'s money: ";
            cin >> money;

            // Round off to nearest penny
            money = ceil(money*100.0) / 100.0;
        }

        // Create a CPU Player with these attributes
        if (sel == 'y') {
            players.push_back(new CPUPlayer{name, money});
        }
        else {
            players.push_back(new HumanPlayer{name, money});
        }
    }

    return players;
}

int main() {
    Deck d;

    // Replace this with an actual random call,
    // Or make a shuffle variant that takes no-args
    d.shuffle(1);

    auto players = promptForPlayers();
    
    // Game plays until player quits
    while(true) {
        clearScreen();
        for(auto p: players) {
            cout << p->getName() << " : " << p->getMoney() << endl;
        }
        cout << endl;

        cout << "Dealing Cards..." << endl;
        pressAnyKeyToContinue();

        float pot = 0;
        vector<float> bets;
        // Deal 5 cards to each player
        for(int i = 0; i < 5; i++) {
            for(auto p : players) {
                Card c = d.draw();
                p->addCardToHand(c);
            }
        }
        
        // Iterate over each player.
        // If they're a human, let them see their hand,
        // then have them bet.
        for(auto p: players) {
            if (isHuman(p)) {
                Hand hand = p->getHand();
                clearScreen();
                cout << p->getName() << "'s Turn!" << endl;
                pressAnyKeyToContinue();
                cout << hand << ": " << hand.categoryAsString() << endl;
            }
            auto bet = p->bet();
            bets.push_back(bet);
            pot += bet;
        }
        
        // Show all hands for review
        clearScreen();
        cout << "Showdown!" << endl;
        pressAnyKeyToContinue();
        for(size_t i = 0; i < players.size(); i++) {
            auto p = players.at(i);
            Hand hand = p->getHand();
            cout << p->getName() << endl;
            cout << '\t' << hand << ": " << hand.categoryAsString() << endl;
            cout << '\t' << "Bet: " << bets.at(i) << ", Remaining: " << p->getMoney() << endl;
            cout << endl;
        }

        cout << "Pot: " << pot << endl;
        
        // Find the winner's hand
        int winnerIndex = 0;
        for(size_t i = 0; i < players.size(); i++) {
            if (players[i]->getHand() > players[winnerIndex]->getHand()) {
                winnerIndex = i;
            }
        }

        Player* winner = players.at(winnerIndex);
        Hand winningHand = players[winnerIndex]->getHand();
        cout << "Winner:" << endl;
        cout << '\t' << winner->getName() << endl;
        cout << '\t' << winningHand << ": " << winningHand.categoryAsString() << endl;
        winner->addMoney(pot);

        // Remove any players who are out of money (Have less than $1)
        // TODO: Could add a minimum ante to bet prototype
        players.erase(
            remove_if(players.begin(), players.end(),
                [](const auto& player) { 
                    return player->getMoney() < 1;
                }), players.end());

        char sel = '\0';
        while (tolower(sel) != 'n' && tolower(sel) != 'y') {
            cout << "Play Again? (Y/N): ";
            cin >> sel;
        }
        if (sel == 'n') {
            return 0;
        }
    }
}