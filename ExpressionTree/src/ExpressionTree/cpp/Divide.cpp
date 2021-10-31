#include <limits>
#include <string>
#include <sstream>
#include "Operation.h"
#include "Node.h"
#include "Add.h"
#include "Divide.h"
#include "Multiply.h"
#include "Subtract.h"

using namespace std;

Divide::Divide(const Node& leftNode, const Node& rightNode)
    : Operation(leftNode, rightNode)
{
}

Node* Divide::derivate(const string& d) const {
    Node* du = getLeftNode()->derivate(d);
    Node* dv = getRightNode()->derivate(d);
    Node* u = getLeftNode();
    Node* v = getRightNode();

    Node* vdu = new Multiply{*v, *du};
    Node* udv = new Multiply{*u, *dv};
    Node* vv = new Multiply{*v, *v};
    Node* vduMinusUdv = new Subtract{*vdu, *udv};

    Node* der = new Divide{
        *vduMinusUdv,
        *vv,
    };

    delete(du);
    delete(dv);
    delete(vdu);
    delete(udv);
    delete(vv);
    delete(vduMinusUdv);

    return der;
}

Node* Divide::clone() const {
    Node* newDivide = new Divide(*getLeftNode()->clone(), *getRightNode()->clone());
    copyTree(*newDivide);
    return newDivide;
}

double Divide::evaluate() const {
    if(getLeftNode()->evaluate() == 0) {
        return 0;
    }
    if(getRightNode()->evaluate() == 0) {
        return numeric_limits<double>::quiet_NaN();
    }
    return getLeftNode()->evaluate() / getRightNode()->evaluate();
}

string Divide::toString() const { 
    stringstream ss;
    ss << "(" << getLeftNode()->toString() << " / "
              << getRightNode()->toString() << ")";
    return ss.str();
}

