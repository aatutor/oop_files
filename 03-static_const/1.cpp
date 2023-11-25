#include <stdio.h>

class Point {
	int x_;
public:
	static int commonY;
	Point (): x_(0) {}
	Point (int x): x_(x) {}
	void Print() {
        printf("(%d, %d)\n", x_, commonY);
	}
};

int Point::commonY = 3;

int main ()
{
	Point p1;
	Point p2(1);

	p1.Print();
	p2.Print();

	Point::commonY = 4;

	p1.Print();
	p2.Print();

	printf("%d\n", Point::commonY);

    return 0;
}
