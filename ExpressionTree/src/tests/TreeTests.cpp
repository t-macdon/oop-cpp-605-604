#include <iostream>
#include <cmath>
#include "doctest.h"
#include "Add.h"
#include "Subtract.h"
#include "Divide.h"
#include "Multiply.h"
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

TEST_CASE("Check Derivation of Addition") {
    // (X + Y) + X
    Tree t {Add{Add{Variable("X"), Variable("Y")}, Variable("X")}};
    Tree tdx {t.derivate("X")};
    Tree tdy {t.derivate("Y")};

    CHECK_EQ(tdx.evaluate(), 2);
    CHECK_EQ(tdy.evaluate(), 1);
}

TEST_CASE("Check Derivation of Multiplication") {
    // X*2
    Tree t{Multiply{Variable{"X"}, Constant{2}}};
    Tree tdx{t.derivate("X")};
    Tree tdy{t.derivate("Y")};

    CHECK_EQ(tdx.evaluate(), 2);
    CHECK_EQ(tdy.evaluate(), 0);
}

TEST_CASE("Check Derivation of Division") {
    // (X / 4)
    Tree t{
        Divide{Variable{"X"}, Constant{4}}
    };

    Tree tdx{t.derivate("X")};
    Tree tdy{t.derivate("Y")};
    CHECK_EQ(tdx.evaluate(), 0.25);
    CHECK_EQ(tdy.evaluate(), 0);
}

TEST_CASE("Check Derivation of Mixed Operators") {
    // (2*X) + (3*Y)
    Tree t{
        Add{
            Multiply{Variable{"X"}, Constant{2}},
            Multiply{Constant{3}, Variable{"Y"}}
        }
    };

    Tree tdx{t.derivate("X")};
    Tree tdy{t.derivate("Y")};
    CHECK_EQ(tdx.evaluate(), 2);
    CHECK_EQ(tdy.evaluate(), 3);
}

TEST_CASE("Derivation with Evaluation") {
    // Example problem given from prompt
    Tree t = Add(
        Multiply(Constant(2.3), Variable("X")),
        Multiply(Variable("Y"),
        Subtract(Variable("Z"), Variable("X"))));

    CHECK_EQ(
        t.toString(),
        "(((2.3) * (X)) + ((Y) * ((Z) - (X))))"
    );

    t.setSymbol("X", 2.0);
    t.setSymbol("Y", 3.0);
    t.setSymbol("Z", 5.0);

    Tree dt = t.derivate("X");
    CHECK_EQ(
        dt.toString(),
        "((((2.3) * (1)) + ((X) * (0))) + (((Y) * ((0) - (1))) + (((Z) - (X)) * (0))))"
    );

    CHECK(dt.evaluate() == doctest::Approx(-0.7));
}