//les05_01a

#include <iostream>
#include <conio.h>
using namespace std;

template<class T>
void display(T array[], size_t size);

template<class T>
void sort(T array[], size_t size);


int main()
{
    cout << "Sort Template" << endl << endl;

    int intArray[]{ 1, 3, 7, -4, -2, 4 };
    int size = sizeof(intArray) / sizeof(int);
    cout << "Original int Array : ";
    display<int>(intArray, size);
    sort<int>(intArray, size);
    cout << "Sorted   int Array : ";
    display<int>(intArray, size);

    char chrArray[]{ 'o', 't', 't', 'f', 'f', 's', 's', 'e', 'n' };
    size = sizeof(chrArray) / sizeof(char);
    cout << "Original chr Array : ";
    display<char>(chrArray, size);
    sort<char>(chrArray, size);
    cout << "Sorted   chr Array : ";
    display<char>(chrArray, size);

    string strArray[]{ "one", "two", "three", "four", "five" };
    size = sizeof(strArray) / sizeof(string);
    cout << "Original str Array : ";
    display<string>(strArray, size);
    sort<string>(strArray, size);
    cout << "Sorted   str Array : ";
    display<string>(strArray, size);

    _getch();
    return 0;
}
