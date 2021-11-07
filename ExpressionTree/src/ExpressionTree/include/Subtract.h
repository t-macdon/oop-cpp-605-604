/**
 * @file Subtract.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Support for the Subtract Operation
 * @version 0.1
 * @date 2021-11-07
 */

#ifndef _SUBTRACT_H_
#define _SUBTRACT_H_

#include "Operation.h"
#include "Node.h"

class Subtract : public Operation {
    public:

        /**
         * @brief Construct a new Subtract object
         * 
         * @param leftNode Lefthand side of the subtract operator
         * @param rightNode Righthand side of the subtract operator
         */
        Subtract(const Node& leftNode, const Node& rightNode);

        /**
         * @brief Clones this Subtract Node
         * 
         * @return Node* Pointer to the Subtract Clone
         */
        virtual Node* clone() const;

        /**
         * @brief Creates a String representation of this object
         * 
         * @return std::string 
         */
        virtual std::string toString() const;

        /**
         * @brief Subtracts the righthand Node from the lefthand Node
         * 
         * @return double Computed value
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

#endif // _SUBTRACT_H_
