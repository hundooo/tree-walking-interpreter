#include <iostream>
#include <string>
#include <vector>
#include "REPL.hpp"
#include "../lexer/Lexer.hpp"
#include "../parser/Parser.hpp"
#include "../ast/AST.hpp"

REPL::REPL() : PROMPT(">>") {}

void REPL::start() { 
    while (true) { 
        std::cout << PROMPT;

        std::string line;
        std::getline(std::cin, line);

        if (!line.compare("")) { 
            break;
        }

        Lexer l = Lexer(line);
        Parser p = Parser(l);
        std::vector<Node *> root = p.parse();

        for (int i = 0; i < root.size(); ++i) {
            printf("%d\n", eval(root[i]));
            p.node_destroy(root[i]);
        }
    }
}

int REPL::eval(Node *n) { 
    if (n->left_ == NULL && n->right_ == NULL) { 
        return n->val_;
    } else {
        if (n->oper_ == "+") { 
            return eval(n->left_) + eval(n->right_);
        } else {
            return -1;
        }
    }
}
