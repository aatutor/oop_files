#include <iostream>
using namespace std;

struct Point {

	private: int x_;
	private: int y_;
	public: double Print() {
		cout <<"("<< x_ <<","<< y_ <<")";
	}
	public: void InitPoint(int x, int y) {
		x_ = x;
		y_ = y;
	}
};

int main()
{
	// Point point{3, 4}; // нельзя задать private полям
	
	Point point;
	point.InitPoint(3, 4);// задать только public методом
	
    //cout <<"("<< point.x_ <<","<< point.y_ <<")";// нет доступа к полям
	point.Print();

	return 0;
}