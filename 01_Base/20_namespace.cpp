#include <iostream>
#include <stdio.h>
using namespace std;

namespace MySpace {
	int x = 5;

	void foo() {
		++x;
	}

	class A {};
}
namespace {
	int y;
}
namespace MySpace {
	A* pa = nullptr;
}

namespace One 
{
	int var = 1;
}
namespace Two
{
	char var = ',';
}
namespace 
{
	int var = 3;
}

int main()
{
	{
		printf("x: %d\n", MySpace::x);
		MySpace::foo();
		printf("x: %d\n", MySpace::x);
		
		MySpace::A a;
	}
	{
		using MySpace::foo;
		foo();

		using MySpace::A;
		A a;

		// printf("x: %d\n", x); // error: 'x' was not declared in this scope
	}
	{
		MySpace::pa = new MySpace::A();
	}
	{
		using namespace MySpace;

		foo();
		A a;
		printf("x: %d\n", x);
	}
	{
		{
			int y = 10;
			::y = 5;
		}
		// printf("y: %d\n", y); // error
		printf("y: %d\n", ::y);
	}
	{
		int var = 4;

		cout <<"vars: "	<< ::var 
						<< Two::var 
						<< One::var 
						<< var << endl;
	}

	return 0;
}
