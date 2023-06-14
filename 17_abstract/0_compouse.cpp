#include <iostream>
#include <string.h>
using namespace std;

class B {
private:
	struct A {
		int x_;
	};
public:
	A a;
	int y_;
};

void Test1()
{
	{
		B::A dim1{1}; // error: 'struct B::A' is private
		cout << dim1.x_ << endl;
	}
	{
		B dim2{2, 3};
		cout << dim2.a.x_ << " " << dim2.y_ << endl << endl;
	}

}

int main ()
{
	Test1();

    return 0;
}
