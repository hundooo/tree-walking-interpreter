#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "../token/Token.hpp"
#include "../lexer/Lexer.hpp"
#include "../ast/AST.hpp"

class Parser { 
    public:
        Lexer l_;
        Token cur_token_;
        Token peek_token_;
        Parser(Lexer l);
        void next_token();
        std::vector<Node *> parse();
        Node *parse_expression();
        Node *parse_single();
        Node *parse_define();
        void node_destroy(Node *n);
};

#endif  // PARSER_H