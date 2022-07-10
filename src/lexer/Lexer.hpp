#ifndef LEXER_H
#define LEXER_H

class Lexer { 
    public:
        std::string input;
        int position;
        int read_position;
        char ch;
        Lexer(std::string input);
        void read_char();
        void eat_white_space();
        char peek_char();
        boolean is_letter(char ch);
        boolean is_digit(char ch);
        std::string read_identifier();
        std::string read_number();
        Token next_token();
}

#endif  // LEXER_H