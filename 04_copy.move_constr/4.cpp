#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

class Point {
	int* x_;
public:
	Point(int x){
		printf("Point(int)\n");
		x_ = new int(x);
	}
	Point(Point& p) {
		printf("Point&\n");
		x_ = new int( *(p.x_) );
	}
	Point(Point&& p) {
		printf("Point&&\n");
		x_ = new int( *(p.x_) );
		delete p.x_;
		p.x_ = nullptr;
	}
	Point& operator= (Point& p){
		printf(" = &\n");
		x_ = new int( *(p.x_) );
		return *this;
	}
	Point& operator= (Point&& p){
		printf(" = &&\n");
		x_ = new int( *(p.x_) );
		return *this;
	}
	~Point() { delete x_; }
	void SetX(int x) { *x_ = x; }
	void Print() {
		printf("%d\n", *x_);
	}
	Point Inc() { 
		*x_ *= 2;
		return *this; 
	}
};

Point PointFactory(int x) {
	Point p1(x), p2(x);
	if (1)
		return p1;
	else
		return p2;
}

int main ()
{
	#if 0
	{
		Point p1( Point(10).Inc() );
		p1.Print();
	}
	#endif
	#if 1
	{
		// Point p1{std::move(Point(5))};
		Point p1 ( PointFactory(5) );
		p1.Print();
	}
	#endif
	#if 0
	{
		std::vector<Point> v;
		v.push_back(Point(10, 20));
	}
	#endif

	#if 0
	{
		Point p2(new Point(6));
		p2.Print();

		Point* p3 = new Point(new Point(7));
		p3->Print();
		delete p3;
	}
	#endif
 
    return 0;
}
