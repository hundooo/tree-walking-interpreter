#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "../src/token/Token.hpp"
#include "../src/lexer/Lexer.hpp"
#include "../src/ast/AST.hpp"
#include "../src/parser/Parser.hpp"

void printBT(const std::string& prefix, const Node* node, bool isLeft) {
    if(node != NULL) {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        if (node->left_ == NULL && node->right_ == NULL) { 
            std::cout << node->val_ << std::endl;
        } else {
            std::cout << node->oper_ << std::endl;
        }

        printBT(prefix + (isLeft ? "│   " : "    "), node->m_left, true);
        printBT(prefix + (isLeft ? "│   " : "    "), node->m_right, false);
    }
}

void printBT(const Node* node) {
    printBT("", node, false);    
}


int main() { 
    std::string input = "(+ 5 7)";
    std::vector<Token> tests;
    Lexer l = Lexer(input);
    Parser p = Parser(l);
    std::vector<Node *> root = p.parse();

    bool flag = true;
    if (root.size() != 1) {
        printf("FAIL -> missing statements\n");
    }

    for (int i = 0; i < root.size(); ++i) { 

    }

    printf("%s", flag ? "ALL TESTS PASSED" : "FAIL");
}