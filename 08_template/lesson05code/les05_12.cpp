// les05_12

#include <iostream>
#include <conio.h>
using namespace std;

double getSum(double x)
{
    return x;
}

template<class... Args>
double getSum(double x, Args... args)
{
    return x + getSum(args...);
}

int main()
{
    double sum = getSum(1, 2, 3, 4, 5);
    cout << "sum = " << sum << endl;

    sum = getSum(25, 0, 5, 60);
    cout << "sum = " << sum << endl;

    _getch();
    return 0;
}
