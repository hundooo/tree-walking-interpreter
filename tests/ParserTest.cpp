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
        std::cout << prefix << (isLeft ? "|--" : "\\--" );

        if (node->left_ == NULL && node->right_ == NULL) { 
            std::cout << node->val_ << std::endl;
        } else {
            std::cout << node->oper_ << std::endl;
        }

        printBT(prefix + (isLeft ? "|   " : "    "), node->left_, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right_, false);
    }
}

void printBT(const Node* node) {
    printBT("", node, false);    
}

int main() { 
    std::string input = "(+ (+ 6 3) (+ 1 4))";
    Lexer l = Lexer(input);
    Parser p = Parser(l);

    Node *node = p.parseExpression();
    printBT(node);
    p.node_destroy(node);
}