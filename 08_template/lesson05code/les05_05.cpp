//les05_05

#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

template<class T>
struct Point
{
    T x;
    T y;
    void display()
    {
        cout << "(" << x << "," << y << ")";
    }
};

template<class T>
struct Array
{
    vector<T> data;
    void Add(T item)
    {
        data.push_back(item);
    }
    void display()
    {
        for(auto var:data)
        cout << var << " ";
    }
};

template<template<class> class T, class T1>
struct Some
{
    T<T1> data; // создается переменная data, 
                // типом которой будет шаблон класса T,
                // принимающий параметр-тип T1
    void Add(T1 item)
    {
        data.Add(item);
    }
    void display()
    {
        data.display();
        cout << endl;
    }
};

int main()
{
    // структура Point с целыми x,y
    Some<Point, int> intPoint;          
    intPoint.data.x = 1;
    intPoint.data.y = 2;
    cout << "Some: struct Point with int  x, y  : ";
    intPoint.display();

    // структура Point с плавающими x,y
    Some<Point, double> doublePoint;
    doublePoint.data.x = 10.01;
    doublePoint.data.y = 0.02;
    cout << "Some: struct Point with double x,y : ";
    doublePoint.display();

    // массив (вектор) целых
    Some<Array, int> intArray;
    intArray.Add(1);
    intArray.Add(3);
    intArray.Add(5);
    cout << "Some: array (vector) with int items: ";
    intArray.display();

    _getch();
    return 0;
}
