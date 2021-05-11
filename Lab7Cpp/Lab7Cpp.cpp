#include "ConsoleProjectLib.h"
#include "ArithmeticExpression.h"

using namespace std;

int main()
{
    ProgramInfo();
    cout << endl;
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    while (cin.fail() || size < 0)
    {
        cin.clear();
        cin.ignore(8192, '\n');
        cout << "Enter the size of the array once more: " << endl;
        cin >> size;
    };
    ArithmeticExpression *expressions = new ArithmeticExpression[size];
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        bool reenter;
        do
        {
            reenter = false;
            double a, b, c;
            cout << "Enter the A" << i + 1 << ": " << endl;
            cin >> a;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(8192, '\n');
                cout << "Enter the A" << i + 1 << ": " << endl;
                cin >> a;
            };
            cout << "Enter the B" << i + 1 << ": " << endl;
            cin >> b;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(8192, '\n');
                cout << "Enter the B" << i + 1 << ": " << endl;
                cin >> b;
            };
            cout << "Enter the C" << i + 1 << ": " << endl;
            cin >> c;
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(8192, '\n');
                cout << "Enter the C" << i + 1 << ": " << endl;
                cin >> c;
            };
            try
            {                                                           // exceptions checking
                expressions[i].SetA(a);
                expressions[i].SetB(b);
                expressions[i].SetC(c);
                cout << "Result " << i + 1 << " = " << fixed << expressions[i].GetResult() << endl;
            }
            catch (const logic_error& exc)
            {
                cerr << exc.what() << endl;
                cout << "Please, enter the data once more" << endl;
                reenter = true;
            }
        } while (reenter);                                              // if an exception arose, reenter A, B and C
    }
    cout << "\nResults:" << endl;
    for (int i = 0; i < size; i++)
        cout << "Result " << i + 1 << " = " << fixed << expressions[i].GetResult() << endl;     // safe, because checked earlier
    cout << endl;
    delete[] expressions;
    system("pause");
}