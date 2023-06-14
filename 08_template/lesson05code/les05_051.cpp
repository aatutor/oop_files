// les05_051

#include <iostream>
#include <conio.h>
using namespace std;

template< typename T >
void Display(T value)
{
    cout << value << endl;
}

template< typename T >
T Sum(T value1, T value2)
{
    return value1 + value2;
}

struct Point
{
    int x;
    int y;
};

int main()
{
    cout << "Template Requirements" << endl;

    int n1 = 1;
    int n2 = 2;
    int n3 = Sum(n1, n2);

    Display(n1);
    Display(n3);

    double d1 = 1.0;
    double d2 = 2.0;
    double d3 = Sum(d1, d2);

    Display(d1);
    Display(d3);

    Point p1{ 1,1 };
    Point p2{ 2,2 };
    //Point p3 = Sum(p1, p2);

    //Display(p1);
    //Display(p3);

    _getch();
    return 0;
}
