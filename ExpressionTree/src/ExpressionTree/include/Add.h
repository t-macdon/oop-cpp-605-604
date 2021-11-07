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
        Add(const Node& leftNode, const Node& rightNode);
        virtual Node* clone() const;
        virtual std::string toString() const;
        virtual double evaluate() const override final;
        virtual Node* derivate(const std::string& d) const override final;
};

#endif // _ADD_H_