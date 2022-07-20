#include <stdlib.h>
#include "AST.hpp"

Node::Node(int val) : left_(NULL), right_(NULL), val_(val), ident_(""), oper_("") {}

Node::Node(std::string oper) : left_(NULL), right_(NULL), val_(0), ident_(""), oper_(oper) {}