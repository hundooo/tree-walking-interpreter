#include <string>
#include <map>
#include "Token.hpp"

const std::string eof = "EOF";
const std::string ILLEGAL = "ILLEGAL";
const std::string IDENT = "IDENT";
const std::string INT = "INT";
const std::string PLUS = "+";
const std::string LPAREN = "(";
const std::string RPAREN = ")";
const std::string DEFINE = "define";
const std::map<std::string, std::string> KEYWORDS = {{"define", DEFINE}};

Token::Token() : type_(""), literal_("") {}

Token::Token(std::string type, std::string literal) : type_(type), literal_(literal) {}

std::string lookup_ident(std::string ident) { 
    if (KEYWORDS.find(ident) != KEYWORDS.end()) { 
        return KEYWORDS.find(ident)->second;
    }
    return IDENT;
}

std::string Token::to_string() { 
    return "{Type:" + type_ + " Literal:" + literal_ + "}";
}
