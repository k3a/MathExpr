# MathExpr
A simple form of mathematical expression parsing can take a string such
as `-pi+1` on input and output `-2.14`.

This project is a C++ class which parses a character sequence as an expression using Dijkstra's
[Shunting-yard algorithm](http://en.wikipedia.org/wiki/Shunting-yard_algorithm).

Based on [bamos/cpp-expression-parser](https://github.com/bamos/cpp-expression-parser/).

Improved in several ways:
- supports boolean operators: >, >=, <, <=, &&, ||, !
- supports boolean constants true and false
- basic support for strings so it's possible to compare them: str == "test" || str == 'test'
- Token (value) struct now contains either float number or std:string

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

