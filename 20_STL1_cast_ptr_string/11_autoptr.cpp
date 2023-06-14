// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <class X>
class Std::auto_ptr
{
	X *ptr;

  public:
	//конструктор и деструктор
	explicit auto_ptr(X *p = 0) throw()
	{
		ptr = p;
	}
	~auto_ptr() throw()
	{
		delete ptr;
	}
	//оператор разыменования позволяет получить объект
	X &operator*() const throw()
	{
		return *ptr;
	}
	//оператор -> позволяет получить указатель
	X *operator->() const throw()
	{
		return ptr;
	}
};
class TEMP
{
  public:
	TEMP()
	{
		cout << "TEMP\n\n";
	}
	~TEMP()
	{
		cout << "~TEMP\n\n";
	}
	void TEST()
	{
		cout << "TEST\n\n";
	}
};
void main()
{
	//создаём два автоматических указателя
	//под один из них выделяем память типа TEMP
	auto_ptr<TEMP> ptr1(new TEMP), ptr2;
	//передача права владения
	ptr2 = ptr1;
	//вызов функции через автоматический указатель
	ptr2->TEST();
	//присваивание автоматического указателя
	//обычному указателю на объект класса
	TEMP *ptr = ptr2.get();
	//вызов функции через обычный указатель
	ptr->TEST();
}

int main()
// int main(int argc, char *argv[])
{
	f1();
	f2();

	return 0;
}
