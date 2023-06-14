#include <stdio.h>

class Point {
	int* x_;
public:
	Point(int x){
		x_ = new int{x};
	}
	~Point() { delete x_; }
	void Print() {
		printf("%d\n", *x_);
	}
	void SetX(int x) { *x_ = x; }
};

int main ()
{
	{
		int x1 = 5;
		int x2 = x1;
	}
	{
		int x1(5);
		int x2(x1);
	}
	{
		Point p1(5);
		Point p2(p1);

		p2.Print();
		p1.SetX(6);
		p2.Print();

		Point* pp1 = new Point(5);
		Point* pp2 = new Point(*pp1);

		pp2->Print();

		delete pp1;

		pp2->Print();
		delete pp2;
	}
 
    return 0;
}
