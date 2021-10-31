#include <string>
#include "Operation.h"
#include "Tree.h"

using namespace std;

Tree::Tree(const Node& node) {
    this->node = node.clone();
    this->node->setTree(this);
}

Tree::~Tree() {
    if(this->node != nullptr) {
        delete this->node;
    }
    this->node = nullptr;
}

double Tree::evaluate() const {
    return node->evaluate();
}

string Tree::toString() const {
    return node->toString();
}

Node& Tree::derivate(const std::string& d) const {
    return *node->derivate(d);
}

double Tree::getSymbol(const string& symbol) const {
    if (hasSymbol(symbol)) { 
        return symbolTable.at(symbol);
    }
    else {
        throw std::out_of_range{"Invalid Symbol"};
    }
}

bool Tree::hasSymbol(const string& symbol) const {
    return (symbolTable.count(symbol) != 0);
}

void Tree::setSymbol(const string& symbol, double value) {
    symbolTable[symbol] = value;
}