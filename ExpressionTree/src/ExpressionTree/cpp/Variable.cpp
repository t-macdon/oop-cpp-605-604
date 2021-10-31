#include <string>
#include <sstream>
#include <limits>

#include "Tree.h"
#include "Variable.h"
#include "Constant.h"
#include "Node.h"

using namespace std;

Variable::Variable(string varName) :
    varName{varName}
{
    ;
}

Variable::~Variable() { };

Node* Variable::clone() const {
    Node* newVariable = new Variable{this->getVariableName()};
    copyTree(*newVariable);
    return newVariable;
}

Node* Variable::derivate(const string& d) const {
    if (d == getVariableName()) {
        return new Constant{1.0};
    }
    else {
        return new Constant{0};
    }
}

double Variable::evaluate() const {
    Tree* tree = nullptr;
    if (this->hasTree()) {
        tree = dynamic_cast<Tree*>(getTree());
    }

    if(tree && tree->hasSymbol(varName)) {
        return tree->getSymbol(varName);
    }

    return numeric_limits<double>::quiet_NaN();
}

string Variable::toString() const {
    stringstream ss;
    ss << "(" << getVariableName() << ")";
    return ss.str();
}