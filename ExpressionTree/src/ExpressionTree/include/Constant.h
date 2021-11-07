/**
 * @file Constant.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Support for a Constant Leaf
 * @version 0.1
 * @date 2021-11-07
 */

#ifndef _CONSTANT_H_
#define _CONSTANT_H_

#include <string>
#include "Node.h"
#include "Leaf.h"

class Constant : public Leaf {
    public:
        // No one's paying attention after 3 decimals
        static const int STRING_PRECISION{3};
        Constant(double value);
        ~Constant();
        virtual std::string toString() const override final;
        virtual Node* clone() const override final;
        virtual Node* derivate(const std::string&) const override final;
        virtual double evaluate() const override final { return this->value; }
    private:
        const double value;
};

#endif // _CONSTANT_H_