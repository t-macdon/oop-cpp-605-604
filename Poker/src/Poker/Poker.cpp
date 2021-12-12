#include <iostream>

#include "Dealer.h"

using namespace std;

// Low bid table, minimum amount of $1
const float ANTE_AMOUNT = 1;

int main() {
    Dealer dealer{ANTE_AMOUNT};

    cout << "Welcome to the table!" << endl
         << "The minimum bid is "
         << "$" << ANTE_AMOUNT
         << endl << endl;

    // dealer.promptForPlayers();
    // Statically set up some players for test
    dealer.loadPlayer("Michael", 25.00, false);
    dealer.loadPlayer("CPU1", 25.00, true);
    dealer.loadPlayer("CPU2", 25.00, true);

    while(dealer.readyToPlay()) {
        dealer.playARound();
    }

}