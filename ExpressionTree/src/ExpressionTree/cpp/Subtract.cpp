#include <string>
#include <sstream>
#include "Operation.h"
#include "Node.h"
#include "Add.h"
#include "Subtract.h"
#include "Variable.h"

using namespace std;

Subtract::Subtract(const Node& leftNode, const Node& rightNode)
    : Operation(leftNode, rightNode)
{
}

Node* Subtract::derivate(const string& d) const {
    Node* du = getLeftNode()->derivate(d);
    Node* dv = getRightNode()->derivate(d);

    Node* der = new Subtract{*du, *dv};

    delete(du);
    delete(dv);

    return der;
}

Node* Subtract::clone() const {
    Node* newSubtract = new Subtract(*getLeftNode()->clone(), *getRightNode()->clone());
    copyTree(*newSubtract);
    return newSubtract;
}

double Subtract::evaluate() const {
    // Do we need to support a cancel-out on equality?
    // A quick way to do it here would be to check if they're variables, if so check names.
    // Otherwise, we could do a global equality up at the node point ... Which could be a pain.
    Variable* leftAsVariable = dynamic_cast<Variable*>(getLeftNode());
    Variable* rightAsVariable = dynamic_cast<Variable*>(getRightNode());
    if (leftAsVariable && rightAsVariable) {
        if (leftAsVariable->getVariableName() == rightAsVariable->getVariableName()) {
            return 0;
        }
    }
    return getLeftNode()->evaluate() - getRightNode()->evaluate();
}

string Subtract::toString() const { 
    stringstream ss;
    ss << "(" << getLeftNode()->toString() << " - "
              << getRightNode()->toString() << ")";
    return ss.str();
}

