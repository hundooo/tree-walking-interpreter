# tree-walking-interpreter
The aim of this project was to create a complete tree walking interpreter from scratch with the ability to interpret a subset of the racket programming language.
Currently the following features are supported
1. Evaluation of prefix notation expressions
2. User defined constants

In the future I intend to add support for anonymous lambda functions and tail recursion as well as extending the available binary operations.

## Setup
To use the interpreter you will require a C++ compiler such as GNU C++ compiler.

First, download all the files from this github repository then in windows cmd navigate to the folder containing this project.

For example, `C:\Users\hundo\tree-walking-interpreter>`.

Now run the following line in the cmd to compile the project into an executable file.

```
g++ src/token/Token.cpp src/lexer/Lexer.cpp src/ast/AST.cpp src/parser/Parser.cpp src/repl/REPL.cpp src/main/Main.cpp
```

Finally, to run the executable enter a.exe in the same file location.

## Usage
### Expressions
Expressions `[exp]` in the interpreter are of the form `[val]` or `([op] [exp] [exp])` where `[val]` is an integer and `[op]` is a binary operator for example `+`.

For example,

```
>> 5
5
```

```
>> (+ 5 7)
12
```

```
>> (+ (+ 1 (+ 2 3)) (+ 4 4))
14
```

### Constants
Constants are made using the `define` keyword and are of the form `(define [const] [exp])`.

For example,

```
>> (define x 5)
>> x
5
```

```
>> (define x 7)
>> (define y 9)
>> (+ x y) 
16
```
