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

        /**
         * @brief Construct a new Variable object
         * 
         * @param varName Name of the Variable
         */
        Variable(std::string varName);

        /**
         * @brief Destroy the Variable object
         * 
         */
        ~Variable();

        /**
         * @brief Creates a String representation of the object
         * 
         * @return std::string 
         */
        virtual std::string toString() const override final;

        /**
         * @brief Clones this Variable
         * 
         * @return Node* Pointer to the clone
         */
        virtual Node* clone() const override final;

        /**
         * @brief Computes this Variable's derivative (either 0 or 1)
         * 
         * @return Node*
         */
        virtual Node* derivate(const std::string&) const override final;

        /**
         * @brief Get the Variable Name object
         * 
         * @return std::string 
         */
        std::string getVariableName() const { return this->varName; }

        /**
         * @brief Computes the value of this Variable
         * 
         * @return double This variable's value
         */
        virtual double evaluate() const override final;

    private:

        /**
         * @brief Name of the Variable
         * 
         */
        const std::string varName;
};

#endif // _VARIABLE_H_