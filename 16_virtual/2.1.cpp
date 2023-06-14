#include <iostream>
#include <string>
using namespace std;

class Parent {
public:
	virtual void Foo(int x) {
		cout << "Parent::Foo\n";
	}
};
class Child : public Parent {
public:
	virtual void Foo(long x) override {
		cout << "Child::Foo\n";
	}
};

void Test() 
{
	{
		Parent* par = new Parent();
		par->Foo(5); // Parent::Foo

		Child* ch = new Child();
		ch->Foo(5);  // Child::Foo
	}
	cout << string(15,'-') << endl;
	{
		Parent* par = new Child();
		par->Foo(5L); // Parent::Foo

		Child* ch = new Child();
		ch->Foo(5L);  // Child::Foo
	}
}

int main ()
{
	Test();

	return 0;
}
