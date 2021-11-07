/**
 * @file Node.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation file for the Node class
 * @version 0.1
 * @date 2021-11-07
 */

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