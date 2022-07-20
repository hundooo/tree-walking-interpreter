#include <iostream>
#include "Parser.hpp"
#include "../token/Token.hpp"
#include "../lexer/Lexer.hpp"
#include "../ast/AST.hpp"

Parser::Parser(Lexer l) : l_(l) {next_token(); next_token();}

void Parser::next_token() { 
    cur_token_ = peek_token_;
    peek_token_ = l_.next_token();
}

std::vector<Node *> Parser::parse() {
    std::vector<Node *> root;
    while (cur_token_.type_ != eof) {
        root.push_back(parseExpression());
    }
    return root;
}

// Node *Parser::parseExpression() { 
//     next_token();
//     static Node op = Node(cur_token_.literal_);
    
//     next_token();
//     static Node left = Node(std::stoi(cur_token_.literal_));
//     Node *lft_ptr = &left;
//     op.left_ = lft_ptr;

//     next_token();
//     static Node right = Node(std::stoi(cur_token_.literal_));
//     Node *rgt_ptr = &right;
//     op.right_ = rgt_ptr;

//     Node *op_ptr = &op;
//     return op_ptr;
// }

Node *Parser::parseExpression() {
    next_token();
    if (cur_token_.type_ == INT) {
        Node *leaf = new Node(std::stoi(cur_token_.literal_));
        return leaf;
    } else if (cur_token_.type_ == PLUS) {
        Node *internal = new Node(cur_token_.literal_);
        internal->left_= parseExpression();
        internal->right_ = parseExpression();
        return internal;
    } else {
        return parseExpression();
    }
}

void Parser::node_destroy(Node *n) { 
    if (n) { 
        node_destroy(n->left_);
        node_destroy(n->right_);
        delete n;
    }
}
