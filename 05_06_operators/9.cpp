#include <iostream>
using namespace std;

class Point {
public:
	int x_;
	int y_;

	// void Print() {
	// 	printf("(%d,%d)\n", x_, y_);
	// }
	friend ostream& operator<< (ostream& out, const Point& p) {
		out <<"("<< p.x_ <<","<< p.y_ <<")";
		return out;
	}
	friend istream& operator>> (istream& in, Point& p) {
		in >> p.x_;
		in.ignore(1);
		in >> p.y_;
		return in;
	}
};

int main ()
{
	Point p1;
	cin >> p1;
	cout << p1 << endl;

	return 0;
}
