/**
 * @file Divide.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Support for the Divide Operation
 * @version 0.1
 * @date 2021-11-07
 */

#ifndef _DIVIDE_H_
#define _DIVIDE_H_

#include "Operation.h"
#include "Node.h"

class Divide : public Operation {
    public:

        /**
         * @brief Construct a new Divide object
         * 
         * @param leftNode Lefthand side of the divide operator
         * @param rightNode Righthand side of the divide operator
         */
        Divide(const Node& leftNode, const Node& rightNode);

        /**
         * @brief Clones this Node then returns a pointer to the clone
         * 
         * @return Node* 
         */
        virtual Node* clone() const;

        /**
         * @brief Creates a String representation of this object
         * 
         * @return std::string 
         */
        virtual std::string toString() const;

        /**
         * @brief Divides leftNode by the rightNode
         * 
         * @return double The result of the division operation
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

#endif
