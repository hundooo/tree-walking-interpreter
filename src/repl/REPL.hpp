#ifndef REPL_H
#define REPL_H

#include <string>
#include "../ast/AST.hpp"

class REPL { 
    public: 
        const std::string PROMPT;
        REPL();
        void start();
        int eval(Node *n);
};

#endif  // REPL_H