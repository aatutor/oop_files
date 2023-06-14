#include <stdio.h>

class Point {
public:
	int x_;
	int y_;

	Point& operator++ (){
		++x_;
		++y_;
		return *this;
	}
	Point& operator-- (){
		--x_;
		--y_;
		return *this;
	}
	Point operator++ (int) {
		Point before(*this);
		++x_;
		++y_;
		return before;
	}
	void Print() {
		printf("(%d,%d)\n", x_, y_);
	}
};

int main ()
{
	Point p1{1,2}, p2{3, 4};
	++p1;
	p1.Print();
	--p2;
	p2.Print();

	return 0;
}
