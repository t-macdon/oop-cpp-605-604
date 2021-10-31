#include <string.h>
#include "doctest.h"
#include "Constant.h"

using namespace std;

TEST_CASE("Initialization") {
    Constant c1{0};
    Constant c2{1.2};
    Constant c3{-3000.123};
}

TEST_CASE("Printing to String") {
    Constant c1{0};
    CHECK_EQ(c1.toString(), "(0)");
}

TEST_CASE("Check value of constants") {
    Constant c1{10.123};
    Constant c2{-123.432};
    Constant c3{9000};

    CHECK_EQ(c1.evaluate(), 10.123);
    CHECK_EQ(c2.evaluate(), -123.432);
    CHECK_EQ(c3.evaluate(), 9000);
}

TEST_CASE("Check for exceptions") { 
    // TODO: Check NaN, Inf, -Inf.
    // See what was done in Probability for impl. details.
}
