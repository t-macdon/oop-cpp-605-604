#include <cmath>
#include "doctest.h"
#include "Add.h"
#include "Constant.h"
#include "Variable.h"

using namespace std;

TEST_CASE("Initialize") {
    Add a1{ Constant(1), Constant(2) };
    Add a2{ Constant(1), Variable("X") };
    Add a3{ Variable("Y"), Variable("X") };
    Add a4{ a1, Constant(1.234)};
    Add a5{ a4, a2 };
}

TEST_CASE("Printing to String") {
    Add a1{ Constant(1), Constant(2) };
    Add a2{ Constant(1), Variable("X") };
    Add a3{ Add{ Constant(1), Constant(2)}, Constant(3)};

    CHECK_EQ("((1) + (2))", a1.toString());
    CHECK_EQ("((1) + (X))", a2.toString());
    CHECK_EQ("(((1) + (2)) + (3))", a3.toString());
}

TEST_CASE("Evaluate addition") {
    Add a1{ Constant(1), Constant(2) };
    Add a2{ Constant(1), Variable("X") };
    Add a3{ Add{ Constant(1), Constant(2)}, Constant(3)};

    CHECK_EQ(a1.evaluate(), 3);
    CHECK(isnan(a2.evaluate()));
    CHECK_EQ(a3.evaluate(), 6);
}