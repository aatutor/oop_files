// https://metanit.com/cpp/tutorial/4.8.php
// https://metanit.com/cpp/tutorial/4.9.php

// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }

int operation(int(*)(int, int), int, int);  // первый параметр - указатель на функцию

int main()
{
    int a{10};
    int b{6};

    int result = operation(add, a, b);
    std::cout << "result: " << result << std::endl;

    result = operation(sub, a, b);
    std::cout << "result: " << result << std::endl;
}

int operation(int (*op) (int, int), int a, int b)
{
    return op(a, b);
}

int add(int x, int y)
{
    return x + y;
}
int subtract(int x, int y)
{
    return x - y;
}
