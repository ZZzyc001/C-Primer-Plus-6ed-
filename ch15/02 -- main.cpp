//error4.cpp
#include <iostream>
#include <cmath>
#include <stdexcept>

class HmeanExcp : public std::logic_error
{
public:
    HmeanExcp() : std::logic_error("hmean() invalid arguments: a = -b\n") {}
};

class GmeanExcp : public std::logic_error
{
public:
    GmeanExcp() : std::logic_error("gmean() arguments should be >= 0\n") {}
};

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        {
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (HmeanExcp& he)
        {
            cout << he.what();
            cout << "Try again.\n";
            continue;
        }
        catch (GmeanExcp& ge)
        {
            cout << ge.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
        throw HmeanExcp();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw GmeanExcp();
    return std::sqrt(a * b);
}
