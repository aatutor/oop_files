#include <stdio.h>
#include <vector>

class Point {
	int* x_;
public:
	Point(int x){
		printf("Point(int)\n");
		x_ = new int(x);
	}
	Point(Point&& p) {
		printf("Point&&\n");
		x_ = new int( *(p.x_) );
		delete p.x_;
		p.x_ = nullptr;
	}
	~Point() { delete x_; }
	void SetX(int x) { *x_ = x; }
	void Print() {
		printf("%d\n", *x_);
	}
};

int main ()
{
	{
		Point p1(std::move(Point(5)));
		p1.Print();

		std::vector<Point> v;
		v.push_back(Point(10));

		// Point p2(new Point(6));
		// p2.Print();

		// Point* p3 = new Point(new Point(7));
		// p3->Print();
		// delete p3;
	}
 
    return 0;
}
