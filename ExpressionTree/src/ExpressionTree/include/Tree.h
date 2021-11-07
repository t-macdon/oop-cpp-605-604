/**
 * @file Tree.h
 * @author Michael Schumacher, Tyler MacDonald
 * @brief Data structure comprised of Nodes. These nodes are traversed and interpreted based on the Tree method called.
 * @version 0.1
 * @date 2021-11-07
 */

#ifndef _TREE_H_
#define _TREE_H_

#include <ostream>
#include <string>
#include <map>

// Prevent cyclic includes by forward declaring this class
class Node;

class Tree {
    public:

        /**
         * @brief Construct a new Tree object
         * 
         * @param node 
         */
        Tree(const Node& node);

        /**
         * @brief Destroy the Tree object
         * 
         */
        ~Tree();

        /**
         * @brief Get the Symbol object
         * 
         * @param symbol 
         * @return double 
         */
        double getSymbol(const std::string& symbol) const;

        /**
         * @brief Set the Symbol object
         * 
         * @param symbol 
         * @param value 
         */
        void setSymbol(const std::string& symbol, double value);

        /**
         * @brief Determine of the symbol exists in the symbol table
         * 
         * @param symbol 
         * @return true If symbol is in the table
         * @return false If symbol is not in the table
         */
        bool hasSymbol(const std::string& symbol) const;

        /**
         * @brief Set the Symbol Table object (std::map)
         * 
         * @param symbolTable 
         */
        void setSymbolTable(const std::map<std::string, double>& symbolTable);

        /**
         * @brief Computes the value of this Tree by traversing the Nodes
         * 
         * @return double The computed value
         */
        double evaluate() const;

        /**
         * @brief Computes the derivative by traversing the Tree's Nodes
         * 
         * @param d Name of the Variable being derived
         * @return Tree 
         */
        Tree derivate(const std::string& d) const;

        /**
         * @brief String representation of this Tree
         * 
         * @return std::string 
         */
        std::string toString() const;
    private:

        /**
         * @brief Mapping of Variable symbols to their appointed values
         * 
         */
        std::map<std::string, double> symbolTable;

        /**
         * @brief Pointer to this Tree's root node
         * 
         */
        Node* node;
};


/**
 * @brief Output stream operator overload
 * 
 * @param os 
 * @param node 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Tree& tree);

#endif // _TREE_H_