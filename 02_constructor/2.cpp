// Вычислить среднюю оценку студента
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

struct Point {
private: 
    int x_;
    int y_;
public: 
    // Point() {
	// 	x_ = 0;
	// 	y_ = 0;
	// 	cout << "Object created\n";
	// }
	Point(): Point(0, 0) {
		cout << "Object created\n";
	}
	Point(int xy): Point(xy, xy) {}
	Point(int x, int y): x_(x), y_(y) {
		cout << "Object created\n";
	}
};

int main()
{
    Point* point;
	point = new Point();// Object created
	delete point;		// Object deleted
	point = new Point(1);// Object created
	delete point;		// Object deleted
	point = new Point(3, 4);// Object created
	delete point;		// Object deleted

	return 0;
}