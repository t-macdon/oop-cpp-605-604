/**
 * @file main.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Driver for the PokerRanking module
 * @version 0.1
 * @date 2021-09-23
 */

#include <fstream>
#include <iostream>
#include <json/json.h>

using namespace std;

int main(int argc, char *argv[])
{
    // get the json filepath from args
    if (argc != 2)
    {
        cout << "Expected 1 argument to json filepath" << endl;
        return 1;
    }

    // save json filepath in string
    string jsonFilepath(argv[1]);

    // read in the json file
    Json::Value root;
    std::ifstream config_doc(jsonFilepath);
    config_doc >> root;

    cout << root << endl;

    return 0;
}