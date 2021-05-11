#include "ArithmeticExpression.h"

double ArithmeticExpression::GetA() {
	return _a;
}

double ArithmeticExpression::GetB() {
	return _b;
}

double ArithmeticExpression::GetC() {
	return _c;
}

void ArithmeticExpression::SetA(double a) {
	_a = a;
}

void ArithmeticExpression::SetB(double b) {
	_b = b;
}

void ArithmeticExpression::SetC(double c) {
	_c = c;
}

ArithmeticExpression::ArithmeticExpression()                                        // standard constructor
{
    _a = 0;
    _b = 0;
    _c = 0;
}
ArithmeticExpression::ArithmeticExpression(double a, double b, double c)           // constructor with parameters
{
    _a = a;
    _b = b;
    _c = c;
}
double ArithmeticExpression::GetResult()
{
    double numerator, denominator;
    if (_a * _b > -2)                             // check whether A * B + 2 > 0 (for natural logarythm)
    {
        numerator = std::log(_a * _b + 2) * _c;
    }
    else
    {
        std::stringstream s;
        s << "A * B can`t be smaller than or equal -2. It was " << std::fixed << (_a * _b);
        throw std::logic_error(s.str());
    }
    if (_c != 0)                                 // check if C (the denominator for B / C) is equal zero
    {
        denominator = 41 - _b / _c + 1;
    }
    else
    {
        throw DivideByZeroException("C can`t be equal zero");
    }
    if (denominator != 0)                       // check if the denominator is equal zero
    {
        return numerator / denominator;
    }
    else
    {
        throw DivideByZeroException("Denominator can`t be equal zero");
    }
}