#include <stdio.h>

class Point;

class Triangle {
	Point* points;
public:
	// ...
	void Print();
};

class Point {
	int x_;
	int y_;
public:
	Point(int x, int y): x_(x), y_(y) {}
	friend void Triangle::Print();
};
void Triangle::Print() {
	printf("{A(%d, %d) B(%d, %d) C(%d, %d)}\n",
		points[0].x_, points[0].y_,
		points[1].x_, points[1].y_,
		points[2].x_, points[2].y_
	);
}

int main () {

    return 0;
}
