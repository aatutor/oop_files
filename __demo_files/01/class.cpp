#include <iostream>
#include <math.h>

class CPoint {
private:
	int x_, y_;
public:
	void Init(/*CPoint* this, */int x, int y){
		this->x_ = x;
		this->y_ = y;
	}
	void Print() 
	{
		std::cout <<"("<< this->x_ <<","<< this->y_ <<")\n";
	}
	CPoint Sum(CPoint point2) 
	{
		// v1
		CPoint result;
		result.x_ = this->x_ + point2.x_;
		result.y_ = this->y_ + point2.y_;
		return result;

		// v2
		// int* res = new int[2]{ point1[0] + point2[0], point1[1] + point2[1] }; 
		// return res;

		// v3
		// return new int[2]{ point1[0] + point2[0], point1[1] + point2[1] }; 
	}
	double Length()
	{
		double x2 = this->x_ * this->x_;
		double y2 = this->y_ * this->y_;
		
		double result = sqrt(x2 + y2);
		return result;
	}
};

void Test() 
{
	using namespace std;
	{
		CPoint point;
		point.Init(1, 2);
		point.Print();
	}
	{
		CPoint point1;
		point1.Init(1, 2);
		CPoint point2;
		point2.Init(3, 5);
		CPoint resultPoint = point1.Sum(point2);
		resultPoint.Print();
	}
	{
		CPoint arrPoint;
		arrPoint.Init(3, 4);
		arrPoint.Print();
		cout <<"Len = "<< arrPoint.Length() << endl;
	}
}

int main ()
{
	Test();
	// Menu();
	
    return 0;
}
