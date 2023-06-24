// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <functional>
using namespace std;

// функция
bool isMultiple(int num, int div) 
{
	return num % div == 0;
}
// функтор
class More { 
	public: bool operator() (int a, int b) { return a > b; }
} isMore;
// лямбда
auto isEqual = [](int a, int b) { return a == b; }; 

// использование чего угодно
bool check(int x, int y, std::function<bool(int,int)> pred) // pred - предикат
{
	return pred(x, y);
}

int main ()
{
	cout << (check(10, 5, isMultiple) ? "yes":"no") << endl;

	cout << (check(10, 5, isMore) ? "yes":"no") << endl;

	cout << (check(10, 5, isEqual) ? "yes":"no") << endl;

	return 0;
}
