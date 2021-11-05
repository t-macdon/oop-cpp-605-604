#include "Node.h"

using namespace std;

Node::Node():
    tree{nullptr}
{
    ;
}

Node::~Node() { }

ostream& operator<<(ostream& os, const Node& node) {
    os << node.toString();
    return os;
}