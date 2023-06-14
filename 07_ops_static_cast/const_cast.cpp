#include <iostream>
using namespace std;



int main ()
{
    const int* x = new int(5);
    cout << *x << endl;
    int* y = const_cast<int*>(x);
    *y = 3;
    cout << *x << endl;
    return 0;
}
