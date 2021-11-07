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
    
        /**
         * @brief Static int representing the decimal precision that should be 
         *  displayed as part of this constant's string representation
         * 
         */
        static const int STRING_PRECISION{3};

        /**
         * @brief Construct a new Constant object
         * 
         * @param value Any number
         */
        Constant(double value);

        /**
         * @brief Destroy the Constant object
         * 
         */
        ~Constant();

        /**
         * @brief Creates a String representation of this object
         * 
         * @return std::string 
         */
        virtual std::string toString() const override final;

        /**
         * @brief Clones this node then return a pointer to the clone
         * 
         * @return Node* 
         */
        virtual Node* clone() const override final;

        /**
         * @brief Computes the derivative of this Constant (value will always be 0)
         * 
         * @return Node* 
         */
        virtual Node* derivate(const std::string&) const override final;

        /**
         * @brief Evaluate this Constant (returns it's stored value)
         * 
         * @return double The stored value
         */
        virtual double evaluate() const override final { return this->value; }
        
    private:

        /**
         * @brief The number value this Constant represents
         * 
         */
        const double value;
};

#endif // _CONSTANT_H_