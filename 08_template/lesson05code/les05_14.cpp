// les05_14
#include <iostream>
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
    IntArray array{ 7, 6, 5, 4, 3, 2, 1 }; // эта строка вызывает ошибку компил€ции
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;

    _getch();
    return 0;
}

