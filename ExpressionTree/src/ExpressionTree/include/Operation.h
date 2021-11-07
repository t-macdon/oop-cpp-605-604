/**
 * @file Operation.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Virtual class for Operation support. Operations are Nodes and belong to a Tree.
 * @version 0.1
 * @date 2021-11-07
 */

#ifndef _OPERATION_H_
#define _OPERATION_H_

#include "Node.h"

class Tree;

class Operation : public Node {
    public:
        Operation(const Node& leftNode, const Node& rightNode);
        virtual ~Operation();
        virtual void setTree(Tree* tree) override;

        // TODO: Replace these with weak ptr or something
        // Also, could assign some const-ness to return type?
        Node* getLeftNode() const { return this->leftNode; }
        Node* getRightNode() const { return this->rightNode; }
    private:
        // TODO: Figure out how to replace these
        // with something that implicitly takes care of ownership,
        // like shared_ptr or unique_ptr
        Node* leftNode;
        Node* rightNode;
};

#endif // _OPERATION_H_