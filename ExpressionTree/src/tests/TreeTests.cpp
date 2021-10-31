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

TEST_CASE("Check Derivation") {
    Tree t1 {Add{Add{Variable("X"), Variable("Y")}, Variable("X")}};
    Tree t1dx {t1.derivate("X")};
    Tree t1dy {t1.derivate("Y")};

    CHECK_EQ(t1dx.evaluate(), 2);
    CHECK_EQ(t1dy.evaluate(), 1);

    Tree t2{Multiply{Variable{"X"}, Constant{2}}};
    Tree t2dx{t2.derivate("X")};
    Tree t2dy{t2.derivate("Y")};
    CHECK_EQ(t2dx.evaluate(), 2);
    CHECK_EQ(t2dy.evaluate(), 0);

    Tree t3{
        Add{
            Multiply{Variable{"X"}, Constant{2}},
            Multiply{Constant{3}, Variable{"Y"}}
        }
    };

    Tree t3dx{t3.derivate("X")};
    Tree t3dy{t3.derivate("Y")};
    CHECK_EQ(t3dx.evaluate(), 2);
    CHECK_EQ(t3dy.evaluate(), 3);

    Tree t4{
        Divide{Variable{"X"}, Constant{4}}
    };

    Tree t4dx{t4.derivate("X")};
    Tree t4dy{t4.derivate("Y")};
    CHECK_EQ(t4dx.evaluate(), 0.25);
    CHECK_EQ(t4dy.evaluate(), 0);

    Tree t5{
        Divide{
            Multiply{Variable{"X"}, Constant{2}},
            Multiply{Variable{"Y"}, Constant{3}}
        }
    };

    Tree t5dx{t5.derivate("X")};
    Tree t5dy{t5.derivate("Y")};
    CHECK_EQ(t5dx.evaluate(), 0);
    CHECK_EQ(t5dy.evaluate(), 0);
}