#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point& setX(int pX) { x = pX; return *this; }
    Point& setY(int pY) { y = pY; return *this; }

    void showPoint() const
    {
        std::cout << '(' << x << ',' << y << ')';
    }
};
int main()
{
    Point p0;

    p0.setX(10).setY(20);
    p0.showPoint();
    std::cout << '\n';

    return 0;
}