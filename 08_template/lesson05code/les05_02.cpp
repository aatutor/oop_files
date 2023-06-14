//les05_02

#include <iostream>
#include <conio.h>
using namespace std;

void stopProgram(string message)
{
    cout << message << endl;
    cout << "Press any key to exit program" << endl;
    _getch();
    exit(1);
}

template<class T>
class Array
{
    static const size_t size{ 5 };
    T arr[size];

public:
    Array()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = T();
        }
    }

    int getSize() const
    {
        return size;
    }

    T getItem(size_t index) const
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        else
        {
            stopProgram("Index is out of range!");
        }
    }

    void setItem(size_t index, T value)
    {
        if (index >= 0 && index < size)
        {
            arr[index] = value;
        }
        else
        {
            stopProgram("Index is out of range!");
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void sort()
    {
        for (int k = size - 1; k > 0; k--)
        {
            for (int j = 0; j < k; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

int main()
{
    cout << "Class Tempate Array" << endl << endl;

    Array<int> intArray;
    cout << "int Array initialization:" << endl;
    intArray.display();
    int size = intArray.getSize();
    for (int i = size; i > 0; i--)
    {
        intArray.setItem(size - i, i);
    }
    cout << endl << "int Array after assignment:" << endl;
    intArray.display();
    intArray.sort();
    cout << endl << "int Array after ordering:" << endl;
    intArray.display();
    cout << endl;

    Array<string> strArray;
    cout << "str Array initialization:" << endl;
    strArray.display();
    strArray.setItem(0, "two");
    strArray.setItem(1, "seven");
    strArray.setItem(2, "zero");
    strArray.setItem(3, "four");
    strArray.setItem(4, "one");
    cout << endl << "str Array after assignment:" << endl;
    strArray.display();
    strArray.sort();
    cout << endl << "str Array after ordering:" << endl;
    strArray.display();

    cout << endl << "Press any key to exit program" << endl;
    _getch();
    return 0;
}
