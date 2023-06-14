#include <iostream>
using namespace std;

struct A {
	int x_ = 3;

	string type_;
	A(){
		type_ += "A()";
	}
	A(A& a) {
		type_ += "A(&)";
	}
};
struct B : virtual public A {
	int y_ = 4;

	B(){
		type_ += "B() ";
	}
	B(B& b):A(b){
		type_ += "B(&)";
	}
};

A* copy(A* a) {
	return new A(*a);
}

int main() 
{
	{
		A a;
		cout << a.type_ << endl;
		A* pa = copy(&a);
		cout << pa->type_ << endl;
		
		B b;
		cout << b.type_ << endl;
		A* pb = copy(&b);
		cout << pb->type_ << endl;
	}
	{

	}

	return 0;
}