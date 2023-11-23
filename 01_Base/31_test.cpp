// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Point {
private: 
    int x_;
    int y_;
public: 
    int GetX() {
        return x_;
    }
    int GetY() {
        return y_;
    }
    void SetX(int x) {
        x_ = x;
    }
    void SetY(int y) {
        y_ = y;
    }
	double Print() {
		cout <<"("<< x_ <<","<< y_ <<")";
	}
	void InitPoint(int x, int y) {
		x_ = x;
		y_ = y;
	}
};
};

void Test()
{
	{
		Point p;
		p.Print();
	}
	{
		Point p;
		p.SetX(1);
		p.SetY(2);

		cout <<"("<< point.GetX() 
			<<","<< point.GetY() <<")"<< endl;
	}
	{
		Point p;
		p.Init(1, 2);
		p.Print();
	}
	{
		Point p;
		p.SetX(1);
		p.SetY(2);

		p.Init(-3, -4);
		p.Print();
	}
}

int main ()
{
	Test();

	return 0;
}
