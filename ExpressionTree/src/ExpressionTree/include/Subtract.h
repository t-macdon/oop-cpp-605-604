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
        Subtract(const Node& leftNode, const Node& rightNode);
        virtual Node* clone() const;
        virtual std::string toString() const;
        virtual double evaluate() const override final;
        virtual Node* derivate(const std::string& d) const override final;
};

#endif
