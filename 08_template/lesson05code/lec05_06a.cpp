// les05_06a

#include <iostream>
#include <conio.h>
using namespace std;

template <class T>
T Max(T t1, T t2)
{
    return (t1 > t2 ? t1 : t2);
}

template <>
const char* Max<const char*>(const char* t1, const char* t2)
{
    return (strcmp(t1, t2) > 0 ? t1 : t2);
}

int main()
{
    int i1 = 10;
    int i2 = 20;
    double d1 = 10.0;
    double d2 = 20.0;
    string s1 = "hi";
    string s2 = "bye";
    const char* p1 = "hi";
    const char* p2 = "bye";
    cout << Max(i1, i2) << endl;
    cout << Max(d1, d2) << endl;
    cout << Max(s1, s2) << endl;
    cout << Max(p1, p2) << endl;

    _getch();
    return 0;
}
