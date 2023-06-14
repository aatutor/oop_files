#include <iostream>
using namespace std;

template<class T>
void display(T array[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template<class T>
void sort(T array[], size_t size)
{
    for (int k = size - 1; k > 0; k--)
    {
        for (int j = 0; j < k; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

