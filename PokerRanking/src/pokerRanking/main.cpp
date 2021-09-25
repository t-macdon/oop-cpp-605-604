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

static const int HAND_SIZE = 5;

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

bool populateHandArray(Json::Value value, array<string, HAND_SIZE> &handArray)
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

void printHand(array<string, HAND_SIZE> &hand)
{
    cout << "[";
    for (unsigned int i = 0; i < hand.size(); i++)
    {
        cout << hand[i];
        if (i != hand.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
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
        for (casesIterator = cases.begin(); casesIterator != cases.end(); casesIterator++)
        {
            // get and verify handOne
            Json::Value handOne = casesIterator->get("handOne", Json::Value::null);
            if (isJsonKeyNull(handOne, "handOne"))
            {
                return 1;
            }

            array<string, HAND_SIZE> handOneArray;
            if (!populateHandArray(handOne, handOneArray))
            {
                return 1;
            }
            printHand(handOneArray);

            // get and verify handTwo
            Json::Value handTwo = casesIterator->get("handTwo", Json::Value::null);
            if (isJsonKeyNull(handTwo, "handTwo"))
            {
                return 1;
            }

            array<string, HAND_SIZE> handTwoArray;
            if (!populateHandArray(handTwo, handTwoArray))
            {
                return 1;
            }
            printHand(handTwoArray);
        }
    }

    return 0;
}