#include <iostream>
using namespace std;

template <class T>
class Point {
protected:
	T x_;
public:
	Point(T x): x_(x) {}

	void Print() {
		cout << x_ << endl;
	}
};
template <class T>
class Point2d : public Point<T> {
	T y_;
public:
	Point2d(T x, T y): Point<T>(x), y_(y) {}

	void Print() {
		cout << Point<T>::x_ <<" "<< y_ << endl;
	}
};

int main ()
{
	{
		Point<int> p1(1);
		p1.Print();
	}
	{
		Point2d<int> p2(2, 3);
		p2.Print();
	}

	return 0;
}
