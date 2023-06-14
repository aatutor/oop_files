#include <iostream>
using namespace std;

class A {
public:
	virtual void Foo() = 0;
};

class B : public A {
public:
	void Foo() override {
		cout << "B::Foo()\n";
	}
};

class C : public A {
public:
	virtual void Foo() override {
		cout << "C::Foo()\n";
	}
};



int main() 
{
	{
		// A a; // error: cannot declare variable 'a' to be of abstract type 'A'
	}
	{
		A* pa = new B();
		pa->Foo();
	}
	{
		A* pa = new C();
		pa->Foo();
	}

	return 0;
}