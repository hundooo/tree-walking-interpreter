#include <string>
#include "Lexer.hpp"
#include "token/Token.hpp"

Lexer::Lexer(std::string input) : input_(input) {read_char();}

void Lexer::read_char() {
    if (read_position_ >= input_.length()) {
        ch_ = 0;
    } else {
        ch_ = input_.at(read_position_);
    }
    position_ = read_position_;
    read_position_ += 1;
}

void Lexer::eat_white_space() { 
    while (ch_ == ' ' || ch == '\t' || ch == '\n' || ch == '\r') { 
        read_char();
    }
}

char Lexer::peek_char() { 
    if (read_position_ >= input_.length()) { 
        return 0;
    } else { 
        return input_.at(read_position_);
    }
}

bool Lexer::is_letter(char ch) { 
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '-';
}

bool Lexer::is_digit(char ch) { 
    return '0' <= ch && ch <= '9';
}

std::string Lexer::read_identifier() { 
    int position = position_;
    while (is_letter(ch_)) { 
        read_char();
    }
    return input_.substr(position, position_);
}

std::string Lexer::read_number() { 
    int position = position_;
    while (is_digit(ch_)) { 
        read_char();
    }
    return input_.substr(position, position_);
}

Token Lexer::next_token() { 
    Token tok;

    eat_white_space();

    switch(ch_) {
        case '(':
        case ')':
        case '+':
        case 0:
        default:

    }

    read_char();
    return tok;
}