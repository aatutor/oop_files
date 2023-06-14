#include <stdio.h>

int commonY = 3;

class Point {
	int x_;
public:
	Point (): x_(0) {}
	Point (int x): x_(x) {}
	void Print() {
        printf("(%d, %d)\n", x_, commonY);
	}
};


int main ()
{
	Point p1;
	Point p2(1);

	p1.Print();
	p2.Print();

	commonY = 4;

	p1.Print();
	p2.Print();

    return 0;
}
