using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArithmeticExpressionLib
{
    public class ArithmeticExpression
    {
        public double A { get; set; }               // A, B, C with getters and setters
        public double B { get; set; }
        public double C { get; set; }
        public ArithmeticExpression()               // standard constructor
        {
            A = 0;
            B = 0;
            C = 0;
        }
        public ArithmeticExpression(double a, double b, double c)           // constructor with parameters
        {
            A = a;
            B = b;
            C = c;
        }
        public double GetResult()
        {
            double numerator, denominator;
            if (A * B > -2)                             // check whether A * B + 2 > 0 (for natural logarythm)
            {
                numerator = Math.Log(A * B + 2) * C;
            }
            else
            {
                throw new ArgumentException($"{nameof(A)} * {nameof(B)} can`t be smaller than or equal -2. It was {A * B:F6}");
            }
            if (C != 0)                                 // check if C (the denominator for B / C) is equal zero
            {
                denominator = 41 - B / C + 1;
            }
            else
            {
                throw new DivideByZeroException($"{nameof(C)} can`t be equal zero");
            }
            if (denominator != 0)                       // check if the denominator is equal zero
            {
                return numerator / denominator;
            }
            else
            {
                throw new DivideByZeroException($"{nameof(denominator)} can`t be equal zero");
            }
        }
    }
}
