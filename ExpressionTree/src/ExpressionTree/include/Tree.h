#ifndef _TREE_H_
#define _TREE_H_

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
        double evaluate() const;
        Node& derivate(const std::string& d) const;
        std::string toString() const;
    private:
        std::map<std::string, double> symbolTable;
        Node* node;
};

#endif // _TREE_H_