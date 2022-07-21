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
        if (cur_token_.type_ == RPAREN) {next_token(); continue;}
        if (peek_token_.type_ == DEFINE) { 
            next_token();
            root.push_back(parse_define());
        } else if (cur_token_.type_ == LPAREN) { 
            root.push_back(parse_expression());
        } else { 
            root.push_back(parse_single());
        }
        next_token();
    }
    return root;
}

Node *Parser::parse_expression() {
    next_token();
    if (cur_token_.type_ == INT) {
        Node *leaf = new Node(std::stoi(cur_token_.literal_));
        return leaf;
    } else if (cur_token_.type_ == IDENT) {
        Node *tmp = new Node();
        tmp->ident_ = cur_token_.literal_;
        return tmp;
    } else if (cur_token_.type_ == PLUS) {
        Node *internal = new Node(cur_token_.literal_);
        internal->left_= parse_expression();
        internal->right_ = parse_expression();
        return internal;
    } else {
        return parse_expression();
    }
}

Node *Parser::parse_single() { 
    Node *n = new Node();
    if (cur_token_.type_ == IDENT) { 
        n->ident_ = cur_token_.literal_;
    } else {
        n->val_ = std::stoi(cur_token_.literal_);
    }
    return n;
}

Node *Parser::parse_define() { 
    Node *node = new Node();
    node->ident_ = peek_token_.literal_;
    next_token();
    node->left_ = parse_expression();
    return node;
}

void Parser::node_destroy(Node *n) { 
    if (n) { 
        node_destroy(n->left_);
        node_destroy(n->right_);
        delete n;
    }
}
