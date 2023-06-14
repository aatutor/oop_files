// les05_13

#include <iostream>
#include <conio.h>
using namespace std;

void print()    // ничего не делает
{}

template <class First, class... Other>
void print(const First& first, const Other&... other)
{
    cout << first;
    print(other...);
}

template <class... Args>
void println(const Args&... args)
{
    print(args...);
    cout << endl;
}

struct Point
{
    int x;
    int y;

    friend std::ostream& operator<<(std::ostream& output, const Point& p)
    {
        output << "(" << p.x << "," << p.y << ")";
        return output;
    }
};

int main()
{
    println("Hello, world");
    println("Pi = ", 3.14, '\n', 2, " * ", 2, " = ", 2 * 2);
    
    Point point{ 12,2 };
    println("Point: ", point);

    _getch();
    return 0;
}
