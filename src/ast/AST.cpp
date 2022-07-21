#include <stdlib.h>
#include "AST.hpp"

Node::Node() : left_(NULL), right_(NULL), val_(0), ident_(""), oper_("") {}

Node::Node(int val) : left_(NULL), right_(NULL), val_(val), ident_(""), oper_("") {}

Node::Node(std::string oper) : left_(NULL), right_(NULL), val_(0), ident_(""), oper_(oper) {}

std::string Node::to_string() { 
    std::string left;
    std::string right;
    left_ == NULL ? left = "NO" : left = "YES";
    right_ == NULL ? right = "NO" : right = "YES";
    return left + " " + right + " " + oper_;
}