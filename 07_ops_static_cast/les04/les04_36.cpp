#include <iostream>

class Rectangle;

class Point
{
    int x;
    int y;
public:
    Point() = default;
    Point(int pX, int pY) : x{ pX }, y{ pY } {}
    Point& setX(int pX) { x = pX; return *this; }
    Point& setY(int pY) { y = pY; return *this; }
    int getX()const { return x; }
    int getY()const { return y; }
    void show() const
    {
        std::cout << '(' << x << ',' << y << ')';
    }

    Point& inputPrompt() { std::cout << "Enter point coordinates x and y\n"; return *this; }
    friend std::ostream& operator<<(std::ostream& out, const Point& point);
    friend std::istream& operator>>(std::istream& in, Point& point);

    friend Rectangle;
};

class Rectangle
{
    Point leftUpCorner;
    Point rightDownCorner;

public:
    Rectangle() = default;
    Rectangle(const Point& leftUpCornerP, int sideAP, int sideBP)
        : leftUpCorner{ leftUpCornerP },
        rightDownCorner{ leftUpCornerP.x + sideAP, leftUpCorner.y + sideBP }
    {}
    Rectangle(const Point& leftUpCornerP, const Point& rightDownCornerP)
        : leftUpCorner{ leftUpCornerP },
        rightDownCorner{ rightDownCornerP }
    {}

    int getSideA() const { return rightDownCorner.x - leftUpCorner.x; }
    int getSideB() const { return rightDownCorner.y - leftUpCorner.y; }

    friend std::ostream& operator<<(std::ostream& out, const Rectangle& rectangle);
};

std::ostream& operator<<(std::ostream& out, const Point& point)
{
    out << '(' << point.x << ',' << point.y << ')';
    return out;
}

std::istream& operator>>(std::istream& in, Point& point)
{
    in >> point.x >> point.y;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& rectangle)
{
    out << "[ " << rectangle.leftUpCorner << ' '
        << rectangle.getSideA()
        << " X "
        << rectangle.getSideB()
        << ' ' << rectangle.rightDownCorner
        << " ]";
    return out;
}

int main()
{
    Rectangle rect1{ {0,0}, 10 ,5 };
    Rectangle rect2{ {0,0}, {10,10} };

    std::cout << "Rectangle 1 " << rect1 << '\n' << "Rectangle 2 " << rect2 << '\n';

    return 0;
}