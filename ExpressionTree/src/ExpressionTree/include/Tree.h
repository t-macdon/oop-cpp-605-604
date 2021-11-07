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
        Tree(const Node& node);
        ~Tree();
        double getSymbol(const std::string& symbol) const;
        void setSymbol(const std::string& symbol, double value);
        bool hasSymbol(const std::string& symbol) const;
        void setSymbolTable(const std::map<std::string, double>& symbolTable);
        double evaluate() const;
        Tree derivate(const std::string& d) const;
        std::string toString() const;
    private:
        std::map<std::string, double> symbolTable;
        Node* node;
};

std::ostream& operator<<(std::ostream& os, const Tree& tree);

#endif // _TREE_H_