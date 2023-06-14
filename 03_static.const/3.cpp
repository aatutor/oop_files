#include <stdio.h>

class Point {
	int x_;
public:
	Point(int x): x_(x) {}
	int GetX() { return x_; }
};

int main () {
	const Point POINT(1);
	printf("%d\n", POINT.GetX()); // нельзя вызвать метод

    return 0;
}
