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

float HumanPlayer::bet(float ante) {
    // Prompt the user for how much they'd like to bet,
    // ensuring it's within their bettable limit
    float betAmt = -1;
    while (betAmt <= ante || betAmt > getMoney()) {
        cout << "Bet amount: ( "
            << ante << " - "
            << getMoney() << " ): ";
        cin >> betAmt;

        // Round off to nearest penny
        betAmt = ceil(betAmt*100.0) / 100.0;
    }

    removeMoney(betAmt);
    return betAmt;
}
