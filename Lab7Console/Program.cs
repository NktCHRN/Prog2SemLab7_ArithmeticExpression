using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ArithmeticExpressionLib;

namespace Lab7CS
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Lab №7";
            ProgramInfo();
            Console.WriteLine();
            int size;
            bool parsed;
            do
            {
                Console.WriteLine("Enter the size of the array: ");
                parsed = int.TryParse(Console.ReadLine(), out size);
            } while (!parsed || size < 0);
            ArithmeticExpression[] expressions = new ArithmeticExpression[size];
            Console.WriteLine();
            for(int i = 0; i < size; i++)
            {
                bool reenter;
                do
                {
                    reenter = false;
                    double a, b, c;
                    do
                    {
                        Console.WriteLine($"Enter the A{i + 1}: ");
                        parsed = double.TryParse(Console.ReadLine().Replace('.', ','), out a);
                    } while (!parsed);
                    do
                    {
                        Console.WriteLine($"Enter the B{i + 1}: ");
                        parsed = double.TryParse(Console.ReadLine().Replace('.', ','), out b);
                    } while (!parsed);
                    do
                    {
                        Console.WriteLine($"Enter the C{i + 1}: ");
                        parsed = double.TryParse(Console.ReadLine().Replace('.', ','), out c);
                    } while (!parsed);
                    try
                    {                                                           // exceptions checking
                        expressions[i] = new ArithmeticExpression(a, b, c);
                        Console.WriteLine($"Result {i + 1} = {expressions[i].GetResult():F6}");
                    }
                    catch (ArgumentException exc)
                    {
                        Console.WriteLine(exc.Message);
                        Console.WriteLine("Please, enter the data once more");
                        reenter = true;
                    }
                    catch (DivideByZeroException exc)
                    {
                        Console.WriteLine(exc.Message);
                        Console.WriteLine("Please, enter the data once more");
                        reenter = true;
                    }
                } while (reenter);                                              // if an exception arose, reenter A, B and C
            }
            Console.WriteLine("\nResults: ");
            for (int i = 0; i < size; i++)
                Console.WriteLine($"Result {i + 1} = {expressions[i].GetResult():F6}");     // safe, because checked on exceptions earlier
            Console.WriteLine("\nPress ENTER to quit");
            Console.Read();
        }
        static void ProgramInfo()                                       // prints information about the program
        {
            Console.WriteLine("Lab №7. Nikita Chernikov, IS-02");
            Console.WriteLine("Researching of the mechanism of exceptions");
            Console.WriteLine("Variant 15");
        }
    }
}
