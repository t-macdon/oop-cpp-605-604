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

#include "Card.h"
#include "Hand.h"

using namespace std;

/**
 * @brief Checks if a file can be accessed.
 * @ref StackOverflow "https://stackoverflow.com/a/19841704"
 * 
 * @param filepath Path to file to check
 * @return true
 * @return false 
 */
bool isFileAccessible(std::string filepath)
{
    std::ifstream f(filepath);
    return f.good();
}

bool isJsonKeyNull(Json::Value value, std::string key)
{
    if (value == Json::Value::null)
    {
        cout << "ERROR: Json key \"" << key << "\" not found" << endl;
        return true;
    }
    return false;
}

bool populateHandArray(Json::Value value, array<string, Hand::HAND_SIZE> &handArray)
{
    // confirm it's an array
    if (!value.isArray())
    {
        cout << "ERROR: handOne must be an array" << endl;
        return false;
    }

    // populate array
    Json::ArrayIndex index;
    for (index = 0; index < value.size(); index++)
    {
        handArray[index] = value.get(index, Json::Value::null).asString();
    }

    return true;
}

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
    
    // confirm file can be accessed
    if (!isFileAccessible(jsonFilepath))
    {
        cout << "Provided filepath cannot be accessed: \"" << jsonFilepath << "\"" << endl;
        return 1; 
    }

    // read in the json file
    Json::Value root;
    std::ifstream config_doc(jsonFilepath);
    config_doc >> root;

    // get root of json file and confirm it exists
    Json::Value tests = root.get("handTests", Json::Value::null);
    if (isJsonKeyNull(tests, "handTests"))
    {
        return 1;
    }

    // tests needs to be an array
    if (!tests.isArray())
    {
        cout << "ERROR: Json root must be an array" << endl;
        return 1;
    }

    // iterate over tests in json file (with error checking)
    Json::Value::iterator iterator;
    for (iterator = tests.begin(); iterator != tests.end(); iterator++)
    {
        // first grab the test description
        Json::Value description = iterator->get("description", Json::Value::null);
        if (isJsonKeyNull(description, "description"))
        {
            return 1;
        }

        cout << "Processing test with description: " << description << endl;

        // now grab the cases
        Json::Value cases = iterator->get("cases", Json::Value::null);
        if (isJsonKeyNull(cases, "cases"))
        {
            return 1;
        }

        // cases needs to be an array
        if (!cases.isArray())
        {
            cout << "ERROR: Test cases must be an array" << endl;
            return 1;
        }

        // iterate over and test each case
        Json::Value::iterator casesIterator;
        int testCount = 0;
        for (casesIterator = cases.begin(); casesIterator != cases.end(); casesIterator++)
        {
            testCount++;
            cout << "Test Number: " << testCount << endl;
            
            // get and verify handOne
            Json::Value handOneRoot = casesIterator->get("handOne", Json::Value::null);
            if (isJsonKeyNull(handOneRoot, "handOne"))
            {
                return 1;
            }

            // populate hand one
            Json::ArrayIndex index;
            Hand handOne;
            for (index = 0; index < handOneRoot.size(); index++)
            {
                Json::Value cardRoot = handOneRoot.get(index, Json::Value::null);
                if (cardRoot == Json::Value::null)
                {
                    cout << "Card Root for index " << index << " is null" << endl;
                    return 1;
                }
                string cardString = cardRoot.asString();
                Card card(cardString);
                handOne.addCard(card);
            }
            cout << "Hand One: " << handOne.toString() << endl;

            // get and verify handTwo
            Json::Value handTwoRoot = casesIterator->get("handTwo", Json::Value::null);
            if (isJsonKeyNull(handTwoRoot, "handTwo"))
            {
                return 1;
            }

            // populate hand two
            Hand handTwo;
            for (index = 0; index < handTwoRoot.size(); index++)
            {
                Json::Value cardRoot = handTwoRoot.get(index, Json::Value::null);
                if (cardRoot == Json::Value::null)
                {
                    cout << "Card Root for index " << index << " is null" << endl;
                    return 1;
                }
                string cardString = cardRoot.asString();
                Card card(cardString);
                handTwo.addCard(card);
            }
            cout << "Hand Two: " << handTwo.toString() << endl;
        }
    }

    return 0;
}