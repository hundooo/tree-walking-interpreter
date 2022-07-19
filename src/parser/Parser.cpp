#include "Parser.hpp"
#include "../token/Token.hpp"
#include "../lexer/Lexer.hpp"
#include "../ast/AST.hpp"

Parser::Parser(Lexer l) : l_(l) {next_token(); next_token();}

void Parser::next_token() { 
    cur_token_ = peek_token_;
    peek_token_ = l_.next_token();
}

std::vector<Node> Parser::parse() {
    std::vector<Node> root;
    while (cur_token_.type_ != eof) {
        if (cur_token_.type_ == INT) {
            Node node = Node(std::stoi(cur_token_.literal_));
            root.push_back(node);
            next_token();
        } else if (cur_token_.type_ == LPAREN) {
            if (peek_token_.type_ == PLUS) { 

            }
        }
    }
    return root;
}
