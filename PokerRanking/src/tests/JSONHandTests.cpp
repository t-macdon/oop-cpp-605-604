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
#include "doctest.h"
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

/**
 * @brief Check if a given key is null
 * 
 * @param value 
 * @param key 
 * @return true Key is null
 * @return false Key is not null (and so exists)
 */
bool isJsonKeyNull(Json::Value value, std::string key)
{
    if (value == Json::Value::null)
    {
        cerr << "JSON key not found: " << key << endl;
        return true;
    }
    return false;
}

TEST_CASE("Reads Test Cases From JSON File")
{
    // save json filepath in string
    string jsonFilepath("/workspaces/oop-cpp-605-604/PokerRanking/src/hands.json");
    
    // confirm file can be accessed
    CHECK(isFileAccessible(jsonFilepath));

    // read in the json file
    Json::Value root;
    std::ifstream config_doc(jsonFilepath);
    config_doc >> root;

    // get root of json file and confirm it exists
    Json::Value tests = root.get("handTests", Json::Value::null);
    CHECK(!isJsonKeyNull(tests, "handTests"));
    CHECK(tests.isArray());

    // iterate over tests in json file (with error checking)
    Json::Value::iterator iterator;
    for (iterator = tests.begin(); iterator != tests.end(); iterator++)
    {
        // first grab the test description
        Json::Value description = iterator->get("description", Json::Value::null);
        CHECK(!isJsonKeyNull(description, "description"));

        // now grab the cases
        Json::Value cases = iterator->get("cases", Json::Value::null);
        CHECK(!isJsonKeyNull(cases, "cases"));
        CHECK(cases.isArray());

        // iterate over and test each case
        Json::Value::iterator casesIterator;
        for (casesIterator = cases.begin(); casesIterator != cases.end(); casesIterator++)
        {            
            // get and verify handOne
            Json::Value handOneRoot = casesIterator->get("handOne", Json::Value::null);
            CHECK(!isJsonKeyNull(handOneRoot, "handOne"));

            // populate hand one
            Json::ArrayIndex index;
            Hand handOne;
            for (index = 0; index < handOneRoot.size(); index++)
            {
                Json::Value cardRoot = handOneRoot.get(index, Json::Value::null);
                CHECK(!isJsonKeyNull(cardRoot, "card"));
                string cardString = cardRoot.asString();
                Card card(cardString);
                handOne.addCard(card);
            }

            // get and verify handTwo
            Json::Value handTwoRoot = casesIterator->get("handTwo", Json::Value::null);
            CHECK(!isJsonKeyNull(handTwoRoot, "handTwo"));

            // populate hand two
            Hand handTwo;
            for (index = 0; index < handTwoRoot.size(); index++)
            {
                Json::Value cardRoot = handTwoRoot.get(index, Json::Value::null);
                CHECK(!isJsonKeyNull(cardRoot, "index"));
                
                string cardString = cardRoot.asString();
                Card card(cardString);
                handTwo.addCard(card);
            }

            // get the operator
            Json::Value operatorRoot = casesIterator->get("operator", Json::Value::null);
            CHECK(!isJsonKeyNull(operatorRoot, "operator"));
            CHECK(operatorRoot.isString());
            string operatorString = operatorRoot.asString();

            // compare hands based on operator
            if (operatorString.compare(">") == 0)
            {
                CHECK(handOne > handTwo);
            } else if (operatorString.compare("==") == 0)
            {
                CHECK(handOne == handTwo);
            } else if (operatorString.compare("<") == 0)
            {
                CHECK(handOne < handTwo);
            } else
            {
                cerr << "Unrecognized operator: " << operatorString << endl;
            }
        }
    }
}