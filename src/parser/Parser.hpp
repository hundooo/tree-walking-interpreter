#ifndef PARSER_H
#define PARSER_H

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
        Node parse();
};

#endif  // PARSER_H