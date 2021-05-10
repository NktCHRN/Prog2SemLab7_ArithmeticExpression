#pragma once
#include <cmath>
#include "DivideByZeroException.h"
#include <sstream>
#include <string>

class ArithmeticExpression
{
private:
    double _a;                            // A, B, C
    double _b;
    double _c;
public:
    double GetA();                        // Getters and setters for A, B, C
    double GetB();
    double GetC();
    void SetA(double a);
    void SetB(double b);
    void SetC(double c);
    ArithmeticExpression();                                       // standard constructor
    ArithmeticExpression(double a, double b, double c);           // constructor with parameters
    double GetResult();                                           // get a result
};