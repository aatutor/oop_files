#include <iostream>
#include <math.h>

struct SPoint {
public:
	int x, y;
};
// class CPoint {
// private:
// }

double Length(SPoint point)
{
	double x2 = point.x * point.x;
	double y2 = point.y * point.y;
	
	double result = sqrt(x2 + y2);
	return result;
}

SPoint Sum(SPoint point1, SPoint point2) 
{
	// v1
	SPoint result;
	result.x = point1.x + point2.x;
	result.y = point1.y + point2.y;
	return result;

	// v2
	// int* res = new int[2]{ point1[0] + point2[0], point1[1] + point2[1] }; 
	// return res;

	// v3
	// return new int[2]{ point1[0] + point2[0], point1[1] + point2[1] }; 
}

void Print(SPoint point) 
{
	std::cout <<"("<< point.x <<","<< point.y <<")\n";
}

void Test() 
{
	using namespace std;
	{
		SPoint sPoint{3, 4};
		Print(sPoint);
	}
	{
		SPoint point1{1, 2};
		SPoint point2{3, 5};
		SPoint resultPoint = Sum(point1, point2);
		Print(resultPoint);
	}
	{
		SPoint arrPoint{3, 4};
		Print(arrPoint);
		cout <<"Len = "<< Length(arrPoint) << endl;
	}
}

int main ()
{
	Test();
	//Menu();
	
    return 0;
}
