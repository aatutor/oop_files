#include <stdio.h>
#include <vector>

class Array {
	char* str_;
public:
	Array(const char* s): str_(s) {}
	~Array() { delete[] str_; }
	Array(Array&);
	Array(Array&&);
	// getter ?
	// setter ?
}
class 


int main ()
{
	{
		int x = 1;
		int&& y = std::move(x);

		x = 5;
		printf("%d\n", y);

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
