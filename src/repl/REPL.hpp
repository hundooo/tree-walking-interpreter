#ifndef REPL_H
#define REPL_H

#include <unordered_map>
#include <string>
#include "../ast/AST.hpp"

class REPL { 
    public: 
        const std::string PROMPT;
        std::unordered_map<std::string, Node *> constants;
        REPL();
        void start();
        int eval(Node *n);
        void add_constant(Node *n);
};

#endif  // REPL_H