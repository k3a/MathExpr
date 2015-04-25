
#include <iostream>
#include "MathExpr.h"

#define TEST(exprs) std::cout << #exprs << " : " << (expr.eval(#exprs, &vars).toNumber() == (exprs) ? "OK" : "FAIL") << std::endl;

int main()
{
    MathExpr expr;
    MathExpr::ValueMap vars;
    
    float pi = 3.14; vars["pi"] = pi;
    std::string str = "test"; vars["str"] = str;

    TEST( str == "test" );
    TEST( str == "xtest" );
    TEST( str == "test" && pi < 1 );
    TEST( str == "xtest" || pi > 1 );
    
    TEST( false || !(false && !false) );
    TEST( true || !(false && !false) );
    TEST( false || !(false && !false) && true );
    TEST( false || !(false && !false) && false );
    TEST( false || !(false && !false) && true || true );
    TEST( false || !(false && !false) && false || true );
    TEST( false || !(false && !false) && true || false );
    TEST( false || !(false && !false) && false || false );
    TEST( false || (false && !false) && true );
    TEST( false || (false && !false) && false );
    TEST( false || (false && !false) && true || true );
    TEST( false || (false && !false) && false || true );
    TEST( false || (false && !false) && true || false );
    TEST( false || (false && !false) && false || false );
    
    //float res = expr.calculate("false || !(false && !false)", &vars);
    //std::cout << "RESULT: " << res << std::endl;
    
    return 0;
}