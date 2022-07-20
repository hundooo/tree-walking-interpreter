#ifndef AST_H
#define AST_H

#include <string>

class Node { 
    public:
        Node *left_;
        Node *right_;
        int val_;
        std::string ident_;
        std::string oper_;
        Node(int val);
        Node(std::string oper);
};

#endif  // AST_H
