/**
 * @file Node.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Virtual class representing a Node. Classes inheriting Node can belong to a Tree.
 * @version 0.1
 * @date 2021-11-07
 */

#ifndef _NODE_H_
#define _NODE_H_

#include <ostream>
#include <string>

// Forward declaration of class Tree.
// This is needed to prevent cyclic including
class Tree;

class Node {

    public:
    
        /**
         * @brief Construct a new Node object
         * 
         */
        Node();

        /**
         * @brief Destroy the Node object
         * 
         */
        virtual ~Node();

        /**
         * @brief Override to clone the object
         * 
         * @return Node* A pointer to the clone
         */
        virtual Node* clone() const = 0;

        /**
         * @brief Override to create a String representation of the object
         * 
         * @return std::string 
         */
        virtual std::string toString() const = 0;

        /**
         * @brief Override to compute the value of this Node
         * 
         * @return double The computed value
         */
        virtual double evaluate() const = 0;

        /**
         * @brief Override to compute the derivation of this node
         *  with respect to the provided variable String
         * 
         * @return Node* 
         */
        virtual Node* derivate(const std::string&) const = 0;

        /**
         * @brief Get the Tree object
         * 
         * @return Tree* Pointer to the associated Tree
         */
        Tree* getTree() const { return tree; }

        /**
         * @brief Set the Tree object
         * 
         * @param tree Pointer to the Tree
         */
        virtual void setTree(Tree* tree) { this->tree = tree; }

        /**
         * @brief Determines if Tree pointer is set
         * 
         * @return true If Tree pointer is not nullptr
         * @return false If Tree pointer is nullptr
         */
        bool hasTree() const { return this->tree != nullptr; }

        /**
         * @brief Sets the provided Node's Tree pointer to this
         *  Node's associated Tree pointer
         * 
         * @param n The Node to pass this Node's tree pointer into
         */
        void copyTree(Node& n) const {n.tree = this->tree;}

    private:

        /**
         * @brief Pointer to this Node's associated Tree object
         * 
         */
        Tree* tree;

};

/**
 * @brief Output stream operator overload
 * 
 * @param os 
 * @param node 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Node& node);

#endif // _NODE_H_