#include <stdio.h>

class Point {
public:
	int x_;
	int y_;

	Point Add(Point p) {
		Point res{ x_ + p.x_, y_ + p.y_ };
		return res;
	}
	void Print() {
		printf("(%d,%d)\n", x_, y_);
	}
};

int main ()
{
	Point p1{1,2}, p2{3, 4};
	Point p3 = p1.Add(p2);

    return 0;
}
