/**
 * @file Multiply.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation file for the Multiply class
 * @version 0.1
 * @date 2021-11-07
 */

#include <string>
#include <sstream>
#include "Operation.h"
#include "Node.h"
#include "Add.h"
#include "Multiply.h"

using namespace std;

Multiply::Multiply(const Node& leftNode, const Node& rightNode)
    : Operation(leftNode, rightNode)
{
}

Node* Multiply::derivate(const string& d) const {
    Node* du = getLeftNode()->derivate(d);
    Node* dv = getRightNode()->derivate(d);
    Node* u = getLeftNode();
    Node* v = getRightNode();

    Node* der = new Add{
        Multiply{*u, *dv},
        Multiply{*v, *du}
    };

    delete(du);
    delete(dv);

    return der;
}

Node* Multiply::clone() const {
    Node* newMultiply = new Multiply(*getLeftNode()->clone(), *getRightNode()->clone());
    copyTree(*newMultiply);
    return newMultiply;
}

double Multiply::evaluate() const {
    if(getLeftNode()->evaluate() == 0 ||
       getRightNode()->evaluate() == 0) {
           return 0;
       }
    return getLeftNode()->evaluate() * getRightNode()->evaluate();
}

string Multiply::toString() const { 
    stringstream ss;
    ss << "(" << getLeftNode()->toString() << " * "
              << getRightNode()->toString() << ")";
    return ss.str();
}
