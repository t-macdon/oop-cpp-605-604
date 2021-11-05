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