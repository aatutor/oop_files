// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//базовый класс
class A
{
public:
	//виртуальная функция для
	//последующего переопределения в потомке
	virtual void Test()
	{
		cout << "Test A\n\n";
	}
};
//класс-потомок
class B : public A
{
public:
	//переопределение виртуальной функции
	void Test() override
	{
		cout << "Test B\n\n";
	}
};

int main()
{
	{
		A* ptrB = new A;
		ptrB->Test();
		B* ptrD = reinterpret_cast<B*>(ptrB);
		ptrD->Test();
	}
	{
		int x = 5;
		unsigned int y = reinterpret_cast<unsigned int>(x);
	}
	return 0;
}
