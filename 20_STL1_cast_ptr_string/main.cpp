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
		A* ptrA = new A;
		ptrA->Test();
		B* ptrB = reinterpret_cast<B*>(ptrA);
		ptrB->Test();
	}
	return 0;
}
