#ifndef _MULTIPLY_H_
#define _MULTIPLY_H_

#include "Operation.h"
#include "Node.h"

class Multiply : public Operation {
    public:
        Multiply(const Node& leftNode, const Node& rightNode);
        virtual Node* clone() const;
        virtual std::string toString() const;
        virtual double evaluate() const override final;
        virtual Node* derivate(const std::string& d) const override final;
};

#endif