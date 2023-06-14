#include <stdio.h>

class Point {
public:
	int x_;
	int y_;

	Point operator+ (Point p){
		Point res{ x_ + p.x_, y_ + p.y_ };
		return res;
	}
	void Print() {
		printf("(%d,%d)\n", x_, y_);
	}
};

// Point operator+ (Point p1, Point p2){
// 	return Point{ p1.x_+p2.x_, p1.y_+p2.y_ };
// }

int main ()
{
	Point p1{1,2}, p2{3, 4};
	Point p3 = p1 + p2 + p1;
	p3.Print();

	p3 = p1.operator+ (p2);
	p3.Print();

	return 0;
}
