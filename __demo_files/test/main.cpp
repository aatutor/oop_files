#include <iostream>
using namespace std;

class Point {
	int x_;
public:
	static int commonX;
	Point (int x): x_(x) {}
	Point (): x_(commonX) {}
};

int Point::commonX = 3;

int main ()
{
	cout << Point::commonX << endl;

    return 0;
}
