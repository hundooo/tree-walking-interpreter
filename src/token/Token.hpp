#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <map>

extern const std::string eof;
extern const std::string ILLEGAL;
extern const std::string IDENT;
extern const std::string INT;
extern const std::string PLUS;
extern const std::string LPAREN;
extern const std::string RPAREN;
extern const std::string DEFINE;
extern const std::map<std::string, std::string> KEYWORDS;

std::string lookup_ident(std::string ident);

class Token { 
    public:
        std::string type_;
        std::string literal_;
        Token();
        Token(std::string type, std::string literal);
        std::string to_string();
};

#endif  // TOKEN_H
