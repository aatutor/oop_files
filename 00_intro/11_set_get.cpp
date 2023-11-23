#include <iostream>

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
    using namespace std;
    
    // Point point{3, 4}; // нельзя задать private полям

    Point point;

    // сеттеры
    point.SetX(3);
    point.SetY(4);

                 // геттеры
    cout <<"("<< point.GetX() 
         <<","<< point.GetY() <<")"<< endl;

	return 0;
}