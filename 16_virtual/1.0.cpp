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
};

void Test() 
{
	{
		Parent* par = new Parent();
		par->Foo(); // Parent::Foo

		Child* ch = new Child();
		ch->Foo();  // Child::Foo
		
		ch->Parent::Foo(); // Parent::Foo
	}
	{
		Parent* par = new Child();
		par->Foo(); // Parent::Foo
	}
}

int main ()
{
	Test();

	return 0;
}
