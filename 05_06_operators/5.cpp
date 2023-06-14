#include <stdio.h>

class Point {
public:
	int x_;
	int y_;

	Point operator- (){
		printf(":op-:\n");
		Point res{-x_, y_};
		return res;
	}
	void Print() {
		printf("(%d,%d)\n", x_, y_);
	}
};

int main ()
{
	Point p1{1,2}, p2{3, 4};
	Point p3 = p1 + p2;
	p3.Print();

	p3 = p1.operator+ (p2);
	p3.Print();

	return 0;
}
