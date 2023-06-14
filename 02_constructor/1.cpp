// Вычислить среднюю оценку студента
#include <iostream>
#include <math.h>
using namespace std;

struct Point {
private: 
    int x_;
    int y_;
public: 
    Point() {
		x_ = 0;
		y_ = 0;
		cout << "Object created\n";
	}
	~Point() {
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