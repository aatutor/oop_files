#include <stdio.h>

class Point {
public:
	int x_;
	int y_;

	void Print() {
		printf("(%d,%d)\n", x_, y_);
	}
};

Point operator+ (Point p1, Point p2){
	Point res{ p1.x_ + p2.x_, p1.y_ + p2.y_ };
	return res;
}

int main ()
{
	Point p1{1,2}, p2{3, 4};
	Point p3 = p1 + p2;
	p3.Print();

	Point p4 = operator+ (p1, p2);
	p4.Print();

	return 0;	
}
