//error4.cpp
#include <iostream>
#include <cmath>
#include <string>
#include <stdexcept>

class arg_error : public std::logic_error
{
private:
    double arg1;
    double arg2;
    std::string fname;
public:
    arg_error(double a1 = 0.0, double a2 = 0.0, std::string f = "none",
        std::string msg = "invalid arguments\n")
        : logic_error(msg), arg1(a1), arg2(a2), fname(f) {}
    void mesg() const;
};

class hmean_error : public arg_error
{
public:
    hmean_error(double a1 = 0.0, double a2 = 0.0, std::string f = "none",
        std::string msg = "invalid arguments\n")
        : arg_error(a1, a2, f, msg) {}
};

class gmean_error : public arg_error
{
public:
    gmean_error(double a1 = 0.0, double a2 = 0.0, std::string f = "none",
        std::string msg = "invalid arguments\n")
        : arg_error(a1, a2, f, msg) {}
};

inline void arg_error::mesg() const
{
    std::cout << arg1 << ", " << arg2 << ", " << fname << std::endl;
}

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
        catch (hmean_error& he)
        {
            he.mesg();
            cout << "Try again.\n";
            continue;
        }
        catch (gmean_error& ge)
        {
            ge.mesg();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
        catch (arg_error& ae)
        {
            ae.mesg();
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
        throw hmean_error(a, b, "hmean()");
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw gmean_error(a, b, "gmean()");
    return std::sqrt(a * b);
}
