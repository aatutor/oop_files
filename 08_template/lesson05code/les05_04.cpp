//les05_04

#include <iostream>
#include <conio.h>
using namespace std;

template <class T, int size> // size является параметром non-type в шаблоне класса
class StatArray
{
private:
    // Параметр non-type в шаблоне класса отвечает за размер выделяемого массива
    T m_array[size];

public:
    T* getArray();

    T& operator[](int index)
    {
        return m_array[index];
    }
};

// Синтаксис определения шаблона метода и самого метода вне тела класса с параметром non-type
template <class T, int size>
T* StatArray<T, size>::getArray()
{
    return m_array;
}

int main()
{
    cout << "Class Tempate with Non-type parameters" << endl << endl;

    // Объявляем целочисленный массив из 10 элементов
    const int size = 10;
    StatArray<int, size> intArray;

    // Заполняем массив значениями
    for (int count = 0; count < size; ++count)
        intArray[count] = count;

    // Выводим элементы массива в обратном порядке 
    for (int count = size - 1; count >= 0; --count)
        std::cout << intArray[count] << " ";
    std::cout << '\n';

    // Объявляем массив типа double из 8 элементов
    StatArray<double, 8> doubleArray;

    // Заполняем массив значениями
    for (int count = 0; count < 8; ++count)
        doubleArray[count] = 5.5 + 0.1 * count;

    // Выводим элементы массива 
    for (int count = 0; count < 8; ++count)
        std::cout << doubleArray[count] << ' ';

    _getch();
    return 0;
}
