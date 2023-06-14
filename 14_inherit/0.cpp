#include <iostream>
using namespace std;

void Test1()
{
	class A {
	public:
		int x_;
	};
	class B {
	public:
		A a_;
		int y_;
	};
	{
		A dim1{1};
		B dim2{2, 3};

		cout << dim1.x_ << endl;
		cout << dim2.a_.x_ << " " << dim2.y_ << endl << endl;
	}
}

void Test2() 
{
	class A {
		int x_;
	public:
		A(int x): x_(x) {}
		int GetX() {
			return x_;
		}
	};
	class B {
		A a_;
		int y_;
	public:
		B(int x, int y): y_(y), a_(x) {}
		int GetX() {
			return a_.GetX();
		}
		int GetY() {
			return y_;
		}
	};
	
	A dim1{5};
	B dim2{10, 15};

	cout << dim1.GetX() << endl;
	cout << dim2.GetX() << " " << dim2.GetY() << endl;
}

int main ()
{
	Test1();
	Test2();

	return 0;
}
