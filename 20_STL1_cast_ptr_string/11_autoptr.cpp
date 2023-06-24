// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
using namespace std;

template <class X>
class my_auto_ptr
{
	X *ptr;
public: //конструктор и деструктор
	explicit my_auto_ptr(X *p = nullptr) throw() {
		ptr = p;
	}
	~my_auto_ptr() throw() {
		delete ptr;
	}
	//оператор разыменования позволяет получить объект
	X& operator*() const throw() {
		return *ptr;
	}
	//оператор -> позволяет получить указатель
	X* operator->() const throw() {
		return ptr;
	}
};
struct Temp
{
	Temp() { cout << "Temp\n\n"; }
	~Temp(){ cout << "~Temp\n\n"; }
	void Test() { cout << "Test\n\n"; }
};

int main()
{
	{
		int *x = new int(5);
		int *y = x;

		delete x;
		// delete y; // not success
	}
	{
 		//создаём два автоматических указателя
		//под один из них выделяем память типа Temp
		std::auto_ptr<Temp> ptr1(new Temp), ptr2;
		// my_auto_ptr<Temp> ptr1(new Temp), ptr2;
		
		ptr2 = ptr1; //передача права владения

		ptr2->Test(); //вызов функции через автоматический указатель
		
		//присваивание автоматического указателя
		//обычному указателю на объект класса
		Temp *ptr = &*ptr2;
		ptr->Test(); //вызов функции через обычный указатель
	}
	cout << "Success\n";
	return 0;
}
