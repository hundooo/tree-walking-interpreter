#ifndef AST_H
#define AST_H

#include <string>

class Node { 
    public:
        Node *left;
        Node *right;
        int val;
        std::string ident;
};

#endif  // AST_H
