#include <iostream>
using namespace std;

void NonVirtualDtor() 
{
	struct A {
		~A() {
			cout << "~A\n";
		}
	};

	struct B : public A {
		~B() {
			cout << "~B\n";
		}
	};

	{
		{// v1
			A a;
		} // ~A
		{// v2
			A* pa = new A();
			delete pa; // ~A
		}
		// v3
		delete new A(); // ~A
	}
	{
		delete new B(); // ~B > ~A
	}
	cout << string(15, '-') << endl;
	{
		A* pa = new A();
		delete pa; // ~A

		A* pb = new B();
		delete pb; // ~A !!!
	}
}

void VirtualDtor() 
{
	struct A {
		virtual ~A() {
			cout << "~A\n";
		}
	};

	struct B : public A {
		~B() {
			cout << "~B\n";
		}
	};

	{
		delete new A(); // ~A

		delete new B(); // ~B > ~A
	}
	cout << string(15, '-') << endl;
	{
		A* pa = new A();
		delete pa; // ~A

		A* pb = new B();
		delete pb; // ~B > ~A
	}
}

struct A {
	virtual ~A() = 0;
};
A::~A() {
	cout << "~A() ";
}
struct B : public A {
	~B() {
		cout << "~B\n";
	}
};
void ClearVirtualDtor() 
{
	{
		delete new A(); // error: A is abstract

		delete new B(); // ~B > ~A
	}
	cout << string(15, '-') << endl;
	{
		A* pa = new A(); // error: A is abstract
		delete pa;

		A* pb = new B();
		delete pb; // ~B > ~A
	}
}

int main() 
{
	// NonVirtualDtor();
	VirtualDtor();

	return 0;
}