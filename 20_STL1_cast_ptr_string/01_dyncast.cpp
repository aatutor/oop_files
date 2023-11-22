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
// int main(int argc, char *argv[])
{
	//указатель на класс-родитель
	//объект класса-родителя
	A *ptr_a, obj_a;

	//указатель на класс-потомок
	//и объект класса-потомка
	B *ptr_b, obj_b;

	//приводим адрес объекта (B*) к указателю типа B*
	ptr_b = dynamic_cast<B*>(&obj_b);

	//если все прошло успешно - вернулся !0
	//произошло приведение
	if (ptr_b)
	{
		cout << "Good work - ";
		ptr_b->Test();
	}
	else //если произошла ошибка - вернулся nullptr
		cout << "Error work!!!\n\n";

	ptr_a = dynamic_cast<A*>(&obj_a);
	if (ptr_a)
	{
		cout << "Good work - ";
		ptr_a->Test();
	}
	else
		cout << "Error work!!!\n\n";

	ptr_a = dynamic_cast<A*>(&obj_b);
	if (ptr_a)
	{
		cout << "Good work - ";
		ptr_a->Test();
	}
	else
		cout << "Error work!!!\n\n";
	
	//ВНИМАНИЕ!!! ЭТО НЕВОЗМОЖНО
	ptr_b = dynamic_cast<B*>(&obj_a); // warning: dynamic_cast of 'A obj_a' to 'class B*' can never succeed
	
	if (ptr_b)
		cout << "Good work - ";
	else
		cout << "Error work!!!\n\n";
		
	return 0;
}
