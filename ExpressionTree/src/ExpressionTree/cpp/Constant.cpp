/**
 * @file Constant.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation file for the Constant class
 * @version 0.1
 * @date 2021-11-07
 */

#include <string>
#include <sstream>
#include "Constant.h"
#include "Node.h"

using namespace std;

Constant::Constant(double value) :
    value{value}
    {
        ;
    }

Constant::~Constant() { }

Node* Constant::derivate(const string&) const {
    return new Constant{0};
}

Node* Constant::clone() const {
    Node* newConstant = new Constant{this->evaluate()};
    copyTree(*newConstant);
    return newConstant;
}

string Constant::toString() const {
    stringstream ss;
    ss.precision(Constant::STRING_PRECISION);
    ss << "(" << evaluate() << ")";
    return ss.str();
}