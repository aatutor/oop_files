#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point() = default;
    Point(int pX, int pY) : x{ pX }, y{ pY } {}
    Point& setX(int pX) { x = pX; return *this; }
    Point& setY(int pY) { y = pY; return *this; }

    void showPoint() const
    {
        std::cout << '(' << x << ',' << y << ')';
    }

    explicit operator bool() const { return x and y; }
};

int main()
{
    const int pointsCount{ 3 };
    Point points[pointsCount]{ {0,0}, {28,29}, {0,26} };

    bool isZero{ false };

    for (auto point{ points }, pointsEnd{ points + pointsCount }; point != pointsEnd; ++point)
    {
        isZero = (bool)*point; /* использовано для наглядной демонстрации необходимости явного преобразования типа*/

        if (*point)
        {
            std::cout << "Zero Point detected!\n";
        }
        else
        {
            point->showPoint();
            std::cout << '\n';
        }
    }

    return 0;
}