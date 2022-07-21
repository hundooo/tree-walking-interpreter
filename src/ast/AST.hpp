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
        Node();
        Node(int val);
        Node(std::string oper);
        std::string to_string();
};

#endif  // AST_H
