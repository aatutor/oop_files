#include <iostream>
#include <string.h>
using namespace std;

void Test1()
{
	struct A {
		int x_ = 3;
	protected:
		A() {}
		A(A& a) = default; // copy ctor
		A(A&& a) = default; // move ctor
	};
	struct B : public A {
		int y_ = 4;
	public:
		B(): A() {}
	};

	{
		B b;
		cout << b.x_ << " " << b.y_ << endl << endl;

		// A a; // error: 'Test()::A::A()' is protected
		// cout << a.x_ << endl;
	}
	{
		// B b;
		// A a = b; // A(A& a) - copy
		// cout << a.x_ << endl;
	}
	{
		// A a = B(); // A(A&& a) - move
		// cout << a.x_ << endl;
	}
	{
		// B b;
		// B b2 = b;
		// cout << a.x_ << endl;
	}
	struct C: public A
	{
		// A* GetObj() {
		// 	A* t = new A();
		// 	return t;
		
		// 	A* p = new A(*this);
		//	return p;
		// }
		A* GetThis() {
			return (A*)this;
		}
	};
	{
		A* a = C().GetThis();
		cout << a->x_ << endl;
	}
	{
		A* a = new C();
		cout << a->x_ << endl;
	}
}

int main ()
{
	Test1();

    return 0;
}
