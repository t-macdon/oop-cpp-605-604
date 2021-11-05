
#ifndef _NODE_H_
#define _NODE_H_

#include <ostream>
#include <string>

// Forward declaration of class Tree.
// This is needed to prevent cyclic including
class Tree;

class Node {

    public:
        Node();
        virtual ~Node();
        virtual Node* clone() const = 0;
        virtual std::string toString() const = 0;
        virtual double evaluate() const = 0;
        virtual Node* derivate(const std::string&) const = 0;
        Tree* getTree() const { return tree; }
        virtual void setTree(Tree* tree) { this->tree = tree; }
        bool hasTree() const { return this->tree != nullptr; }
        void copyTree(Node& n) const {n.tree = this->tree;}

    private:
        Tree* tree;

};

std::ostream& operator<<(std::ostream& os, const Node& node);

#endif // _NODE_H_