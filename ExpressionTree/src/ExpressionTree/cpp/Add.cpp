#include <string>
#include <sstream>
#include "Operation.h"
#include "Node.h"
#include "Add.h"

using namespace std;

Add::Add(const Node& leftNode, const Node& rightNode)
    : Operation(leftNode, rightNode)
{
}

Node* Add::derivate(const string& d) const {
    Node* du = getLeftNode()->derivate(d);
    Node* dv = getRightNode()->derivate(d);
    Node* newAdd =  new Add{*du, *dv};
    delete(du);
    delete(dv);
    return newAdd;
}

Node* Add::clone() const {
    Node* newAdd = new Add(*getLeftNode()->clone(), *getRightNode()->clone());
    copyTree(*newAdd);
    return newAdd;
}

double Add::evaluate() const {
    return getLeftNode()->evaluate() + getRightNode()->evaluate();
}

string Add::toString() const { 
    stringstream ss;
    ss << "(" << getLeftNode()->toString() << " + "
              << getRightNode()->toString() << ")";
    return ss.str();
}
