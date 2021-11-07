/**
 * @file Variable.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Support for a Variable Leaf which is looked up in the symbol table
 * @version 0.1
 * @date 2021-11-07
 */

#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <string>
#include "Node.h"
#include "Leaf.h"

class Variable : public Leaf {
    public:
        Variable(std::string varName);
        ~Variable();
        virtual std::string toString() const override final;
        virtual Node* clone() const override final;
        virtual Node* derivate(const std::string&) const override final;
        std::string getVariableName() const { return this->varName; }
        virtual double evaluate() const override final;
    private:
        const std::string varName;
};

#endif // _VARIABLE_H_