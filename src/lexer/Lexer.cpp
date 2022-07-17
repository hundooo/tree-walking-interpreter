#include <string>
#include "Lexer.hpp"
#include "../token/Token.hpp"

Lexer::Lexer(std::string input) : input_(input), position_(0), read_position_(0), ch_(0) {read_char();}

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
    while (ch_ == ' ' || ch_ == '\t' || ch_ == '\n' || ch_ == '\r') { 
        read_char();
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
    return input_.substr(position, position_ - position);
}

std::string Lexer::read_number() { 
    int position = position_;
    while (is_digit(ch_)) { 
        read_char();
    }
    return input_.substr(position, position_ - position);
}

Token Lexer::next_token() { 
    Token tok = Token("", "");
    eat_white_space();

    switch(ch_) {
    case '(':
        tok = Token(LPAREN, std::string(1, ch_));
        break;
    case ')':
        tok = Token(RPAREN, std::string(1, ch_));
        break;
    case '+':
        tok = Token(PLUS, std::string(1, ch_));
        break;
    case 0:
        tok = Token(eof, "");
        break;
    default:
        if (is_letter(ch_)) {
            std::string literal = read_identifier();
            std::string type = lookup_ident(literal);
            tok = Token(type, literal);
            return tok;
        } else if (is_digit(ch_)) { 
            tok = Token(INT, read_number());
            return tok;
        } else {
            tok = Token(ILLEGAL, std::string(1, ch_));
        }
    }

    read_char();
    return tok;
}