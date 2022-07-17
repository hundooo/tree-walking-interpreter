#ifndef LEXER_H
#define LEXER_H

#include "../token/Token.hpp"

class Lexer { 
    public:
        std::string input_;
        int position_;
        int read_position_;
        char ch_;
        Lexer(std::string input);
        void read_char();
        void eat_white_space();
        bool is_letter(char ch);
        bool is_digit(char ch);
        std::string read_identifier();
        std::string read_number();
        Token next_token();
};

#endif  // LEXER_H