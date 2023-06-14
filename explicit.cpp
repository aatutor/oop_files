#include <iostream>
using namespace std;

class Point {
	int x_;
public:
	Point(int x): x_(x) {}
};
class PointEx {
	int x_;
public:
	explicit PointEx(int x): x_(x) {}
};

void Foo (Point p) {}
void FooEx (PointEx p) {}

int main ()
{
	Point p1 = 1;
	Foo(1);

	//PointEx p2 = 2;
	//FooEx(2);

	PointEx p2 = PointEx(2);
	FooEx(PointEx(2));

    return 0;
}
