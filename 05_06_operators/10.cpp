#include <iostream>
using namespace std;

class Point {
	int* x_;
	int* y_;
public:
	Point(int x, int y): x_(new int(x)), y_(new int(y)) {}

	Point(const Point& from) {
		printf("copy\n");
		x_ = new int{*(from.x_)};
		y_ = new int{*(from.y_)};
	}
	Point& operator= (const Point& from) {
		printf("copy=\n");
		*x_ = *(from.x_);
		*y_ = *(from.y_);
		return *this;
	}

	Point(Point&& from) {
		printf("move\n");
		swap(x_, from.x_);
		swap(y_, from.y_);
	}
	Point& operator= (Point&& from) {
		printf("move=\n");
		swap(x_, from.x_);
		swap(y_, from.y_);
		return *this;
	}

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
