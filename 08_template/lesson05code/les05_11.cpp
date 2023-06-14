// les05_11

#include <iostream>
#include <conio.h>
using namespace std;

int getSum(int count, int first, ...) 
{
    int sum = 0;
    int* p = &first;
    while (count--)
    {
        sum += *p;
        p++;
        p++;
    }
    return sum;
}

int main()
{
    int sum = getSum(5, 1, 2, 3, 4, 5);
    cout << "sum = " << sum << endl;
    sum = getSum(4, 25, 0, 5, 60);
    cout << "sum = " << sum << endl;

    _getch();
    return 0;
}
