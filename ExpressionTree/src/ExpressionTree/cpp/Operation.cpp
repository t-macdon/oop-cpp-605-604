/**
 * @file Operation.cpp
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Implementation file for the Operation class
 * @version 0.1
 * @date 2021-11-07
 */

#include <memory>
#include "Tree.h"
#include "Node.h"
#include "Operation.h"

using namespace std;
Operation::Operation(const Node& leftNode, const Node& rightNode) :
    leftNode{leftNode.clone()}, rightNode{rightNode.clone()}
{
}

void Operation::setTree(Tree* tree) {
    Node::setTree(tree);
    getLeftNode()->setTree(getTree());
    getRightNode()->setTree(getTree());
}

Operation::~Operation() {
    delete this->leftNode;
    delete this->rightNode;
    this->rightNode = this->leftNode = nullptr;
}