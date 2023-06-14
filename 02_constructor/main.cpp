// Вычислить среднюю оценку студента
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

struct Point {
private: 
	int x_;
	int y_;
	char* name_;
public: 
	Point(): x_(0), y_(0) {
		name_ = new char[50]{"noname"};
		cout << "Object created\n";
	}
    // Point() {
	// 	x_ = 0;
	// 	y_ = 0;
	// 	cout << "Object created\n";
	// }
	Point(int xy): Point(xy, xy) {}
	Point(int x, int y): x_(x), y_(y) {
		cout << "Object created\n";
	}
	Point(int x, int y, const char* name): Point(x, y) {
		name_ = new char[strlen(name)];
		strcpy(name_, name);
	}
	Point(int x, int y, const char* name = new char[50]{"noname"}): Point(x, y) {
		name_ = new char[strlen(name)];
		strcpy(name_, name);
	}

	~Point() {
		delete name_;
		cout << "Object deleted\n";
	}
};

int main()
{
    Point* point;
	point = new Point();// Object created
	delete point;		// Object deleted

	return 0;
}