// les05_14b

#include <iostream>
#include <initializer_list>
#include <conio.h>
using namespace std;

template <class T>
class DynArray
{
private:
    int length;
    T* data;

public:
    DynArray() : length(0), data(nullptr)
    {
    }

    DynArray(int length) : length(length)
    {
        data = new T[length];
    }

    DynArray(const std::initializer_list<T>& list) : DynArray(list.size())
    {
        int i = 0;
        for (auto& element : list)
        {
            data[i] = element;
            i++;
        }
    }

    ~DynArray()
    {
        delete[] data;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    int getLength() const
    {
        return length;
    }
};

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
    DynArray<int> intArray{ 7, 6, 5, 4, 3, 2, 1 };
    for (int i = 0; i < 7; i++)
    {
        cout << intArray[i] << ' ';
    }
    cout << endl;

    DynArray<Point> pointArray{ Point{1,1}, Point{7, 7}, Point{3,3} };
    for (int i = 0; i < 3; i++)
    {
        cout << pointArray[i] << ' ';
    }
    cout << endl;

    _getch();
    return 0;
}

