// les05_09

#include <iostream>
#include <conio.h>
using namespace std;

template <typename T1, typename T2>
struct Pair
{
    T1 first;
    T2 second;
    Pair() : first(T1()), second(T2()) {};
    Pair(const T1& x, const T2& y) : first{x}, second{y}{}

    void display()
    {
        cout << "(" << first << "," << second << ")";
    }

    bool operator==(const Pair& pair)
    {
        return this->first == pair.first &&
            this->second == pair.second;
    }

    bool operator!=(const Pair& pair)
    {
        return !(*this == pair);
    }
};

int main()
{
    Pair<int, int>point1(0, 0);
    Pair<int, int>point2(1, 1);
    point1.display();
    cout << " ";
    point2.display();
    cout << " ";
    cout << (point1 == point2 ? "equals" : "not equals") << endl;

    Pair<int, int> point;
    point.display();
    cout << " ";
    point1.display();
    cout << " ";
    cout << (point != point1 ? "not equals" : "equals") << endl;

    Pair<string, string> name("John", "Smith");
    Pair <Pair<string, string> , int > mark(name, 8);
    mark.first.display();
    cout << " : " << mark.second << endl;
    _getch();
    return 0;
}
