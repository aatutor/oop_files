// les05_14a

#include <iostream>
#include <initializer_list>
#include <conio.h>
using namespace std;

class IntArray
{
private:
    int length;
    int* data;

public:
    IntArray() : length(0), data(nullptr)
    {
    }

    IntArray(int length) : length(length)
    {
        data = new int[length];
    }

    IntArray(const std::initializer_list<int>& list) : IntArray(list.size())
    {
        int i = 0;
        for (auto& element : list)
        {
            data[i] = element;
            i++;
        }
    }

    ~IntArray()
    {
        delete[] data;
    }

    int& operator[](int index)
    {
        return data[index];
    }

    int getLength() const
    {
        return length;
    }
};

int main()
{
    IntArray array{ 7, 6, 5, 4, 3, 2, 1 };
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;

    _getch();
    return 0;
}

