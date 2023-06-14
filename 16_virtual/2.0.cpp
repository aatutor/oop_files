#include <iostream>
#include <string>
using namespace std;

class Parent {
public:
	virtual void Foo() {
		cout << "Parent::Foo\n";
	}
};
class Child : public Parent {
public:
	virtual void Foo() {
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
	cout << string(15,'-') << endl;
	{
		Parent* par = new Child();
		par->Foo(); // Child::Foo

		Child* ch = new Child();
		ch->Foo();  // Child::Foo
		
		ch->Parent::Foo(); // Parent::Foo
		par->Parent::Foo(); // Parent::Foo
	}
}

int main ()
{
	Test();

	return 0;
}
