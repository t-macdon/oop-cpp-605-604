#include <iostream>
#include <string>
#include <cmath>
#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(string name, float money) :
    Player{name, money}
{
    ;
}

float HumanPlayer::bet() {
    // Prompt the user for how much they'd like to bet,
    // ensuring it's within their bettable limit
    float betAmt = -1;
    while (betAmt <= 0 || betAmt > getMoney()) {
        cout << "Bet amount: (0.00 - "
            << getMoney() << " ): ";
        cin >> betAmt;

        // Round off to nearest penny
        betAmt = ceil(betAmt*100.0) / 100.0;
    }

    removeMoney(betAmt);
    return betAmt;
}
