#include <iostream>
using namespace std;

class Point1d {
public:
	int x_;

	Point1d(int x): x_(x) {}
	void Print() {
		cout << x_ << endl;
	}
};
class Point2d : public Point1d {
public:
	int y_;

	Point2d(int x, int y): Point1d(x), y_(y) {}
	void Print() {
		cout << x_ <<" "<< y_ << endl;
	}
};

void AddX(Point1d* pt, int dx) {
	pt->x_ += dx;
}

int main ()
{
	{
		Point1d* p1 = new Point1d(3);
		AddX(p1, 5);
		p1->Print();
	}
	{
		Point2d* p2 = new Point2d(1, 2);
		AddX(p2, 10);
		p2->Print();
	}

	return 0;
}
