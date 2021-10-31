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