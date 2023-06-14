#include <iostream>
using namespace std;

class Point {
	int* x_;
	int* y_;
public:
	Point() = default;
	Point(int x, int y): x_(new int(x)), y_(new int(y)) {}

	Point(const Point& from) = delete;
	Point(Point&& from) = delete;

	void Print() {
		printf("(%d,%d)\n", *x_, *y_);
	}
};

int main ()
{
	Point p1{1,2}, p2{3, 4};
	Point p3 = p1;
	p3 = p2;
	p3 = Point(4, 5);
	p3.Print();
	Point p4( move( Point(7, 8) ) );

	return 0;
}
