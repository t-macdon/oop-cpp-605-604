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
        Divide(const Node& leftNode, const Node& rightNode);
        virtual Node* clone() const;
        virtual std::string toString() const;
        virtual double evaluate() const override final;
        virtual Node* derivate(const std::string& d) const override final;
};

#endif
