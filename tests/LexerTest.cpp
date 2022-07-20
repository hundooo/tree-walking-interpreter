#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "../src/token/Token.hpp"
#include "../src/lexer/Lexer.hpp"

int main() { 
    std::string input = "(+ 3 5)";
    std::vector<Token> tests;
    Lexer l = Lexer(input);

    tests.push_back(Token(LPAREN, "("));
    tests.push_back(Token(PLUS, "+"));
    tests.push_back(Token(INT, "3"));
    tests.push_back(Token(INT, "5"));
    tests.push_back(Token(RPAREN, ")"));

    bool flag = true;
    for (int i = 0; i < tests.size(); ++i) { 
        Token tt = tests.at(i);
        Token tok = l.next_token();

        if (tok.type_.compare(tt.type_)) { //
            std::cout << "tests[" << i << "] - token type wrong. expected=" << tt.type_ << ", got=" << tok.type_ << "\n";
            flag = false;
        }

        if (tok.literal_.compare(tt.literal_)) { //
            std::cout << "tests[" << i << "] - literal wrong. expected=" << tt.literal_ << ", got=" << tok.literal_ << "\n";
            flag = false;
        }
    }
    printf("%s", flag ? "ALL TESTS PASSED" : "FAIL");
}