#include <stdio.h>
#include <cmath>

class Point {
public:
	int x_;
	int y_;

	void Print() {
		printf("(%d,%d)\n", x_, y_);
	}
	operator bool() {
		return (x_ == 0) && (y_ == 0);
	}
	operator double() {
		return sqrt(x_*x_ + y_*y_);
	}
};

int main ()
{
	Point p1{3, 4}, p2{0, 0};
	bool b = p1;
	printf("%d\n", b);
	printf("%d\n", (bool)p2);

	double d = p1;
	printf("%.2f\n", d);
	printf("%.2f\n", (double)p2);

	return 0;
}
