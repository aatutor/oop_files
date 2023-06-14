#include <iostream>
#include <string>
using namespace std;

class Parent {
public:
	virtual void Foo() {
		cout << "Parent::Foo\n";
	}
};
class Child : public Parent {};

void Test() 
{
	{
		Parent* par = new Parent();
		Parent* ch = new Child();
		
		par->Foo(); // Parent::Foo
		ch->Foo();  // Parent::Foo
	}
}

int main ()
{
	Test();

	return 0;
}
