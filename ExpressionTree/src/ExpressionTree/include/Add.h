/**
 * @file Add.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Support for the Add Operation
 * @version 0.1
 * @date 2021-11-07
 */

#ifndef _ADD_H_
#define _ADD_H_

#include "Operation.h"
#include "Node.h"

class Add : public Operation {
    public:

        /**
         * @brief Construct a new Add object
         * 
         * @param leftNode Lefthand side of the add operator
         * @param rightNode Righthand side of the add operator
         */
        Add(const Node& leftNode, const Node& rightNode);

        /**
         * @brief Clones this Add Node
         * 
         * @return Node* Pointer to the Add clone
         */
        virtual Node* clone() const;

        /**
         * @brief Creates a String representation of this object
         * 
         * @return std::string
         */
        virtual std::string toString() const;

        /**
         * @brief Adds the left and right Nodes
         * 
         * @return double The result of the addition operation
         */
        virtual double evaluate() const override final;

        /**
         * @brief Computes the derivatives of leftNode and rightNode
         * 
         * @param d The name of the variable being derived
         * @return Node* 
         */
        virtual Node* derivate(const std::string& d) const override final;
};

#endif // _ADD_H_