#ifndef TOKEN_H
#define TOKEN_H

extern const std::string eof;
extern cosnt std::string IDENT;
extern const std::string INT;
extern const std::string PLUS;
extern const std::string LPAREN;
extern const std::string RPAREN;
extern const std::string DEFINE;

class Token { 
    public:
        std::string type_;
        std::string literal_;
        Token(std::string type, std::string literal); 
};

#endif  // TOKEN_H