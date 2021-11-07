/**
 * @file Leaf.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Base class for a Leaf Node
 * @version 0.1
 * @date 2021-11-07
 */

#ifndef _LEAF_H_
#define _LEAF_H_

#include "Node.h"

class Leaf : public Node {
    public: 

        /**
         * @brief Construct a new Leaf object
         * 
         */
        Leaf();

        /**
         * @brief Destroy the Leaf object
         * 
         */
        virtual ~Leaf();
};

#endif // _LEAF_H_