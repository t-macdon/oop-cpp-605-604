/**
 * @file Multiply.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Support for the Multiply Operation
 * @version 0.1
 * @date 2021-11-07
 */

#ifndef _MULTIPLY_H_
#define _MULTIPLY_H_

#include "Operation.h"
#include "Node.h"

class Multiply : public Operation {
    public:

        /**
         * @brief Construct a new Multiply object
         * 
         * @param leftNode Lefthand side of the Multiply operator
         * @param rightNode Righthand side of the Multiply operator
         */
        Multiply(const Node& leftNode, const Node& rightNode);

        /**
         * @brief Clones this Multiply Node
         * 
         * @return Node* Pointer to the Multiply clone 
         */
        virtual Node* clone() const;

        /**
         * @brief Creates a String representation of this object
         * 
         * @return std::string
         */
        virtual std::string toString() const;

        /**
         * @brief Multiplies the left and right nodes
         * 
         * @return double The result of the multiplication operation
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

#endif // _MULTIPLY_H_