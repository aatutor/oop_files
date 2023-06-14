#include <iostream>
using namespace std;

namespace MySpace {
	int x = 5;

	void foo() {
		cout << x << endl;
	}

	class A {

	};
}
namespace {
	int y;
}

int main()
{
	MySpace::A a;
	cout << MySpace::x << endl;
	MySpace::foo();

	using MySpace::foo;

	foo();
	int y;

	::y = 5;
	y = 6;

	return 0;
}
