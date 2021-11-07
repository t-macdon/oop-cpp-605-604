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

        /**
         * @brief Construct a new Operation object
         * 
         * @param leftNode Reference to the lefthand side of this operator
         * @param rightNode Reference to the righthand side of this operator
         */
        Operation(const Node& leftNode, const Node& rightNode);

        /**
         * @brief Destroy the Operation object
         * 
         */
        virtual ~Operation();

        /**
         * @brief Set the Tree object
         * 
         * @param tree 
         */
        virtual void setTree(Tree* tree) override;
        
        /**
         * @brief Get the Left Node object
         * 
         * @return Node* 
         */
        Node* getLeftNode() const { return this->leftNode; }

        /**
         * @brief Get the Right Node object
         * 
         * @return Node* 
         */
        Node* getRightNode() const { return this->rightNode; }

    private:
    
        /**
         * @brief Pointer to the lefthand Node
         * 
         */
        Node* leftNode;

        /**
         * @brief Pointer to the righthand Node
         * 
         */
        Node* rightNode;
};

#endif // _OPERATION_H_