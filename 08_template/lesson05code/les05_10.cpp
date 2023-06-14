// les05_10
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Tree.h"
using namespace std;

struct Point
{
    int x;
    int y;

    friend bool operator>(const Point& p1, const Point& p2)
    {
        int d1 = p1.x + p1.y;
        int d2 = p2.x + p2.y;
        return d1 > d2;
    }

    friend bool operator<(const Point& p1, const Point& p2)
    {
        return !(p1 > p2);
    }

    friend std::ostream& operator<<(std::ostream& output, const Point& p)
    {
        output << "(" << p.x << "," << p.y << ")";
        return output;
    }
};

int main() 
{
    int n = 10;
    Tree<int> intTree;

    cout << "Integer values:" << endl;
    for (int i = 0; i < 10; i++) 
    {
        int value = rand() % 100;
        cout << value << " ";
        intTree.insertNode(value);
    }
    cout << endl;

    cout << "Ordered values:" << endl; 
    intTree.Display();
    cout << endl;

    Tree<Point> pointTree;

    cout << "Point values:" << endl;
    for (int i = 0; i < 10; i++)
    {
        Point point = Point{ rand() % 20, rand() % 20 };
        cout << point << " ";
        pointTree.insertNode(point);
    }
    cout << endl;

    cout << "Ordered values:" << endl;
    pointTree.Display();
    cout << endl;

    _getch();
    return 0;
}
