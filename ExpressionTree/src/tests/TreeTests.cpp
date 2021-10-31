#include <iostream>
#include <cmath>
#include "doctest.h"
#include "Add.h"
#include "Tree.h"
#include "Constant.h"
#include "Variable.h"

using namespace std;

TEST_CASE("Initialize") {
    Tree t{ Add{ Constant(1), Constant(2)} };
}

TEST_CASE("Evaluate Constants") {
    Tree t{ Add{ Constant(1), Constant(2)} };
    CHECK_EQ(t.evaluate(), 3);
}

TEST_CASE("Evaluate Variables") {
    Tree t1 {Add{Add{Variable("XRAY"), Constant(2)}, Constant(3)}};
    t1.setSymbol("XRAY", 40);
    CHECK_EQ(t1.evaluate(), 40+2+3);

    Tree t2 {Add{Add{Variable("XRAY"), Constant(2)}, Constant(3)}};
    CHECK(isnan(t2.evaluate()));
}

TEST_CASE("Check Derivation") {
    Tree t1 {Add{Add{Variable("X"), Variable("Y")}, Variable("X")}};
    Tree t1dx {t1.derivate("X")};
    Tree t1dy {t1.derivate("Y")};

    CHECK_EQ(t1dx.evaluate(), 2);
    CHECK_EQ(t1dy.evaluate(), 1);
}