/**
 * @file UnitTestMain.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Unit testing main file
 * @version 0.1
 * @date 2021-09-23
 */

#if defined(RUN_UNIT_TESTS) && RUN_UNIT_TESTS
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#else
#define DOCTEST_CONFIG_IMPLEMENT
#endif
#include "doctest.h"

/**
 * @brief Runs the tests
 * @ref GitHub "https://github.com/onqtam/doctest/blob/master/doc/markdown/main.md"
 * 
 * @return int 
 */
int main() 
{
    doctest::Context context;

    // overrides
    context.setOption("no-breaks", true);             // don't break in the debugger when assertions fail

    int res = context.run(); // run

    if(context.shouldExit()) // important - query flags (and --exit) rely on the user doing this
        return res;          // propagate the result of the tests
    
    int client_stuff_return_code = 0;
    // your program - if the testing framework is integrated in your production code
    
    return res + client_stuff_return_code; // the result from doctest is propagated here as well
}