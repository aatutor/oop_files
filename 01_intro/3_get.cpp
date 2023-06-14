// Вычислить среднюю оценку студента
#include <iostream>
#include <math.h>
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
};

int main()
{
    // Point point{3, 4}; // нельзя задать private полям
    Point point;
    point.SetX(3);
    point.SetY(4);
    cout <<"("<< point.GetX() <<","<< point.GetY() <<")"<< endl;

	return 0;
}