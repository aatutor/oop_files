// Вычислить среднюю оценку студента
#include <iostream>
#include <math.h>
using namespace std;

struct Point {

	private: int x_;
	private: int y_;
	public: double Print() {
		cout <<"("<< x_ <<","<< y_ <<")";
	}
	public: void initPoint(int x, int y) {
		x_ = x;
		y_ = y;
	}
};

int main()
{
	// Point point{3, 4}; // нельзя задать
	
	Point point;
	point.initPoint(3, 4);// задать только так
    //cout <<"("<< point.x_ <<","<< point.y_ <<")";// нет доступа к полям
	point.Print();

	return 0;
}