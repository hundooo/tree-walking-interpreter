#include <stdio.h>
#include <string>
#include <iostream>
#include "src/lexer/Lexer.hpp"
#include "src/token/Token.hpp"

int main() { 
    std::string input = "(define ten (+ 3 7)) (+ 1 8)";
    Token tests[13];
    Lexer l = Lexer(input);
    
    tests[0] = Token(LPAREN, "(");
    tests[1] = Token(DEFINE, "define");
    tests[2] = Token(IDENT, "ten");
    tests[3] = Token(LPAREN, "(");
    tests[4] = Token(PLUS, "+");
    tests[5] = Token(INT, "3");
    tests[6] = Token(INT, "7");
    tests[7] = Token(RPAREN, ")");
    tests[8] = Token(RPAREN, ")");
    tests[9] = Token(LPAREN, "(");
    tests[10] = Token(PLUS, "+");
    tests[11] = Token(INT, "1");
    tests[12] = Token(INT, "8");
    tests[13] = Token(RPAREN, ")");

    bool flag = true;
    for (int i = 0; i < 13; ++i) { 
        Token tt = tests[i];
        Token tok = l.next_token();

        if (!tok.type_.compare(tt.type_)) {
            //System.out.println("tests[" + i + "]" + "- tokentype wrong. expected=" + tt.type + ", got=" + tok.type);
            std::cout << "tests[" << i << "]- token type wrong. expected=" << tt.type_ << ", got=" << tok.type_;
            flag = false;
        }

        if (!tok.literal_.compare(tt.literal_)) { 
            //System.out.println("tests[" + i + "]" + "- literal wrong. expect=" + tt.literal + ", got=" + tok.literal);
            std::cout << "tests[" << i << "]- literal wrong. expected=" << tt.literal_ << ", got=" << tok.literal_;
            flag = false;
        }
    }
    printf("%s", flag ? "ALL TESTS PASSED" : "FAIL");
}