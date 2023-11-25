#include <stdio.h>

class Point {
	int x_;
	int y_;
public:
	Point(int x, int y): x_(x), y_(y) {}
	friend void Print(Point);
};
void Print(Point p) {
	printf("(%d, %d)\n", p.x_, p.y_);
}

int main () {
	Point point(3, 4);
	Print(point);

    return 0;
}
