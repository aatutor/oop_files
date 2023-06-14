#include <iostream>
using namespace std;

class Parent {
public:
	void Foo() {
		cout << "Parent::Foo\n";
	}
};
class Child : public Parent {
public:
	void Foo() {
		cout << "Child::Foo\n";
	}
	void Bar() {
		cout << "Child::Bar\n";
	}
};

void Test() 
{
	{
		Parent* p = new Parent();
		p->Foo();

		Child* c = new Child();
		c->Foo();
		c->Bar();
	}
	{
		Parent* ptr = new Child();
		ptr->Foo();
		// ptr->Bar(); // fail: not exists Parent::Bar();
	}
	{
		Child ch;
		Parent par = (Parent)ch;
		par.Foo();
		// par.Bar(); // fail
		// Child ch2 = (Child)par; // fail: not exists Child::Child(Parent&)
	}
}

int main ()
{
	Test();

	return 0;
}
