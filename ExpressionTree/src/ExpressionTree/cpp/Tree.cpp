/**
 * @file Tree.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation file for the Tree class
 * @version 0.1
 * @date 2021-11-07
 */

#include <ostream>
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

ostream& operator<<(ostream& os, const Tree& tree) {
    os << tree.toString();
    return os;
}

double Tree::evaluate() const {
    return node->evaluate();
}

string Tree::toString() const {
    return node->toString();
}

Tree Tree::derivate(const std::string& d) const {
    Tree derivedTree{*node->derivate(d)};
    derivedTree.setSymbolTable(this->symbolTable);
    return derivedTree;
}

void Tree::setSymbolTable(const std::map<std::string, double>& symbolTable) {
    this->symbolTable = symbolTable;
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