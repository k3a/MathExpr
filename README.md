# MathExpr
A simple form of mathematical expression parsing can take a string such
as `-pi+1` on input and output `-2.14`.

This project is a C++ class which parses a character sequence as an expression using Dijkstra's
[Shunting-yard algorithm](http://en.wikipedia.org/wiki/Shunting-yard_algorithm).

Based on [bamos/cpp-expression-parser](https://github.com/bamos/cpp-expression-parser/) to make a single-file alternative with additional functionality:
- support for boolean operators: >, >=, <, <=, &&, ||, !
- support for boolean constants true and false
- basic support for strings so it's possible to compare them: str == "test" || str == 'test'
- wildcards matching support operators =~, !~: str =~ 't*s*'
- token (value) struct containing either float number or std:string

# ![#f03c15](https://placehold.it/15/f03c15/000000?text=+) `Deprecated`

Over time, [bamos/cpp-expression-parser](https://github.com/bamos/cpp-expression-parser/) improved and it looks like all these features are now part of it so I recommend you use that instead. This repo will be kept for compatibility reasons and eventual security fixes.

# Minimal example.

```C
#include <iostream>
#include "MathExpr.h"

int main() {
  MathExpr expr;
  
  MathExpr::ValueMap vars;
  vars["pi"] = 3.14;
  vars["str"] = "test";
  
  float val = expr.eval("str == 'test'", &vars).toNumber();
  std::cout << (val?"true":"false") << std::endl;
  
  return 0;
}
```

File main.cpp contains some basic tests.

# License
MIT

